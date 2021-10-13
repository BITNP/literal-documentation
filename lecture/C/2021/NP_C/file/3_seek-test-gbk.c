#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("./3.txt", "wb+");
    if (fp == NULL) {
        perror("Fail to open ./3.txt");
        exit(EXIT_FAILURE);
    }

    fputs("A sentence.\n", fp);

    fseek(fp, 0, SEEK_END);
    printf("SEEK_END: %d\n", fgetc(fp));

    fseek(fp, -1, SEEK_END);
    printf("SEEK_END - 1: %d\n", fgetc(fp));
    
    fseek(fp, -2, SEEK_END);
    printf("SEEK_END - 2: %c\n", fgetc(fp));

    fclose(fp);

    return 0;
}
