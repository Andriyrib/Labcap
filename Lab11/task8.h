#include <stdio.h>

void createFileG(FILE* fileF, FILE* fileG, int n) {
    int value;
    int max = 0;
    int count = 0;

    while (fscanf(fileF, "%d", &value) != EOF) {
        if (value > max) {
            max = value;
        }

        count++;

        if (count == n) {
            fprintf(fileG, "%d\n", max);
            max = 0;
            count = 0;
        }
    }

    // Якщо кількість компонент файлу не ділиться на n
    if (count != 0) {
        fprintf(fileG, "%d\n", max);
    }
}

int main() {
    FILE* fileF = fopen("F.txt", "r");
    FILE* fileG = fopen("G.txt", "w");

    if (fileF == NULL || fileG == NULL) {
        printf("Помилка відкриття файлу.\n");
        return 1;
    }

    int n = 5; // Змініть це значення на бажану кількість компонент
    createFileG(fileF, fileG, n);

    fclose(fileF);
    fclose(fileG);

    return 0;
}