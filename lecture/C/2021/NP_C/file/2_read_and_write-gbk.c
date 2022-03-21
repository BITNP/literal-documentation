#include <stdio.h>
#include <stdlib.h>

const char filename[] = "2.txt";

int count = 1;

void try_mode(const char *mode)
{
    printf("%d 现在用 %s 模式打开文件。\n", count, mode);
    
    // 打开
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        perror("文件打开失败");
        exit(EXIT_FAILURE);
    }

    // 处理
    fprintf(fp, "    这句话是在 %s 模式写的，这是第 %d 次试图写入。\n",
            mode, count);

    if (ferror(fp))
        perror("写文件错误");
    else
        puts("已写入文件。");

    // 输出
    puts("下面打印文件内容。");
    rewind(fp);
    char c;
    while (c = fgetc(fp), c != EOF)
        putchar(c);

    if (ferror(fp))
        perror("读文件错误");
    else if (feof(fp))
        puts("——这就是文件的全部内容。");

    // 关闭
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
