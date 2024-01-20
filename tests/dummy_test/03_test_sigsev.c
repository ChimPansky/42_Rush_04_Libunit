/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_test_sigsev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:55 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/20 18:28:05 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

int test_sigsev(void)
{
	void	**dummy1;
	void	*dummy2;

	dummy1 = NULL;
	dummy2 = *dummy1;
	return (SUCCESS);
}
