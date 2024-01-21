/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:23:23 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 18:31:18 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static t_unit_test	*test_create(char *title,
	int (*test_function)(void), bool enabled)
{
	t_unit_test	*new_test;

	new_test = ft_calloc(1, sizeof(t_unit_test));
	if (!new_test)
		return (NULL);
	new_test->title = title;
	new_test->test_function = test_function;
	new_test->enabled = enabled;
	return (new_test);
}

t_unit_test	*test_add(t_unit_test **tests,
	char *title, int (*test_function)(void), bool enabled)
{
	t_unit_test	*new_test;
	t_unit_test	*cur_test;

	new_test = test_create(title, test_function, enabled);
	if (!new_test)
		return (NULL);
	if (tests && !*tests)
		*tests = new_test;
	else
	{
		cur_test = *tests;
		while (cur_test->next)
			cur_test = cur_test->next;
		cur_test->next = new_test;
	}
	return (new_test);
}

void	test_free(t_unit_test *test)
{
	t_unit_test	*current;

	if (!test)
		return ;
	current = test;
	while (test)
	{
		current = test;
		test = test->next;
		free(current);
	}
}

static int	init_fds(int *file_fd, int *null_fd, bool trunc)
{
	if (trunc)
		*file_fd = open("test-log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		*file_fd = open("test-log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*file_fd < 0)
		return (logfile_error(), -1);
	*null_fd = open("/dev/null", O_WRONLY);
	if (*null_fd < 0)
		return (devnull_error(), -1);
	return (0);
}

int	launch_tests(char *routine_name, t_tester *tester, t_unit_test *test_list)
{
	t_unit_test	*cur_test;
	int			file_fd;
	int			null_fd;
	int			successful_tests;
	int			total_tests;

	tester->current_routine = routine_name;
	tester->routine_nr++;
	if ((tester->routine_nr == 1 && init_fds(&file_fd, &null_fd, true) < 0)
		|| (tester->routine_nr != 1 && init_fds(&file_fd, &null_fd, false) < 0))
		return (test_free(test_list), -1);
	successful_tests = 0;
	total_tests = 0;
	cur_test = test_list;
	successful_tests = execute_routine(tester->current_routine,
			test_list, file_fd, null_fd);
	total_tests = get_total_tests(test_list);
	log_summary(test_list, successful_tests, STDOUT_FILENO);
	log_summary(test_list, successful_tests, file_fd);
	close(null_fd);
	close(file_fd);
	test_free(test_list);
	if (total_tests != successful_tests)
		return (FAILURE);
	return (SUCCESS);
}
