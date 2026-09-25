#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    int n;          // высота треугольника
    char symbol;    // символ для рисования

    std::cout << "Введите высоту треугольника: ";
    std::cin >> n;
    std::cout << "Введите символ: ";
    std::cin >> symbol;

    if (n <= 0) {
        std::cout << "Высота должна быть положительным числом!" << std::endl;
        return 1;
    }

    // внешний цикл отвечает за строки
    for (int i = 1; i <= n; i++) {
        // внутренний цикл печатает i символов в строке i
        for (int j = 1; j <= i; j++) {
            std::cout << symbol;
        }
        std::cout << std::endl;   // переход на новую строку
    }

    return 0;
}