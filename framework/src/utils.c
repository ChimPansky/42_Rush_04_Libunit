#include "libunit.h"

int capture_stdout_to_pipe()
{
    int stdout_pipe[2];

    if (pipe(stdout_pipe) == -1)
        return (-1);
    if (dup2(stdout_pipe[1], STDOUT_FILENO) == -1)
        return (close(stdout_pipe[0]), close(stdout_pipe[1]), -1);
    close(stdout_pipe[1]);
    return (stdout_pipe[0]);
}
