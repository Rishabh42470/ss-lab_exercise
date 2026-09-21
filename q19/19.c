#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("shared.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd);
        return 1;
    }

    if (pid == 0) {
        write(fd, "Child writing\n", 14);
        printf("Child wrote to file.\n");
    }
    else {
        write(fd, "Parent writing\n", 15);
        printf("Parent wrote to file.\n");
    }

    close(fd);
    return 0;
}
