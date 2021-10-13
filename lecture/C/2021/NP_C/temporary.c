#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;
    do {
        x++;
    } while (x < 3);
    printf("%d", x);

    return 0;
}
