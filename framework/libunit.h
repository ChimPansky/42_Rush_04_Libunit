/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkasbari <thomas.kasbarian@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:25:03 by sdabland          #+#    #+#             */
/*   Updated: 2024/01/21 17:59:17 by tkasbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>	// remove before push
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "signal.h"

# define DEF_COLOR "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

# ifndef TEST_TIMEOUT_SECS
#  define TEST_TIMEOUT_SECS 2
# endif

# define SUCCESS 0
# define FAILURE -1

typedef struct s_tester
{
	char	*current_routine;
	int		routine_nr;
}				t_tester;

typedef struct s_unit_test
{
	char				*title;
	int					(*test_function)(void);
	bool				enabled;
	struct s_unit_test	*next;
}				t_unit_test;

typedef enum e_test_status
{
	STATUS_OK,
	STATUS_KO,
	STATUS_SIGSEGV,
	STATUS_SIGBUS,
	STATUS_SIGABRT,
	STATUS_SIGFPE,
	STATUS_SIGPIPE,
	STATUS_SIGILL,
	STATUS_TIMEOUT,
	STATUS_NOT_RUN,
	STATUS_UNKNOWN
}					t_test_status;

// unit.c:
t_unit_test	*test_add(t_unit_test **tests, char *title,
				int (*test_function)(void), bool enabled);
void		test_free(t_unit_test *test);
int			launch_tests(t_tester *tester, t_unit_test *test_list);
void		log_test(char *launcher_name, t_unit_test *test,
				t_test_status status, int fd);
void		log_summary(t_unit_test *tests, int passed, int fd);

// executor.c:
int			execute_test(t_unit_test *tests_head, t_unit_test *test,
				int file_fd, int null_fd);
int			execute_routine(char *routine_name,
	t_unit_test *test_list, int file_fd, int null_fd);

// logging.c:
void		logfile_error(void);
void		devnull_error(void);

// utils.c:
int			capture_stdout_to_pipe();
int			get_total_tests(t_unit_test *test_list);

#endif
