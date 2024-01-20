#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "libft.h"
# include <stdio.h>	// remove before push
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

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
#  define TEST_TIMEOUT_SECS 3
# endif

# define SUCCESS 0
# define FAILURE -1

typedef struct s_unit_test
{
	char				*title;
	int					(*test_function)(void);
	bool				enabled;
	struct s_unit_test	*next;
}				t_unit_test;

typedef	enum e_test_status
{
	STATUS_OK,
	STATUS_KO,
	STATUS_SIGSEGV,
	STATUS_SIGBUS,
	STATUS_TIMEOUT,
	STATUS_NOT_RUN,
	STATUS_UNKNOWN
}				t_test_status;

t_unit_test	*test_add(t_unit_test **tests,
	char *title, int (*test_function)(void), bool enabled);

int	launch_tests(char *routine_name, t_unit_test **test_list);
void	print_tests(t_unit_test *test_list);

void	log_test(char *launcher_name, t_unit_test *test, t_test_status status);

int	execute_test(t_unit_test *test);

#endif
