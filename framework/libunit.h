#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/wait.h>

#include <stdio.h>	// remove before push

# define SUCCESS 0
# define FAILURE -1

typedef struct s_unit_test
{
	char				*title;
	int					(*test_function)(void);
	bool				enabled;
	struct s_unit_test	*next;
}				t_unit_test;

t_unit_test	*test_add(t_unit_test **tests,
	char *title, int (*test_function)(void), bool enabled);

int	launch_tests(char *routine_name, t_unit_test **test_list);
void	print_tests(t_unit_test *test_list);


#endif
