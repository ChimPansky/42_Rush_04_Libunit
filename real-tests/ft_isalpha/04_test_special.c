/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_test_sigbus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:10:52 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/20 18:28:12 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"
#include <stdlib.h>

int test_sigbus(void)
{
	char    *p;
    int        i;

    asm("pushf\n\torl $0x40000,(%rsp)\n\tpopf");
    p = malloc(sizeof(int) + 1);
    p++;
    i = *(int *)p;
    //(void)i;
	return (SUCCESS);
}
