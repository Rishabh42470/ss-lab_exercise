#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child PID = %d\n", getpid());
        printf("Child exiting...\n");
        return 0;
    }
    else {
        printf("Parent PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);
        printf("Parent sleeping. Check child using ps.\n");

        sleep(10);

        wait(NULL);

        printf("Child collected. Zombie removed.\n");
    }

    return 0;
}
