#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int** data;
    int rows;
    int cols;
} Matrix;

// Функція для виділення пам'яті для матриці
void allocateMatrix(Matrix* matrix, int rows, int cols) {
    matrix->rows = rows;
    matrix->cols = cols;

    matrix->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        matrix->data[i] = (int*)malloc(cols * sizeof(int));
    }
}

// Функція для звільнення пам'яті, виділеної для матриці
void freeMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; ++i) {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

// Функція для обчислення суми всіх матриць
Matrix sumMatrices(Matrix* matrices, int numMatrices) {
    Matrix sum;
    allocateMatrix(&sum, matrices[0].rows, matrices[0].cols);

    for (int i = 0; i < sum.rows; ++i) {
        for (int j = 0; j < sum.cols; ++j) {
            sum.data[i][j] = 0;
            for (int k = 0; k < numMatrices; ++k) {
                sum.data[i][j] += matrices[k].data[i][j];
            }
        }
    }

    return sum;
}

int main() {
    int numMatrices;
    printf("Введіть кількість матриць: ");
    scanf("%d", &numMatrices);

    Matrix* matrices = (Matrix*)malloc(numMatrices * sizeof(Matrix));

    // Введення матриць
    for (int i = 0; i < numMatrices; ++i) {
        int rows, cols;
        printf("Введіть кількість рядків і стовпців для матриці %d: ", i + 1);
        scanf("%d %d", &rows, &cols);

        allocateMatrix(&matrices[i], rows, cols);

        printf("Введіть елементи матриці %d:\n", i + 1);
        for (int j = 0; j < rows; ++j) {
            for (int k = 0; k < cols; ++k) {
                scanf("%d", &matrices[i].data[j][k]);
            }
        }
    }

    // Перевірка, чи всі матриці однакового розміру
    int equalSize = 1;
    for (int i = 1; i < numMatrices; ++i) {
        if (matrices[i].rows != matrices[0].rows || matrices[i].cols != matrices[0].cols) {
            equalSize = 0;
            break;
        }
    }

    if (equalSize) {
        // Обчислення та виведення суми матриць
        Matrix sum = sumMatrices(matrices, numMatrices);
        printf("Сума всіх матриць:\n");
        for (int i = 0; i < sum.rows; ++i) {
            for (int j = 0; j < sum.cols; ++j) {
                printf("%d\t", sum.data[i][j]);
            }
            printf("\n");
        }
        freeMatrix(&sum);
    }
    else {
        printf("Матриці мають різний розмір. Неможливо обчислити суму.\n");
    }

    // Звільнення пам'яті
    for (int i = 0; i < numMatrices; ++i) {
        freeMatrix(&matrices[i]);
    }
    free(matrices);

    return 0;
}