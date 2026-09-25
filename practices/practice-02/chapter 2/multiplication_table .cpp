
//  Часть 2.
// (1) Таблица умножения 9x9 с выравниваем столбцов

#include <iostream>
#include <iomanip> // Input/Output Manipulators C++ для управления форматированием потоков ввода и вывода без ручной возни со склеиванием строк
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    for (int i = 1; i <= 9; ++i) { // отвечает за вертикаль - номера строк, делает ровно 9 шагов, каждый раз фиксируя текущий множитель строки i
        for (int j = 1; j <= 9; ++j) { // отвечает за горизонталь - столбцы внутри строки, i * j вычисляет произведение текущей строки на текущий столбец
            std::cout << std::setw(4) << i * j; // set width - установить ширину (4 символа);
        }
        std::cout << '\n';
    }
    return 0;
}
