#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
    double x;
    scanf("%lf", &x);
    double y = cos(x);
    printf("%lf\n", y);
}