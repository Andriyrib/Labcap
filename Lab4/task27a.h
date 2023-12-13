#include <stdio.h>
#include <math.h>

double calculatePi(double epsilon) {
    double sum = 0.0;
    double term = 0.0;
    int k = 1;

    do {
        term = 1.0 / (k * k);
        sum += term;
        k++;
    } while (term > epsilon);

    return sqrt(sum * 6);
}

int main() {
    double epsilon;

    printf("??????? ???????? ?: ");
    scanf("%lf", &epsilon);

    double pi = calculatePi(epsilon);
    printf("???????? ????? ?: %.10f\n", pi);

    return 0;
}