/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:32:01 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 14:15:34 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_H
# define DUMMY_H

# include "libunit.h"
# include "libft.h"

int	dummy_launcher(void);
int	test_ok(void);
int	test_ko(void);
int	test_sigsev(void);
int	test_sigbus(void);
int	test_timeout(void);
int	test_sigabrt(void);
int	test_sigfpe(void);
int	test_sigpipe(void);
int	test_sigill(void);

#endif
