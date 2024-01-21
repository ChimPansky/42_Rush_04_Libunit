/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:34:54 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 17:51:36 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	get_test_status_signaled(int status)
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
	return (STATUS_UNKNOWN);
}

static int	get_test_status(int status)
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
		return (get_test_status_signaled(status));
	return (STATUS_UNKNOWN);
}

static void	child_exit(int status)
{
	if (status == SUCCESS)
		exit(STATUS_OK);
	else if (status == FAILURE)
		exit(STATUS_KO);
	exit(STATUS_UNKNOWN);
}

int	execute_test(t_unit_test *tests_head, t_unit_test *test,
				int file_fd, int null_fd)
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
		child_exit(status);
	}
	wait(&status);
	return (get_test_status(status));
}

int	execute_routine(char *routine_name,
	t_unit_test *test_list, int file_fd, int null_fd)
{
	t_unit_test	*cur_test;
	int			status;
	int			successful_tests;

	successful_tests = 0;
	cur_test = test_list;
	while (cur_test)
	{
		if (cur_test->enabled)
			status = execute_test(test_list, cur_test, file_fd, null_fd);
		else
			status = STATUS_NOT_RUN;

		log_test(routine_name, cur_test, status, STDOUT_FILENO);
		log_test(routine_name, cur_test, status, file_fd);
		if (status == STATUS_OK)
			successful_tests++;
		cur_test = cur_test->next;
	}
	return (successful_tests);
}
