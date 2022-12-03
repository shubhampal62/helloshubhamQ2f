#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sched.h>
#include <sys/wait.h>

struct timespec start1, end1, delta1;
struct timespec start2, end2, delta2;
struct timespec start3, end3, delta3;

int main()
{
    int pid1 = fork();
    int pid2 = fork();
    int pid3 = fork();

    if (pid1 > 0 && pid2 > 0 && pid3 == 0)
    {
        clock_gettime(CLOCK_REALTIME, &start1);
        printf("child 1 \n");
        execl("/bin/bash", "sh", "bash1.sh", NULL);
        return 0;
    }
    
    else if (pid1 > 0 && pid2 == 0 && pid3 > 0)
    {
        clock_gettime(CLOCK_REALTIME, &start2);
        printf("I am child 2\n");
        execl("/bin/bash", "sh", "bash1.sh", NULL);
    }
    else if (pid1 == 0 && pid2 > 0 && pid3 > 0)
    {
        clock_gettime(CLOCK_REALTIME, &start3);
        printf("I am child 3\n");
        execl("/bin/bash", "sh", "bash1.sh", NULL);
    }
    while (waitpid(-1, NULL, 0) > 0)
        ;
    clock_gettime(CLOCK_REALTIME, &end);
    printf("time taken by child 3 %d.%.9ld\n", (int)delta.tv_sec, delta.tv_nsec);

    return 0;
}