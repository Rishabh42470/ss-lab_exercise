#include <stdio.h>
#include <unistd.h>

int main() {
    printf("PID = %d\n", getpid());
    printf("Process is currently running.\n");

    printf("Check process state using:\n");
    printf("ps -o pid,stat,cmd -p %d\n", getpid());

    sleep(10);

    return 0;
}
