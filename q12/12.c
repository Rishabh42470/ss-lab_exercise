#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("file.txt", O_RDWR | O_CREAT, 0644);

    int flags = fcntl(fd, F_GETFL);

    if (flags == -1)
    {
        perror("fcntl");
        return 1;
    }

    int mode = flags & O_ACCMODE;

    if (mode == O_RDONLY)
        printf("Read Only\n");

    else if (mode == O_WRONLY)
        printf("Write Only\n");

    else if (mode == O_RDWR)
        printf("Read + Write\n");

    close(fd);

    return 0;
}
