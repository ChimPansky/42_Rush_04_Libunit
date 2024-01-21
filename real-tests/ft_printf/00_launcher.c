#include "libunit.h"
#include "tests.h"

int ft_printf_launcher(void)
{
    t_unit_test *test_list;

    test_list = NULL;
    test_add(&test_list, "Hello World", &test_hello_world, true);
    test_add(&test_list, "Number", &test_number, true);

    return (launch_tests("ft_printf", &test_list));
}