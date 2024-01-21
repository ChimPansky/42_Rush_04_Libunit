/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:32:01 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 15:31:38 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAL_TESTS_H
# define REAL_TESTS_H

# include "libunit.h"
# include "libft.h"

int	simple_func_int(int input, int expected_return, int (*func)(int));
int	malloced_func_string(int input, char *expected_return, char * (*func)(int));

// ft_isalpha:
int	ft_isalpha_launcher(void);
int	isalpha_lower_case(void);
int	isalpha_upper_case(void);
int	isalpha_digit(void);
int	isalpha_special(void);
int	isalpha_null_terminator(void);

// ft_itoa:
int	ft_itoa_launcher(void);
int	itoa_zero(void);
int	itoa_one(void);

// ft_printf:
int	ft_printf_launcher(void);

#endif
