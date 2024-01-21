/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:15:31 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 16:26:30 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	test_hex(void)
{
	char	buf[100];
	int		stdout_pipe;

	ft_bzero(buf, 100);
	stdout_pipe = capture_stdout_to_pipe();
	if (ft_printf("> %x < %x > %x %x %x",
			2147483647, -2147483648, 0, 10, -23) != 36)
		return (FAILURE);
	if (read(stdout_pipe, buf, 100) < 0)
		return (FAILURE);
	close(stdout_pipe);
	if (ft_strncmp("> 7fffffff < 80000000 > 0 a ffffffe9", buf, 37) != 0)
		return (FAILURE);
	return (SUCCESS);
}
