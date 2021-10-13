#include <stdio.h> // fopen() 等
#include <stdlib.h> // exit() 等

int main()
{
    const char filename[] = "./1.txt"; // 从 cwd 写起

    FILE *file_pointer = fopen(filename, "a+");
    if (file_pointer == NULL) {
        perror("文件打开失败");
        exit(EXIT_FAILURE);
    }

    puts("文件打开成功！");

    /* 这里处理文件 */

    fclose(file_pointer);

    return 0;
}
