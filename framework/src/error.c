#include "libunit.h"

void	logfile_error()
{
	ft_putendl_fd("Error: Failed to create logfile.", STDERR_FILENO);
}

void	devnull_error()
{
	ft_putendl_fd("Error: Failed to open /dev/null.", STDERR_FILENO);
}