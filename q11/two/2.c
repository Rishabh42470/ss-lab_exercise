#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    dup2(fd, 1);

    printf("Hello Linux\n");

    close(fd);

    return 0;
}
