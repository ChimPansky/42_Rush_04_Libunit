/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:16:42 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 18:19:45 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "real_tests.h"

int	main(void)
{
	t_tester	tester;

	ft_bzero(&tester, sizeof(t_tester));
	if (true)
		ft_isalpha_launcher(&tester);
	if (true)
		ft_itoa_launcher(&tester);
	if (true)
		ft_printf_launcher(&tester);
	return (SUCCESS);
}
