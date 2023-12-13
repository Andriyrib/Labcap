#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
    unsigned a, b, c;
    scanf("%u,%u,%u", &a, &b, &c);
    printf("a) %u\n", a * b * c);

    unsigned long long d, e, f;
    scanf("%llu,%llu,%llu", &d, &e, &f);
    printf("b) %llu\n", d * e * f);
}