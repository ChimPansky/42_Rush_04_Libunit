#include "libft.h"
#include "libunit.h"

int test_number(void)
{
    int stdout_pipe;

    stdout_pipe = capture_stdout_to_pipe();
    ft_printf("> %d < %d > %d %d %d", 2147483647, -2147483648, 0, 10, -23);

    char buf[100];
    ft_bzero(buf, 100);
    if (read(stdout_pipe, buf, 100) < 0)
        return (-1);
    close(stdout_pipe);

    if (ft_strncmp("> 2147483647 < -2147483648 > 0 10 -23", buf, 37) != 0)
        return (-1);
    return (0);
}
