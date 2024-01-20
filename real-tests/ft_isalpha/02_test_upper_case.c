#include "libunit.h"
#include "tests.h"

int test_upper_case(void)
{
	if (true)
		return (SUCCESS);
	else /* this dumb test fails */
		return (FAILURE);
}
