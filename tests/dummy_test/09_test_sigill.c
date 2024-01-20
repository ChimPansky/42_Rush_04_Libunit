/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_test_sigill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:36 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/20 16:32:09 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

//TODO: cause sigill Error...
int test_sigill(void)
{
	if (true)
		return (SUCCESS);
	else
		return (FAILURE);
}
