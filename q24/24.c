#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    pid_t pid = getpid();

    int priority = getpriority(PRIO_PROCESS, pid);

    printf("PID = %d\n", pid);
    printf("Current nice value = %d\n", priority);

    printf("Use another terminal to run:\n");
    printf("renice 10 -p %d\n", pid);

    while (1) {
        sleep(2);
    }

    return 0;
}
