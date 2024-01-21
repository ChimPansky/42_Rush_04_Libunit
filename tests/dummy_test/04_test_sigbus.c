/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_test_sigbus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:55 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 18:52:54 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

int	test_sigbus(void)
{
	char	*dummy;
	int		x;
	int		i;

	x = 42;
	asm("pushf\n\torl $0x40000, (%rsp)\n\tpopf");
	dummy = (char *)&x;
	dummy++;
	i = *(int *)dummy;
	(void) i;
	return (SUCCESS);
}
