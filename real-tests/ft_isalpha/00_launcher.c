/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:11:03 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 17:57:30 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "real_tests.h"

int	ft_isalpha_launcher(t_tester *tester)
{
	t_unit_test	*test_list;

	test_list = NULL;
	tester->current_routine = "FT_ISALPHA";
	tester->routine_nr++;
	test_add(&test_list, "Lower Case test", &isalpha_lower_case, true);
	test_add(&test_list, "Upper Case test", &isalpha_upper_case, true);
	test_add(&test_list, "Digit test", &isalpha_digit, true);
	test_add(&test_list, "Special Char test", &isalpha_special, true);
	test_add(&test_list, "Null terminator test",
		&isalpha_null_terminator, true);
	return (launch_tests(tester, test_list));
}
