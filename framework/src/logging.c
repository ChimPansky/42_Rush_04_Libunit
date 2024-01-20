/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:59:41 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/20 15:28:17 by sdabland         ###   ########.fr       */
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
