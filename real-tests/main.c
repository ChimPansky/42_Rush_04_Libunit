/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:16:42 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 14:28:17 by tkasbari         ###   ########.fr       */
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
	if (false)
		ft_printf_launcher();
	return (SUCCESS);
}
