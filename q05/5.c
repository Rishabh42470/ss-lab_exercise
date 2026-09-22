#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int count = 0;

    while(1)
    {
        for(int i = 0; i < 5; i++)
        {
            char filename[50];

            sprintf(filename, "file%d.txt", count++);

            int fd = open(filename, O_CREAT | O_RDWR, 0644);

            if(fd == -1)
            {
                perror("open");
                return 1;
            }

            printf("Created %s with FD %d\n", filename, fd);
        }

        sleep(2);
    }

    return 0;
}
