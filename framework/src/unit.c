/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:23:23 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/20 19:34:39 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_unit_test	*test_create(char *title, int (*test_function)(void), bool enabled)
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

int	init_fds(int *file_fd, int *null_fd)
{
	*file_fd = open("test-log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*file_fd < 0)
		return (logfile_error(), -1);
	*null_fd = open("/dev/null", O_WRONLY);
	if (*null_fd < 0)
		return (devnull_error(), -1);
	return (0);
}

int	launch_tests(char *routine_name, t_unit_test **test_list)
{
	t_unit_test	*cur_test;
	int			file_fd;
	int			null_fd;
	int			status;
	int			successful_tests;

	if (init_fds(&file_fd, &null_fd) < 0)
		return (test_free(*test_list), -1);
	successful_tests = 0;
	cur_test = *test_list;
	while (cur_test)
	{
		if (cur_test->enabled)
			status = execute_test(*test_list, cur_test, file_fd, null_fd);
		else
			status = STATUS_NOT_RUN;
		if (status == STATUS_OK)
			successful_tests++;
		log_test(routine_name, cur_test, status, STDOUT_FILENO);
		log_test(routine_name, cur_test, status, file_fd);
		cur_test = cur_test->next;
	}
	log_summary(*test_list, successful_tests, STDOUT_FILENO);
	log_summary(*test_list, successful_tests, file_fd);
	return (close(null_fd), close(file_fd), test_free(*test_list), SUCCESS);
}
