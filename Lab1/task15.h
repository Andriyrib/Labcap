#include <iostream>
using namespace std;

int main() {
    double m, v, kinetic_energy;

    // Введення маси тіла (у кілограмах) та його швидкості (у м/с)
    cout << "mass: ";
    cin >> m;

    cout << "speed: ";
    cin >> v;

    // Обчислення кінетичної енергії за формулою: K = 0.5 * m * v^2
    kinetic_energy = 0.5 * m * v * v;

    // Виведення результату
    cout << "Kinetic energy of the body: " << kinetic_energy << " joules" << endl;

    return 0;
}