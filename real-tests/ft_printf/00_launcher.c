#include "libunit.h"
#include "real_tests.h"

int ft_printf_launcher(t_tester *tester)
{
    t_unit_test *test_list;

    test_list = NULL;
    test_add(&test_list, "Hello World", &test_hello_world, true);
    test_add(&test_list, "Number", &test_number, true);
    return (launch_tests("FT_PRINTF", tester, test_list));
}
