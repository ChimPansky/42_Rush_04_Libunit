/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:23:00 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/20 19:23:13 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	logfile_error(void)
{
	ft_putendl_fd("Error: Failed to create logfile.", STDERR_FILENO);
}

void	devnull_error(void)
{
	ft_putendl_fd("Error: Failed to open /dev/null.", STDERR_FILENO);
}
