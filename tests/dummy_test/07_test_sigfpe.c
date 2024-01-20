/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_test_sigfpe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:44 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/20 16:30:37 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

//TODO: cause sigfpe Error...
int test_sigfpe(void)
{
	if (true)
		return (SUCCESS);
	else
		return (FAILURE);
}
