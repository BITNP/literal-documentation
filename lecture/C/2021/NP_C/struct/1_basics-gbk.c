#include <stdio.h>

struct Complex_ {
    float re; // ʵ��
    float im; // �鲿
};

typedef struct Complex_ Complex;

int main()
{
    // struct Complex_ z = {1, 2};
    Complex z = {1, 2};
    
    printf("%.2f + %.2fi\n", z.re, z.im);
    // Ϊ������������ֻ������������

    return 0;
}
