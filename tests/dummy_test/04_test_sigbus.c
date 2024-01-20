/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_test_sigbus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:52 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/20 16:30:30 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

//TODO: figure out what exactly causes BUS Errors...
int test_sigbus(void)
{
	if (true)
		return (SUCCESS);
	else
		return (FAILURE);
}
