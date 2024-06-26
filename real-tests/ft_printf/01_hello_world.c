/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_hello_world.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:13:51 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 16:14:20 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	test_hello_world(void)
{
	int		stdout_pipe;
	char	buf[100];

	ft_bzero(buf, 100);
	stdout_pipe = capture_stdout_to_pipe();
	if (ft_printf("Hello World!\n") != 13)
		return (FAILURE);
	if (read(stdout_pipe, buf, 100) < 0)
		return (FAILURE);
	close(stdout_pipe);
	if (ft_strncmp("Hello World!\n", buf, 14) != 0)
		return (FAILURE);
	return (SUCCESS);
}
