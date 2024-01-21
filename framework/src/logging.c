/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itohatweb <itohatweb@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:59:41 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 14:23:49 by itohatweb        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static char	*get_status_str(t_test_status status)
{
	if (status == STATUS_OK)
		return (GREEN "OK" DEF_COLOR);
	else if (status == STATUS_KO)
		return (RED "KO" DEF_COLOR);
	else if (status == STATUS_NOT_RUN)
		return (GRAY "SKIPPED" DEF_COLOR);
	else if (status == STATUS_NOT_RUN)
		return (GRAY "SKIPPED" DEF_COLOR);
	else if (status == STATUS_SIGSEGV)
		return (YELLOW "SIGSEGV" DEF_COLOR);
	else if (status == STATUS_SIGBUS)
		return (YELLOW "SIGBUS" DEF_COLOR);
	else if (status == STATUS_SIGABRT)
		return (YELLOW "SIGABRT" DEF_COLOR);
	else if (status == STATUS_SIGFPE)
		return (YELLOW "SIGFPE" DEF_COLOR);
	else if (status == STATUS_SIGPIPE)
		return (YELLOW "SIGPIPE" DEF_COLOR);
	else if (status == STATUS_SIGILL)
		return (YELLOW "SIGILL" DEF_COLOR);
	else if (status == STATUS_TIMEOUT)
		return (MAGENTA "TIMEOUT" DEF_COLOR);
	return (CYAN "UNKNOWN" DEF_COLOR);
}

void	log_test(char *launcher_name, t_unit_test *test,
			t_test_status status, int fd)
{
	ft_putstr_fd(launcher_name, fd);
	ft_putstr_fd(": ", fd);
	ft_putstr_fd(test->title, fd);
	ft_putstr_fd(": ", fd);
	ft_putstr_fd("[", fd);
	ft_putstr_fd(get_status_str(status), fd);
	ft_putstr_fd("]", fd);
	ft_putstr_fd("\n", fd);
}

void	log_summary(t_unit_test *tests, int passed, int fd)
{
	int	skipped;
	int	total;

	skipped = 0;
	total = 0;
	while (tests)
	{
		total++;
		if (tests->enabled == false)
			skipped++;
		tests = tests->next;
	}
	ft_putstr_fd("\nSummary: ", fd);
	if (passed != total - skipped)
		ft_putstr_fd(RED, fd);
	else
		ft_putstr_fd(GREEN, fd);
	ft_putnbr_fd(passed, fd);
	ft_putstr_fd(" / ", fd);
	ft_putnbr_fd(total - skipped, fd);
	ft_putstr_fd(DEF_COLOR " Passed", fd);
	ft_putstr_fd(GRAY " - ", fd);
	ft_putnbr_fd(skipped, fd);
	ft_putstr_fd(" Skipped" DEF_COLOR, fd);
	ft_putstr_fd("\n", fd);
}
