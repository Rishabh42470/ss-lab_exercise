#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/resource.h>

int main(void)
{
    int priority;

    errno = 0;
    priority = getpriority(PRIO_PROCESS, 0);

    if (errno != 0) {
        perror("getpriority");
        return 1;
    }

    printf("Current process priority (nice value): %d\n", priority);

    printf("Increasing nice value by 5...\n");

    errno = 0;
    if (nice(5) == -1 && errno != 0) {
        perror("nice");
        return 1;
    }

    errno = 0;
    priority = getpriority(PRIO_PROCESS, 0);

    if (errno != 0) {
        perror("getpriority");
        return 1;
    }

    printf("New process priority (nice value): %d\n", priority);

    return 0;
}
