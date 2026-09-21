#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <string.h>
#include <errno.h>

int main(void)
{
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0);

    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("Current scheduling policy: ");

    switch (policy) {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown policy (%d)\n", policy);
    }

    printf("\nChanging scheduling policy to SCHED_RR...\n");

    param.sched_priority = sched_get_priority_min(SCHED_RR);

    if (param.sched_priority == -1) {
        perror("sched_get_priority_min");
        return 1;
    }

    if (sched_setscheduler(0, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler");
        printf("Note: SCHED_RR normally requires appropriate privileges.\n");
        return 1;
    }

    policy = sched_getscheduler(0);

    if (policy == -1) {
        perror("sched_getscheduler");
        return 1;
    }

    printf("New scheduling policy: ");

    switch (policy) {
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        default:
            printf("Unknown policy (%d)\n", policy);
    }

    return 0;
}
