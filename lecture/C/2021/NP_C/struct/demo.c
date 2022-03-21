#include <stdbool.h>
#include <stdio.h>

// 结构体像数据的容器。
void container_of_data()
{
    int today_year = 2021,
        today_month = 6,
        today_day = 13;

    printf("今天是%d年%d月%d日。\n",
           today_year, today_month, today_day);

    // ---

    struct Date {
        int year, month, day;
    };

    struct Date today = {2021, 6, 13};
    printf("今天是%d年%d月%d日。\n",
           today.year, today.month, today.day);

    // ---

    typedef struct Date Date_;

    Date_ birthday = {1831, 6, 13};
    printf("J.C.麦克斯韦生于%d年%d月%d日。\n",
           birthday.year, birthday.month, birthday.day);
}

// 杂项
void miscellaneous()
{
    typedef struct {
        char name[12];
        char id[10];
        int age;
    } Student;

    Student students[5];
    puts("请依次输入每人的名字、学号、年龄，以空格分割 >> ");
    for (int i = 0; i < 5; i++)
        scanf("%s%s%d", students[i].name,
              students[i].id, &students[i].age);

    for (int i = 0; i < 5; i++)
        printf("%s, %s, %d\n", students[i].name,
               students[i].id, students[i].age);
}

int main()
{
    miscellaneous();
    return 0;
}
