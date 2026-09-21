#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    struct stat s;

    if(stat("file.txt", &s) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("Inode: %ld\n", s.st_ino);
    printf("Hard links: %ld\n", s.st_nlink);
    printf("UID: %d\n", s.st_uid);
    printf("GID: %d\n", s.st_gid);
    printf("Size: %ld bytes\n", s.st_size);
    printf("Block size: %ld\n", s.st_blksize);
    printf("Blocks: %ld\n", s.st_blocks);

    printf("Last access: %s", ctime(&s.st_atime));
    printf("Last modification: %s", ctime(&s.st_mtime));
    printf("Last change: %s", ctime(&s.st_ctime));

    return 0;
}
