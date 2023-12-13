#include <stdio.h>
#include <math.h>

void processFile(FILE* fileF, FILE* fileG) {
    int value;

    while (fscanf(fileF, "%d", &value) != EOF) {
        if (value > 0) {
            double squareRoot = sqrt(value);
            fprintf(fileG, "%d,%.5lf\n", value, squareRoot);
        }
    }
}

int main() {
    FILE* fileF = fopen("F.txt", "r");
    FILE* fileG = fopen("G.txt", "w");

    if (fileF == NULL || fileG == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    processFile(fileF, fileG);

    fclose(fileF);
    fclose(fileG);

    return 0;
}