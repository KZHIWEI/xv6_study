#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
    int parent_write[2];
    int children_write[2];

    pipe(parent_write);
    pipe(children_write);

    int pid = fork();
    if (pid == 0){
        close(parent_write[1]);
        close(children_write[0]);
        char buf[56];
        read(parent_write[0], buf, 55);
        close(parent_write[0]);
        int pid = getpid();
        printf("%d: received ping\n", pid);
        write(children_write[1],"1",1);
        close(children_write[1]);
    }else{
        close(children_write[1]);
        close(parent_write[0]);
        write(parent_write[1], "1", 1);
        char buf[56];
        read(children_write[0], buf, 55);
        int pid = getpid();
        printf("%d: received pong\n", pid);
        close(parent_write[1]);
    }
    exit(0);
}
