/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_test_sigpipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:38 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 15:43:30 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

int	test_sigpipe(void)
{
	int		fds[2];
	pid_t	child_id;
	int		cicles;

	if (pipe(fds) == -1)
		return (FAILURE);
	child_id = fork();
	if (child_id == -1)
		return (FAILURE);
	if (child_id == 0)
	{
		close(fds[0]);
		close(fds[1]);
	}
	else
	{
		close(fds[0]);
		cicles = 0;
		while (cicles++ < 100)
		{
			usleep(100);
			write(fds[1], "X", 1);
		}
	}
	return (wait(NULL), FAILURE);
}
