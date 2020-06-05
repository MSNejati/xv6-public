#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    time_t t;
    srand((unsigned)time(&t));
    int pid = fork();
    if (pid == 0)
    {
        fork();
        fork();
        fork();
        int *ptr = (int *)malloc((rand() % 100) * 1000);
        ptr++;
        while (1)
        {
        }
    }
    else
    {
        sleep(2);
    }
}