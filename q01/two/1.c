#include <stdio.h>
#include <unistd.h>

int main()
{
    if(link("file1.txt", "hardlink") == -1)
    {
        perror("link");
        return 1;
    }

    printf("Hard link created successfully\n");

    return 0;
}
