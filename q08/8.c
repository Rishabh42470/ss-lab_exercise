#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char ch;

    fd = open("file.txt", O_RDONLY);

    if(fd == -1)
    {
        perror("open");
        return 1;
    }

    while(read(fd, &ch, 1) > 0)
    {
        write(1, &ch, 1);
    }

    close(fd);

    return 0;
}
