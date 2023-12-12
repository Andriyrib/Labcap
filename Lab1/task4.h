#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>


int main(void) {
    const long double m1 = 42e3;
    const long double m2 = 26e3;
    const long double gamma = 6.673e-11L;
    const long double r = 15.;
   
    long double f = gamma * m1 * m2 / (r * r);

    printf("F = %Le\n", f);
}