#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    if (argc < 2)
    {
        char *missingerr = "missing operand\n";
        write(2, missingerr, strlen(missingerr));
        exit(1);
    }else if (argc > 2)
    {
        char *toomanyerr = "too many operand\n";
        write(2, toomanyerr, strlen(toomanyerr));
        exit(1);
    }
    int value = atoi(argv[1]);
    sleep(value);
    exit(0);
}
