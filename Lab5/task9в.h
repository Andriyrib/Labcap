#include <stdio.h>

double calculateElement(int n) {
    if (n <= 2) return 0;
    double v[n + 1];
    v[0] = v[1] = 0;
    v[2] = 3.0 / 2.0;

    for (int i = 3; i <= n; i++) {
        v[i] = (i - 2) / ((i - 3) * (i - 3) + 1.0) * v[i - 1] - v[i - 2] * v[i - 3] + 1;
    }

    return v[n];
}

int main() {
    int index;

    printf("Enter the sequence element index: ");
    scanf("%d", &index);

    double result = calculateElement(index);
    printf("Sequence element with index %d: %.10f\n", index, result);

    return 0;
}