#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("file.txt", O_RDWR);

    if(fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("File opened successfully\n");
    printf("File descriptor = %d\n", fd);

    close(fd);

    return 0;
}
