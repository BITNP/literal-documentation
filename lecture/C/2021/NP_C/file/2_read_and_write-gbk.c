#include <stdio.h>
#include <stdlib.h>

const char filename[] = "2.txt";

int count = 1;

void try_mode(const char *mode)
{
    printf("%d ������ %s ģʽ���ļ���\n", count, mode);
    
    // ��
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        perror("�ļ���ʧ��");
        exit(EXIT_FAILURE);
    }

    // ����
    fprintf(fp, "    ��仰���� %s ģʽд�ģ����ǵ� %d ����ͼд�롣\n",
            mode, count);

    if (ferror(fp))
        perror("д�ļ�����");
    else
        puts("��д���ļ���");

    // ���
    puts("�����ӡ�ļ����ݡ�");
    rewind(fp);
    char c;
    while (c = fgetc(fp), c != EOF)
        putchar(c);

    if (ferror(fp))
        perror("���ļ�����");
    else if (feof(fp))
        puts("����������ļ���ȫ�����ݡ�");

    // �ر�
    fclose(fp);

    puts("");
    count++;
}

int main()
{
    try_mode("w");
    try_mode("r");
    try_mode("a");
    try_mode("r+");
    try_mode("w+");
    try_mode("a+");
    // try_mode("wb+");
    // try_mode("rb+");
    // try_mode("ab+");

    return 0;
}
