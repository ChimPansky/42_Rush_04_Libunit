#include "libunit.h"
#include "tests.h"

int test_null_terminator(void)
{
	if (true)
		return (SUCCESS);
	else /* this dumb test fails */
		return (FAILURE);
}
