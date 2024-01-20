#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

# define SUCCESS 0
# define FAILURE -1

t_list	t_unit_test;

typedef struct s_test_case
{
	char	*title;
	// add necessary fields...
}				t_test_case

t_test_case	*test_case_add(t_unit_test **tests, char *title, void *test_function);

#endif