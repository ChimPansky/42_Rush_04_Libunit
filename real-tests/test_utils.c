/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:29:36 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 16:29:50 by tkasbari         ###   ########.fr       */
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

int	malloced_func_string(int input, char *expected_return, char * (*func)(int))
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
