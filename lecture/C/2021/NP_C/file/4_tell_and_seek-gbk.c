#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("./4.txt", "w+");
    if (fp == NULL) {
        perror("Fail to open ./4.txt");
        exit(EXIT_FAILURE);
    }

    // д��
    fputs("����ַ�����Ҫ ��_��", fp);

    long important_pos = ftell(fp);
    fputs("!", fp);

    fputs("��_�� ��Ҫ�����Ǹ��ַ�������ʲô����Ҫ��\n", fp);

    // ���
    fseek(fp, important_pos, SEEK_SET);
    printf("��Ҫ�ַ���%c\n", fgetc(fp));

    rewind(fp);
    puts("ȫ�����ݣ�");
    char c;
    while (c = fgetc(fp), c != EOF)
        putchar(c);

    fclose(fp);

    return 0;
}
