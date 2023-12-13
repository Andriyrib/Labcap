#include <stdio.h>
#include <string.h>

#define MAX_TOYS 100

// Структура для зберігання даних про іграшки
typedef struct {
    char name[50];
    double price;
    int minAge;
    int maxAge;
} Toy;

// Функція для пошуку іграшок для дітей відповідного віку з певною вартістю
void findToysForAgeAndPrice(Toy toys[], int n, int targetAge, double maxPrice) {
    int foundCount = 0;
    double totalCost = 0;

    printf("Toys for children %d years, the value of which does not exceed %.2lf грн:\n", targetAge, maxPrice);

    for (int i = 0; i < n; ++i) {
        if (toys[i].minAge <= targetAge && toys[i].maxAge >= targetAge && totalCost + toys[i].price <= maxPrice) {
            printf("%s - %.2lf грн\n", toys[i].name, toys[i].price);
            totalCost += toys[i].price;
            foundCount++;

            if (foundCount >= 2) {
                break;
            }
        }
    }

    if (foundCount == 0) {
        printf("No matching toys found.\n");
    }
}

int main() {
    // Відкриття файлу
    FILE* file = fopen("toys.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Зчитування даних з файлу
    Toy toys[MAX_TOYS];
    int toysCount = 0;

    while (fscanf(file, "%s %lf %d %d", toys[toysCount].name, &toys[toysCount].price,
        &toys[toysCount].minAge, &toys[toysCount].maxAge) == 4) {
        toysCount++;
    }

    fclose(file);

    // Пошук іграшок для дітей з певним віком та вартістю
    int targetAge = 4;  // Змініть це значення на вік, який вам потрібний
    double maxPrice = 100;  // Змініть це значення на бажану максимальну вартість

    findToysForAgeAndPrice(toys, toysCount, targetAge, maxPrice);

    return 0;
}