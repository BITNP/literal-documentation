#include <stdio.h>

struct Complex_ {
    float re; // 实部
    float im; // 虚部
};

typedef struct Complex_ Complex;

int main()
{
    // struct Complex_ z = {1, 2};
    Complex z = {1, 2};
    
    printf("%.2f + %.2fi\n", z.re, z.im);
    // 为简便起见，这里只考虑了正数。

    return 0;
}
