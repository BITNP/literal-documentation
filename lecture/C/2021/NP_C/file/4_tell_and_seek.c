#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("./4.txt", "w+");
    if (fp == NULL) {
        perror("Fail to open ./4.txt");
        exit(EXIT_FAILURE);
    }

    // 写入
    fputs("这个字符很重要 →_→", fp);

    long important_pos = ftell(fp);
    fputs("!", fp);

    fputs("←_← 重要的是那个字符，我是什么不重要。\n", fp);

    // 输出
    fseek(fp, important_pos, SEEK_SET);
    printf("重要字符：%c\n", fgetc(fp));

    rewind(fp);
    puts("全部内容：");
    char c;
    while (c = fgetc(fp), c != EOF)
        putchar(c);

    fclose(fp);

    return 0;
}
