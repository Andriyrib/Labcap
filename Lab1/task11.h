#include <iostream>
#include <string>

int main() {
    // Ініціалізація двох рядків
    std::string str1 = "hello";
    std::string str2 = "world!";

    // Виведення рядків з розділенням комою та пробілом, та додавання трьох окличних знаків
    std::cout << str1 << ", " << str2 << " !!!" << std::endl;

    return 0;
}