/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_test_sigpipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:38 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/20 16:32:00 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

//TODO: cause sigpipe Error...
int test_sigpipe(void)
{
	if (true)
		return (SUCCESS);
	else
		return (FAILURE);
}
