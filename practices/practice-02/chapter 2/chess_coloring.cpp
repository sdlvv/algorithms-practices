
// Часть 2.
// (4) Шахматная доска 8х8 двумя символами.

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main () {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    char black = ' ';
    char white = ' ';

    std::cin >> black;
    std::cout << "Введите символ для черных: \n"; std::cin >> black;

    std::cin >> white;
    std::cout << "Введите символ для белых: \n"; std::cin >> white;

    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {

        }
    }
    if ((i + j) % 2 == 0) {
        std::cout << black << " ";
    } else {
        std::cout << white << " ";
    }
}
