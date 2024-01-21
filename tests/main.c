/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabland <sdabland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:17:17 by tkasbari          #+#    #+#             */
/*   Updated: 2024/01/21 18:36:52 by sdabland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "dummy.h"

int	main(void)
{
	t_tester	tester;

	ft_bzero(&tester, sizeof(t_tester));
	dummy_launcher(&tester);
	return (0);
}
