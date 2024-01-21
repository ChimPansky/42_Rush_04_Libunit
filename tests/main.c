/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:17:17 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 17:26:43 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

int	main(void)
{
	t_tester	tester;

	ft_bzero(&tester, sizeof(t_tester));
	dummy_launcher(tester);
	return (0);
}
