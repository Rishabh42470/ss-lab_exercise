#include <stdio.h>
#include <sched.h>

int main(void)
{
    int max_priority, min_priority;

    max_priority = sched_get_priority_max(SCHED_FIFO);
    min_priority = sched_get_priority_min(SCHED_FIFO);

    if (max_priority == -1 || min_priority == -1) {
        perror("sched_get_priority");
        return 1;
    }

    printf("Real-time scheduling policy: SCHED_FIFO\n");
    printf("Maximum real-time priority: %d\n", max_priority);
    printf("Minimum real-time priority: %d\n", min_priority);

    return 0;
}
