/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:14:28 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 18:33:21 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "real_tests.h"

int	ft_printf_launcher(t_tester *tester)
{
	t_unit_test	*test_list;

	test_list = NULL;
	test_add(&test_list, "Hello World",
		&test_hello_world, true);
	test_add(&test_list, "Number",
		&test_number, true);
	test_add(&test_list, "Hex",
		&test_hex, true);
	test_add(&test_list, "NULL",
		&test_null, true);
	test_add(&test_list, "Hex Big",
		&test_hex_big, true);
	return (launch_tests("FT_PRINTF", tester, test_list));
}
