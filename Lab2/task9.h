#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main(void) {
    double a, b, c;
    double r;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &r);

    double area = r * r * (1. / tan(a / 2.) + 1. / tan(b / 2.) + 1. / tan(c / 2.));

    printf("area = %lf\n", area);
}