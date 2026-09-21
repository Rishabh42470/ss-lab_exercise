#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat st;
    char filename[100];

    printf("Enter filename: ");
    scanf("%s", filename);

    if (stat(filename, &st) == -1) {
        perror("stat");
        return 1;
    }

    if (S_ISREG(st.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(st.st_mode))
        printf("Directory\n");
    else if (S_ISFIFO(st.st_mode))
        printf("FIFO\n");
    else if (S_ISLNK(st.st_mode))
        printf("Symbolic link\n");
    else if (S_ISCHR(st.st_mode))
        printf("Character device\n");
    else if (S_ISBLK(st.st_mode))
        printf("Block device\n");
    else if (S_ISSOCK(st.st_mode))
        printf("Socket\n");
    else
        printf("Unknown file type\n");

    return 0;
}
