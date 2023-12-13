#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(double** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void freeMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    srand(time(NULL)); // Ініціалізуємо генератор випадкових чисел

    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Виділення пам'яті для двовимірного масиву
    double** matrix = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (double*)malloc(cols * sizeof(double));
    }

    // Заповнення матриці випадковими числами
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = (double)(rand() % 100) / 10.0; // Для прикладу генеруємо числа від 0 до 9.9
        }
    }

    // Вивід матриці на екран
    printf("Initial matrix:\n");
    printMatrix(matrix, rows, cols);

    // Знаходження рядка з найменшим за модулем елементом
    int minRow = -1;
    double minElement = __DBL_MAX__;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (abs(matrix[i][j]) < minElement) {
                minElement = abs(matrix[i][j]);
                minRow = i;
            }
        }
    }

    // Видалення рядка з найменшим за модулем елементом
    if (minRow != -1) {
        printf("\nThe string with the smallest modulo element: %d\n", minRow + 1);
        free(matrix[minRow]);
        for (int i = minRow; i < rows - 1; ++i) {
            matrix[i] = matrix[i + 1];
        }
        --rows;
        printf("\nMatrix after row deletion:\n");
        printMatrix(matrix, rows, cols);
    }
    else {
        printf("\nThere is no row with the smallest modulo element\n");
    }

    // Звільнення пам'яті
    freeMatrix(matrix, rows);

    return 0;
}