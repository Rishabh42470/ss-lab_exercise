#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *args[] = {"ls", "-Rl", NULL};
    char *envp[] = {"PATH=/usr/bin:/bin", NULL};

    if (argc != 2) {
        printf("Usage: %s <a|b|c|d|e>\n", argv[0]);
        printf("a = execl\n");
        printf("b = execlp\n");
        printf("c = execle\n");
        printf("d = execv\n");
        printf("e = execvp\n");
        return 1;
    }

    switch (argv[1][0]) {
        case 'a':
            execl("/bin/ls", "ls", "-Rl", (char *)NULL);
            break;

        case 'b':
            execlp("ls", "ls", "-Rl", (char *)NULL);
            break;

        case 'c':
            execle("/bin/ls", "ls", "-Rl", (char *)NULL, envp);
            break;

        case 'd':
            execv("/bin/ls", args);
            break;

        case 'e':
            execvp("ls", args);
            break;

        default:
            printf("Invalid option. Use a, b, c, d, or e.\n");
            return 1;
    }

    perror("exec failed");
    return 1;
}
