#include <math.h>
#include <stdio.h>

typedef struct {
    float re; // 实部
    float im; // 虚部
} Complex;

const Complex one = {1., 0.}, I = {0., 1.},
              omega = {-0.500, 0.866};

#define NearlyZero 1e-4

void print_c(Complex z)
{
    float re = z.re,
          im = z.im;

    if (fabs(im) < NearlyZero) {
        if (fabs(re) < NearlyZero)
            printf("0\n");
        else
            printf("%.3f\n", re);
    } else {
        if (fabs(re) < NearlyZero)
            printf("%.3f i\n", im);
        else
            printf("%.3f %c %.3f i\n", re,
                   im > 0 ? '+' : '-', fabs(im));
    }
}

void make_conjugate(Complex *p)
{
    p->im = -p->im;
}

Complex sum_c(Complex z1, Complex z2)
{
    Complex ret;
    ret.re = z1.re + z2.re;
    ret.im = z1.im + z2.im;

    return ret;
}

Complex prod_c(Complex z1, Complex z2)
{
    Complex ret;
    ret.re = z1.re * z2.re - z1.im * z2.im;
    ret.im = z1.re * z2.im + z1.im * z2.re;

    return ret;
}

void times_by_c(Complex *p, Complex z)
{
    float p_re = p->re;
    p->re = p->re * z.re - p->im * z.im;
    p->im = p_re * z.im + p->im * z.re;
}

int main()
{
    Complex z;
    z = one;
    print_c(z);

    make_conjugate(&z);
    printf("1的共轭与自身%s相等。\n",
           (z.re == one.re && z.im == one.im) ? "" : "不");

    puts("每次乘 ω：");
    for (int i = 0; i < 3; i++) {
        z = prod_c(z, omega);
        print_c(z);
    }

    puts("每次乘 i：");
    for (int i = 0; i < 4; i++) {
        times_by_c(&z, I);
        print_c(z);
    }

    return 0;
}
