#include <stdio.h>
#include <math.h>


double eReLu(double a, double x) {
    if (x < 0) {
        return a * (exp(x) - 1);
    }
    else {
        return 0;
    }
}

double derivative_eReLu(double a, double x) {
    if (x < 0) {
        return a * exp(x);
    }
    else {
        return 0;
    }
}

int main() {
    double a = 2.0; 
    double x = -1.5; 

    double result = eReLu(a, x);
    double derivative = derivative_eReLu(a, x);

    printf("eReLu(%.2f, %.2f) = %.2f\n", a, x, result);
    printf("Derivative of eReLu(%.2f, %.2f) = %.2f\n", a, x, derivative);

    return 0;
}