#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the number of numbers: ");
    scanf("%d", &n);

    int count = 0;
    int k = n / 2;

    int numbers[n];
    printf("Enter %d whole numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < n - k; i++) {
        for (int j = i + 1; j <= i + k && j < n; j++) {
            int product = numbers[i] * numbers[j];
            int sqrt_product = sqrt(product);

            if (sqrt_product * sqrt_product == product) {
                count++;
            }
        }
    }

    printf("Number of complete squares among pairs: %d\n", count);

    return 0;
}