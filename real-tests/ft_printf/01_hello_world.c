#include "libft.h"
#include "libunit.h"

int test_hello_world(void)
{
    int stdout_pipe;

    stdout_pipe = capture_stdout_to_pipe();
    ft_printf("Hello World!\n");

    char buf[100];
    ft_bzero(buf, 100);
    if (read(stdout_pipe, buf, 100) < 0)
        return (-1);
    close(stdout_pipe);

    if (ft_strncmp("Hello World!\n", buf, 13) != 0)
        return (-1);
    return (0);
}
