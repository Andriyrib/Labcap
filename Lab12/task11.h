#include <stdio.h>
#include <math.h>

void processFile(FILE* file) {
    double maxPrecision = 0.0;
    double value;
    char delimiter = ',';

    // Пошук максимальної точності
    while (fscanf(file, "%lf%c", &value, &delimiter) != EOF) {
        int precision = 0;
        char* ptr = strchr(strchr("%lf%c", '.') + 1, '.'); // Пошук другої крапки
        if (ptr != NULL) {
            precision = strlen(ptr + 1); // Знаходимо точність числа
            if (precision > maxPrecision) {
                maxPrecision = precision; // Оновлюємо максимальну точність
            }
        }
    }

    // Повертаємо позицію на початок файлу
    fseek(file, 0, SEEK_SET);

    // Заміна від'ємних чисел та запис до файлу
    while (fscanf(file, "%lf%c", &value, &delimiter) != EOF) {
        if (value < 0) {
            fprintf(file, "%.lf", fabs(value)); // Запис модуля числа
        }
        else {
            fprintf(file, "%.lf", value); // Запис додатного числа
        }

        if (delimiter == '\n' || delimiter == EOF) {
            fprintf(file, "\n"); // Додавання роздільника рядку
        }
        else {
            fprintf(file, ","); // Додавання коми
        }
    }
}

int main() {
    FILE* file = fopen("input.txt", "r+");

    if (file == NULL) {
        printf("Помилка відкриття файлу.\n");
        return 1;
    }

    processFile(file);

    fclose(file);

    return 0;
}