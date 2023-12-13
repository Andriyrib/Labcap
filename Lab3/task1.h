#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void) {
    unsigned n;
    scanf("%u", &n);

    unsigned n0 = n % 10;
    n /= 10;
    unsigned n1 = n % 10;
    n /= 10;
    unsigned n2 = n;

    unsigned digit_sum = n0 + n1 + n2;

    unsigned rev = n0 * 100 + n1 * 10 + n2;

    printf("a) %u, %u, %u\nb) %u\nc) %u\n", n0, n1, n2, digit_sum, rev);
}