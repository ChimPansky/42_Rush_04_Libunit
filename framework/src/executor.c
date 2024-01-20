/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:34:54 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/20 15:20:32 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	get_test_status(int status)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == STATUS_OK)
			return (STATUS_OK);
		else if (WEXITSTATUS(status) == STATUS_KO)
			return (STATUS_KO);
	}
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			return (STATUS_SIGSEGV);
		else if (WTERMSIG(status) == SIGBUS)
			return (STATUS_SIGBUS);
		else if (WTERMSIG(status) == SIGALRM)
			return (STATUS_TIMEOUT);
	}
	return (STATUS_UNKNOWN);
}

int	execute_test(t_unit_test *test)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		// TODO: Test whether this works. (Test TIMEOUT)
		alarm(TEST_TIMEOUT_SECS);
		// TODO what to do if test->func is NULL?
		if (!test->func)
			exit(STATUS_KO);
		status = test->func();
		if (status == 0)
			exit(STATUS_OK);
		else if (status == -1)
			exit(STATUS_KO);
		exit(STATUS_UNKNOWN);
	}
	wait(&status);
	return (get_test_status(status));
}
