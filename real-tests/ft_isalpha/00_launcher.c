/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:11:03 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 14:23:26 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "real_tests.h"

int	ft_isalpha_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	test_add(&test_list, "Lower Case test", &test_lower_case, true);
	test_add(&test_list, "Upper Case test", &test_upper_case, true);
	test_add(&test_list, "Digit test", &test_digit, true);
	test_add(&test_list, "Special Char test", &test_special, true);
	test_add(&test_list, "Null terminator test", &test_null_terminator, true);
	return (launch_tests("FT_ISALPHA", &test_list));
}
