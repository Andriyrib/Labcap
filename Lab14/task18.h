#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000  // Максимальна довжина рядка

int main() {
    FILE* inputFile, * outputFile;
    inputFile = fopen("input.txt", "r"); // Відкриття файлу для читання

    if (inputFile == NULL) {
        perror("Помилка при відкритті файлу");
        return -1;
    }

    char line[MAX_LENGTH];
    int minLength = MAX_LENGTH + 1;  // Початкове значення для мінімальної довжини
    int maxLength = 0;  // Початкове значення для максимальної довжини

    // Знаходження мінімальної та максимальної довжини рядків
    while (fgets(line, sizeof(line), inputFile)) {
        int length = strlen(line);
        if (length < minLength) {
            minLength = length;
        }
        if (length > maxLength) {
            maxLength = length;
        }
    }

    // Повторне відкриття файлу для переносу покажчика на початок
    fseek(inputFile, 0, SEEK_SET);

    // Відкриття файлу для запису результуючих рядків
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Помилка при відкритті файлу для запису");
        return -1;
    }

    // Запис мінімальних та максимальних рядків у новий файл
    while (fgets(line, sizeof(line), inputFile)) {
        int length = strlen(line);
        if (length == minLength || length == maxLength) {
            fputs(line, outputFile);
        }
    }

    // Закриття файлів
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}