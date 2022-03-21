#include <stdio.h>
#include <stdlib.h>

void infinite_read()
{
    const char filename[] = "demo.txt";
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Write failure");
        exit(EXIT_FAILURE);
    }
    fputs("旧历的年底毕竟最像年底，??\n", fp);
    fclose(fp);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Read failure");
        exit(EXIT_FAILURE);
    }

    puts("char: ");
    for (int i = 0; i < 50; i++)
        putchar(fgetc(fp));

    rewind(fp);
    puts("int:");
    for (int i = 0; i < 50; i++)
        printf("%0X ", fgetc(fp));

    fclose(fp);

    puts("[End]");
}

int main()
{
    infinite_read();

    return 0;
}
