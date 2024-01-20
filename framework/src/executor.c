/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:34:54 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/20 19:11:25 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <signal.h>
#include <stdlib.h>

int	get_test_status(int status)
{
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == STATUS_OK)
			return (STATUS_OK);
		else if (WEXITSTATUS(status) == STATUS_KO)
			return (STATUS_KO);
		else if (WEXITSTATUS(status) == STATUS_NOT_RUN)
			return (STATUS_NOT_RUN);
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

int	execute_test(t_unit_test *tests_head, t_unit_test *test, int file_fd, int null_fd)
{
	int		status;
	pid_t	pid;
	int		(*func)(void);

	func = test->test_function;
	if (!func)
		return (STATUS_UNKNOWN);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		test_free(tests_head);
		alarm(TEST_TIMEOUT_SECS);
		if (dup2(null_fd, STDOUT_FILENO) < 0)
			exit(STATUS_NOT_RUN);
		close(null_fd);
		close(file_fd);
		status = func();
		if (status == 0)
			exit(STATUS_OK);
		else if (status == -1)
			exit(STATUS_KO);
		exit(STATUS_UNKNOWN);
	}
	wait(&status);
	return (get_test_status(status));
}
