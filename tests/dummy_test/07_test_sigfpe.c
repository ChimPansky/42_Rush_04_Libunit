/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_test_sigfpe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:44 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 18:53:36 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

int	test_sigfpe(void)
{
	int	div_zero;
	int	a;

	a = 5;
	div_zero = a / (a - a);
	(void) div_zero;
	return (SUCCESS);
}
