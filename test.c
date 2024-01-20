#include <stdlib.h>
int	main(void)
{
    char    *p;
    int        i;

    asm("pushf\n\torl $0x40000,(%rsp)\n\tpopf");
    p = malloc(sizeof(int) + 1);
    p++;
    i = *(int *)p;
    (void)i;
    return (1);
}

