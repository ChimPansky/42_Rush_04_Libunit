#include "libunit.h"

t_unit_test	*test_create(char *title, int (*test_function)(void), bool enabled)
{
	t_unit_test	*new_test = malloc(sizeof(t_unit_test));

	if (!new_test)
		return (NULL);
	new_test->title = title;
	new_test->test_function = test_function;
	new_test->enabled = enabled;
	return (new_test);
}

t_unit_test	*test_add(t_unit_test **tests,
	char *title, int (*test_function)(void), bool enabled)
{
	t_unit_test	*new_test;
	t_unit_test	*cur_test;

	new_test = test_create(title, test_function, enabled);
	if (!new_test)	// TODO: Exit/Error?
		return (NULL);
	if (tests && !*tests)
		*tests = new_test;
	else
	{
		cur_test = *tests;
		while (cur_test->next)
			cur_test = cur_test->next;
		cur_test->next = new_test;
	}
	return (new_test);
}

int	launch_tests(char *routine_name, t_unit_test **test_list)
{
	printf("executing %s tests...\n", routine_name);
	print_tests(*test_list);
	return (SUCCESS);
}

void	print_tests(t_unit_test *test_list)
{
	t_unit_test	*cur_test;

	cur_test = test_list;

	printf("unit_test_list:\n");
	if (!cur_test)
		return ;
	while (cur_test)
	{
		printf("{Title: %s; Function_ptr: %p; Enabled: %d;)}\n",  cur_test->title, cur_test->test_function, cur_test->enabled);
		cur_test = cur_test->next;
	}
	printf("\n");
}
