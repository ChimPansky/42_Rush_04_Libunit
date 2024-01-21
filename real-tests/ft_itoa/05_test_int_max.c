/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_int_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:11:00 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 16:16:05 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "real_tests.h"

int	itoa_int_max(void)
{
	return (malloced_func_string(INT_MAX, "2147483647", &ft_itoa));
}
