
// Часть 1. Одиночные циклы
// (3) Поиск наибольшего и наименьшего из вводимых значений без массива.

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    int first;
    std::cout << "Введите числа (0 - для завершения)" << '\n';

    if (!(std::cin >> first) || first == 0) {
        std::cout << "Последовательность пуста." << '\n';
        return 0;
    }

    int min_val = first;
    int max_val = first;

    int current;
    while (std::cin >> current && current != 0) {
        if (current > max_val) {
            max_val = current;
        }
        if (current < min_val) {
            min_val = current;
        }
    }

    std::cout << "Минимум: " << min_val << '\n';
    std::cout << "Максимум: " << max_val << '\n';

    return 0;
}

