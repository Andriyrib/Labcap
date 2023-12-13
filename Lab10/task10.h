#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNTRIES 50

// Структура для зберігання інформації про державу
typedef struct {
    char name[50];
    double population;  // Населення в мільйонах
    double area;        // Площа
} Country;

// Функція для пошуку держави з мінімальною щільністю населення
void findCountryWithMinDensity(Country countries[], int n) {
    double minDensity = countries[0].population / countries[0].area;
    int minIndex = 0;

    for (int i = 1; i < n; ++i) {
        double density = countries[i].population / countries[i].area;
        if (density < minDensity) {
            minDensity = density;
            minIndex = i;
        }
    }

    printf("The state with the minimum population density: %s\n", countries[minIndex].name);
}

int main() {
    int numCountries;
    printf("Enter the number of states: ");
    scanf("%d", &numCountries);

    if (numCountries <= 0 || numCountries > MAX_COUNTRIES) {
        printf("Invalid value for number of states\n");
        return 1;
    }

    Country countries[MAX_COUNTRIES];
    printf("Enter data about states (name, population in millions, area):\n");
    for (int i = 0; i < numCountries; ++i) {
        printf("State %d: ", i + 1);
        scanf("%s %lf %lf", countries[i].name, &countries[i].population, &countries[i].area);
    }

    findCountryWithMinDensity(countries, numCountries);

    return 0;
}