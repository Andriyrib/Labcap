#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10  // Максимальна кількість вершин багатокутника

// Структура для зберігання координат вершин багатокутника
typedef struct {
    int x;
    int y;
} Point;

// Структура для зберігання інформації про багатокутник
typedef struct {
    int size;  // Кількість вершин у багатокутнику
    Point vertices[MAX_VERTICES];  // Масив вершин багатокутника
} Polygon;

// Функція для введення координат вершин багатокутника
void inputPolygon(Polygon* polygon) {
    printf("Enter the number of vertices of the polygon: ");
    scanf("%d", &polygon->size);

    printf("Enter the coordinates of the vertices in the format x y:\n");
    for (int i = 0; i < polygon->size; ++i) {
        scanf("%d %d", &polygon->vertices[i].x, &polygon->vertices[i].y);
    }
}

// Функція для виведення координат вершин багатокутника
void printPolygon(Polygon polygon) {
    printf("Polygon with %d peaks:\n", polygon.size);
    for (int i = 0; i < polygon.size; ++i) {
        printf("(%d, %d)\n", polygon.vertices[i].x, polygon.vertices[i].y);
    }
}

int main() {
    Polygon myPolygon;
    inputPolygon(&myPolygon);
    printPolygon(myPolygon);

    return 0;
}