
// Часть 2.
// (3) Вывод равнобедренного треугольника

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main () {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
    int height = 5;
    char symbol;

    std::cout << "Введите символ: \n";
    std::cin >> symbol;

    for (int i = 0; i < height; i++) {
        // Печать пробелов перед звездочками
        for (int j = 0; j < height - i - 1; j++) {
            std::cout << " ";
        }
        // Печать звездочек
        for (int k = 0; k < 2 * i + 1; k++) {
            std::cout << symbol;
        }
        std::cout << std::endl;
    }

    return 0;
}
