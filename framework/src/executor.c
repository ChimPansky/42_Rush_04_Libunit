/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:34:54 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/20 18:35:13 by tkasbari         ###   ########.fr       */
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
		else if (WTERMSIG(status) == SIGABRT)
			return (STATUS_SIGABRT);
		else if (WTERMSIG(status) == SIGFPE)
			return (STATUS_SIGFPE);
		else if (WTERMSIG(status) == SIGPIPE)
			return (STATUS_SIGPIPE);
		else if (WTERMSIG(status) == SIGILL)
			return (STATUS_SIGILL);
	}
	return (STATUS_UNKNOWN);
}

int	execute_test(t_unit_test *test)
{
	int		status;
	pid_t	pid;

	// TODO what to do if test->func is NULL?
	if (!test->test_function)
		return (STATUS_UNKNOWN);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		// TODO: Test whether this works. (Test TIMEOUT)
		alarm(TEST_TIMEOUT_SECS);
		status = test->test_function();
		if (status == 0)
			exit(STATUS_OK);
		else if (status == -1)
			exit(STATUS_KO);
		exit(STATUS_UNKNOWN);
	}
	wait(&status);
	return (get_test_status(status));
}
