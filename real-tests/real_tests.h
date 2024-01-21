/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:32:01 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 15:48:39 by sdabland         ###   ########.fr       */
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
int	test_hello_world(void);
int	test_number(void);

#endif
