#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, fd2;

    fd = open("q11_fcntl.txt",
              O_WRONLY | O_CREAT | O_TRUNC | O_APPEND,
              0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    fd2 = fcntl(fd, F_DUPFD, 10);

    if (fd2 == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    printf("Original FD = %d\n", fd);
    printf("Duplicated FD = %d\n", fd2);

    write(fd, "Written using FD1\n", 18);
    write(fd2, "Written using FD2\n", 18);

    close(fd);
    close(fd2);

    return 0;
}
