/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:15:31 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 16:33:29 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"

int	test_null(void)
{
	char	buf[100];
	int		stdout_pipe;

	ft_bzero(buf, 100);
	stdout_pipe = capture_stdout_to_pipe();
	if (ft_printf("%d %x %p %s", NULL, NULL, NULL, NULL) != 16)
		return (FAILURE);
	if (read(stdout_pipe, buf, 100) < 0)
		return (FAILURE);
	close(stdout_pipe);
	if (ft_strncmp("0 0 (nil) (null)", buf, 17) != 0)
		return (FAILURE);
	return (SUCCESS);
}
