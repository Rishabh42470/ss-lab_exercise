#include <stdio.h>
#include <unistd.h>

int main() {
    printf("PID = %d\n", getpid());
    printf("CPU-intensive process running...\n");

    while (1) {
        // CPU intensive work
    }

    return 0;
}
