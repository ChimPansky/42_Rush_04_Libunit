/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:11:13 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/20 16:11:14 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "tests.h"

int	ft_isalpha_launcher(void)
{
	t_unit_test	*test_list;

	test_list = NULL;
	test_add(&test_list, "Lower Case test", &test_lower_case, true);
	test_add(&test_list, "Upper Case test", &test_upper_case, true);
	test_add(&test_list, "Digit test", &test_digit, true);
	test_add(&test_list, "Null terminator test test", &test_null_terminator, true);

	return (launch_tests("STRLEN", &test_list));
}
