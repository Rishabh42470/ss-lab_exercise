#include <stdio.h>
#include <unistd.h>

int main()
{
    if(symlink("file1.txt", "softlink") == -1)
    {
        perror("symlink");
        return 1;
    }

    printf("Soft link created successfully\n");

    return 0;
}

