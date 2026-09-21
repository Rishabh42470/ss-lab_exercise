#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    int newfd = dup(fd);

    printf("Original FD = %d\n", fd);
    printf("Duplicate FD = %d\n", newfd);

    close(fd);
    close(newfd);

    return 0;
}
