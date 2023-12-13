#include <stdio.h>

#define N 3 // Розмірність матриці (кількість рядків)
#define M 4 // Кількість елементів у рядку

void swapRows(int matrix[N][M], int row1, int row2) {
    for (int i = 0; i < M; ++i) {
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

int main() {
    int matrix[N][M] = { {1, -2, 3, -4},
                        {-5, 6, -7, 8},
                        {9, -10, 11, 12} };

    int firstNegRow = -1; // Індекс першого рядка з негативними елементами
    int lastNegRow = -1; // Індекс останнього рядка з негативними елементами

    // Знаходимо перший та останній рядок з негативними елементами
    for (int i = 0; i < N; ++i) {
        int negativeCount = 0;
        for (int j = 0; j < M; ++j) {
            if (matrix[i][j] < 0) {
                ++negativeCount;
            }
        }

        if (negativeCount == M) {
            if (firstNegRow == -1) {
                firstNegRow = i;
            }
            lastNegRow = i;
        }
    }

    if (firstNegRow != -1 && lastNegRow != -1) {
        swapRows(matrix, firstNegRow, lastNegRow); // Поміняти рядки, якщо вони знайдені

        // Вивести матрицю після заміни рядків
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Рядки не знайдені\n");
    }

    return 0;
}