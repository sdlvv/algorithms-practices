#include <iostream>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    // функуия: y = 3x - 5, табулирование функции на отрезке [0, 10] с шагом h = 1.
        int x_start = 0;
        int x_end = 10;
        int h = 1;

        // шапка таблицы
        std::cout << std::setw(5) << "X" << " | " << std::setw(8) << "Y" << std::endl;
        std::cout << "-------------------------" << std::endl;

        for (int x = x_start; x <= x_end; x += h) {
            int y = 3 * x - 5;

            std::cout << std::setw(5) << x << " | " << std::setw(8) << y << std::endl;
        }
        return 0;
    }