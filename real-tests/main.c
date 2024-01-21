/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:16:42 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 17:56:06 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "real_tests.h"

int	main(void)
{
	t_tester	tester;

	int	routine_ret;

	ft_bzero(&tester, sizeof(t_tester));
	if (true)
		routine_ret = ft_isalpha_launcher(&tester);
	if (true)
		ft_itoa_launcher(&tester);
	if (true)
		ft_printf_launcher(&tester);
	printf ("isalpha routine returnval: %d\n", routine_ret);
	return (SUCCESS);
}
