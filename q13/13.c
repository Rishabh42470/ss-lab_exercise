#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set readfds;
    char buffer[100];

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    printf("Waiting for input...\n");

    select(STDIN_FILENO + 1, &readfds, NULL, NULL, NULL);

    if (FD_ISSET(STDIN_FILENO, &readfds)) {
        int n = read(STDIN_FILENO, buffer, sizeof(buffer));
        write(STDOUT_FILENO, buffer, n);
    }

    return 0;
}
