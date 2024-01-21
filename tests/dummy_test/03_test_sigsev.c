/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_test_sigsev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:55 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 18:53:11 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

int	test_sigsev(void)
{
	void	**dummy1;
	void	*dummy2;

	dummy1 = NULL;
	dummy2 = *dummy1;
	(void) dummy2;
	return (SUCCESS);
}
