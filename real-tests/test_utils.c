/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:12:15 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 18:34:27 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "real_tests.h"

int	simple_func_int(int input, int expected_return, int (*func)(int))
{
	if (func(input) == expected_return)
		return (SUCCESS);
	else
		return (FAILURE);
}

int	malloced_func_string(int input, char *expected_return, char *(*func)(int))
{
	char	*result;
	int		return_val;

	result = func(input);
	if (!result)
		return (FAILURE);
	if (ft_strlen(result) == ft_strlen(expected_return) && ft_strncmp(result,
			expected_return, ft_strlen(expected_return)) == 0)
		return_val = SUCCESS;
	else
		return_val = FAILURE;
	if (result)
		free(result);
	return (return_val);
}
