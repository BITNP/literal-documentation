#include <stdio.h> // fopen() ��
#include <stdlib.h> // exit() ��

int main()
{
    const char filename[] = "./1.txt"; // �� cwd д��

    FILE *file_pointer = fopen(filename, "a+");
    if (file_pointer == NULL) {
        perror("�ļ���ʧ��");
        exit(EXIT_FAILURE);
    }

    puts("�ļ��򿪳ɹ���");

    /* ���ﴦ���ļ� */

    fclose(file_pointer);

    return 0;
}
