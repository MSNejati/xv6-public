#include "types.h"
#include "stat.h"
#include "user.h"

// We create some processes here and allocate memory to them
int main(void)
{
    int pid = fork();
    if (pid == 0)
    {
        fork();
        fork();
        fork();
        int processId = getpid();
        int *ptr;
        ptr = malloc(100000 * processId);
        ptr++;
        while (1)
        {
        }
    }
    else
    {
        sleep(2);
    }
    exit();
}