/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:11:03 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 17:25:36 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

int	dummy_launcher(t_tester *tester)
{
	t_unit_test	*test_list;

	test_list = NULL;
	tester->current_routine = "DUMMY Tests";
	tester->routine_nr++;
	test_add(&test_list, "Dummy test OK", &test_ok, true);
	test_add(&test_list, "Dummy test KO", &test_ko, true);
	test_add(&test_list, "Dummy test SIGSEV", &test_sigsev, true);
	test_add(&test_list, "Dummy test SIGBUS", &test_sigbus, true);
	test_add(&test_list, "Dummy test TIMEOUT", &test_timeout, true);
	test_add(&test_list, "Dummy test SIGABRT", &test_sigabrt, true);
	test_add(&test_list, "Dummy test SIGFPE", &test_sigfpe, true);
	test_add(&test_list, "Dummy test SIGPIPE", &test_sigpipe, true);
	test_add(&test_list, "Dummy test SIGILL", &test_sigill, true);
	test_add(&test_list, "Dummy test SKIPPED", &test_ok, false);
	return (launch_tests(tester, &test_list));
}
