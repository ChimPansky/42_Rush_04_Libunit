/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:11:03 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 18:27:55 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "real_tests.h"

int	ft_itoa_launcher(t_tester *tester)
{
	t_unit_test	*test_list;

	test_list = NULL;
	test_add(&test_list, "Zero test", &itoa_zero, true);
	test_add(&test_list, "1 test", &itoa_one, true);
	test_add(&test_list, "Negative test", &itoa_negative, true);
	test_add(&test_list, "42 test", &itoa_42, true);
	test_add(&test_list, "INT_MAX test", &itoa_int_max, true);
	test_add(&test_list, "INT_MIN test", &itoa_int_min, true);
	return (launch_tests("FT_ITOA", tester, test_list));
}
