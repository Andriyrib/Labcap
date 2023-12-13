#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>   
#include <inttypes.h> 

uint64_t subfact(unsigned n) {

    if (n < 2) {
        return 1 - n;
    }
    return subfact(n - 1) * n + (n % 2 == 0 ? 1 : -1);
}

int main(void) {
    unsigned n;
    scanf("%u", &n);

    printf("!%u = %" PRIu64 "\n", n, subfact(n));
}