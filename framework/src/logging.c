/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:59:41 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/20 18:49:03 by tkasbari         ###   ########.fr       */
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

void	log_test(char *launcher_name, t_unit_test *test, t_test_status status)
{
	ft_putstr_fd(launcher_name, STDOUT_FILENO);
	ft_putstr_fd(": ", STDOUT_FILENO);
	ft_putstr_fd(test->title, STDOUT_FILENO);
	ft_putstr_fd(": ", STDOUT_FILENO);
	ft_putstr_fd("[", STDOUT_FILENO);
	ft_putstr_fd(get_status_str(status), STDOUT_FILENO);
	ft_putstr_fd("]", STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
