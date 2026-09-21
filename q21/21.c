#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        printf("Parent PID = %d\n", getpid());
        printf("Parent exiting...\n");
        return 0;
    }

    sleep(3);

    printf("Child PID = %d\n", getpid());
    printf("New Parent PID = %d\n", getppid());

    return 0;
}
