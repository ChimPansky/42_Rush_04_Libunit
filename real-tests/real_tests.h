/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:32:01 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 14:51:49 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAL_TESTS_H
# define REAL_TESTS_H

# include "libunit.h"
# include "libft.h"

int	simple_func_int(int input, int expected_return, int (*func)(int));

// ft_isalpha:
int	ft_isalpha_launcher(void);
int	test_lower_case(void);
int	test_upper_case(void);
int	test_digit(void);
int	test_special(void);
int	test_null_terminator(void);

// ft_XXX:
int	ft_xxx_launcher(void);

// ft_printf:
int	ft_printf_launcher(void);

#endif
