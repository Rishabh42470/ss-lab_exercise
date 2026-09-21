#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2;

    child1 = fork();

    if (child1 == 0) {
        printf("Child 1: PID = %d\n", getpid());
        sleep(2);
        return 0;
    }

    child2 = fork();

    if (child2 == 0) {
        printf("Child 2: PID = %d\n", getpid());
        sleep(4);
        return 0;
    }

    printf("Parent waiting for Child 2...\n");

    waitpid(child2, NULL, 0);

    printf("Child 2 finished.\n");

    waitpid(child1, NULL, 0);

    printf("Child 1 finished.\n");

    return 0;
}
