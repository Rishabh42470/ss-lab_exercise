#include <unistd.h>

int main()
{
    char buffer[100];

    int n = read(0, buffer, 100);

    write(1, buffer, n);

    return 0;
}
