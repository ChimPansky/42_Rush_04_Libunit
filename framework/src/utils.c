/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:32:08 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 18:32:25 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	capture_stdout_to_pipe(void)
{
	int	stdout_pipe[2];

	if (pipe(stdout_pipe) == -1)
		return (-1);
	if (dup2(stdout_pipe[1], STDOUT_FILENO) == -1)
		return (close(stdout_pipe[0]), close(stdout_pipe[1]), -1);
	close(stdout_pipe[1]);
	return (stdout_pipe[0]);
}

int	get_total_tests(t_unit_test *test_list)
{
	int			count;
	t_unit_test	*cur_test;

	count = 0;
	cur_test = test_list;
	while (cur_test)
	{
		if (cur_test->enabled)
			count++;
		cur_test = cur_test->next;
	}
	return (count);
}
