#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


double a(double x) {
    double x2 = x * x;
    return x2 * x2 + 2 * x2 + 1;
}


double b(double x) {
    double x2 = x * x; 
    x += 1.; 
    return (x2 + x) * x2 + x; 
}


double e(double x) {
    x *= 2.; 
    double x2 = x * x; 
    x += 1.; 
    return (x2 + x) * x2 + x; 
}


double e_geometric(double x) {
    x *= 2.;
    double x2 = x * x;
    return (x2 * x2 * x - 1.) / (x - 1.);
}

int main(void) {
    double x;
    scanf("%lf", &x);
   
    printf("a(x) = %lf\n", a(x));

    printf("b(x) = %lf\n", b(x));

    printf("e(x) = %lf\n", e(x));
    printf("e_geometric(x) = %lf\n", e_geometric(x));
}