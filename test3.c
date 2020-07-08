#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int id;
    double x=0, z;

    x = 0;
    id = 0;

    id = fork();
    setp(id, ((id * 15) + 58) % 100);
    id = fork();
    setp(id, ((id * 20) + 80) % 100);
    id = fork();
    setp(id, ((id * 8) + 25) % 100);
    id = fork();
    setp(id, ((id * 17) + 97) % 100);
    if(id < 0)
        printf(1, "%d failed in fork!\n", getpid());
    else if(id > 0)
    {   // Parent
        printf(1, "Parent %d creating child %d\n", getpid(), id);
        // cps();
        wait();
    }
    else
    {   // Child
        printf(1, "Child %d created\n", getpid());
        cps();
        for(z=0;z<80000.0;z+=0.001)
            x = x + 3.14*69.69; // Useless calculations to consume CPU time
        exit();
    }
    exit();
}