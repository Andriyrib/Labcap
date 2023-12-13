#include <stdio.h>
#include <math.h>

double calculateArcsin(double x, double epsilon) {
    double sum = 0;
    double term = x;
    int n = 1;

    while (fabs(term) >= epsilon) {
        sum += term;
        term *= ((2 * n - 1) * x * x) / ((2 * n) * (2 * n + 1));
        n++;
    }

    return sum;
}

int main() {
    double x, epsilon;

    printf("Enter the value x (-1 < x < 1): ");
    scanf("%lf", &x);

    printf("Enter a precision value ?: ");
    scanf("%lf", &epsilon);

    if (fabs(x) >= 1) {
        printf("Invalid value x. |x| should be less 1.\n");
        return 1;
    }

    double result = calculateArcsin(x, epsilon);
    printf("Value arcsin(%.2f) with precision %.10f: %.10f\n", x, epsilon, result);

    return 0;
}