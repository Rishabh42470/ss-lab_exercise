#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int target_hour, target_minute;
    time_t now;
    struct tm *current_time;
    struct tm target_time;
    long wait_seconds;
    int fd;

    if (argc < 3) {
        printf("Usage: %s HH:MM \"command\"\n", argv[0]);
        printf("Example: %s 23:30 \"date >> /tmp/task.log\"\n", argv[0]);
        return 1;
    }

    if (sscanf(argv[1], "%d:%d", &target_hour, &target_minute) != 2 ||
        target_hour < 0 || target_hour > 23 ||
        target_minute < 0 || target_minute > 59) {
        printf("Invalid time. Use HH:MM format.\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid > 0) {
        printf("Daemon started with PID: %d\n", pid);
        return 0;
    }

    if (setsid() == -1) {
        perror("setsid");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {
        exit(0);
    }

    umask(0);
    chdir("/");

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    fd = open("/dev/null", O_RDWR);

    if (fd >= 0) {
        dup2(fd, STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);

        if (fd > STDERR_FILENO)
            close(fd);
    }

    time(&now);
    current_time = localtime(&now);

    target_time = *current_time;
    target_time.tm_hour = target_hour;
    target_time.tm_min = target_minute;
    target_time.tm_sec = 0;

    if (mktime(&target_time) <= now) {
        target_time.tm_mday++;
    }

    wait_seconds = (long)difftime(mktime(&target_time), now);

    if (wait_seconds > 0)
        sleep((unsigned int)wait_seconds);

    system(argv[2]);

    return 0;
}
