/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_test_sigabrt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:47 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/20 16:30:34 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

//TODO: cause sigabrt Error...
int test_sigabrt(void)
{
	if (true)
		return (SUCCESS);
	else
		return (FAILURE);
}
