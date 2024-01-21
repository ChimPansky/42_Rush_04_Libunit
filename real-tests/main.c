/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:16:42 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 15:49:12 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "real_tests.h"

int	simple_func_int(int input, int expected_return, int (*func)(int))
{
	if (func(input) == expected_return)
		return (SUCCESS);
	else
		return (FAILURE);
}

int	main(void)
{
	if (true)
		ft_isalpha_launcher();
	if (false)
		ft_xxx_launcher();
	if (true)
		ft_printf_launcher();
	return (SUCCESS);
}
