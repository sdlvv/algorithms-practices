#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    // найти первое число в диапазоне [100; 200], кратное 17.
    std::cout << "--- break --- \n";
    int start = 100, end = 200;
    int divisor = 17;
    int first_found = -1;

    for (int i = start; i <= end; i++) {
        if (i % divisor == 0) {
            first_found = i;
            break;
        }
    }
    if (first_found != -1) {
        std::cout << "Первое число, кратное " << divisor << ": " << first_found << "\n\n";
    }
   // вывести только нечетные числа из [1; 15], пропуская четные.
    std::cout << "--- continue ---\n";
    std::cout << "Нечетные числа: ";

    for (int i = 1; i <= 15; ++i) {
        if (i % 2 == 0) {
            continue;
        }
        std::cout << i << " ";
    }
    std::cout << "\n\n";

   // найти первое совпадение произведения i * j == target в таблице 10x10.
    std::cout << "--- Выход из вложенного цикла через флаг ---\n";
    int target = 42;
    bool found = false;
    int found_i = -1, found_j = -1;

    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            if (i * j == target) {
                found = true;
                found_i = i;
                found_j = j;
                break; // завершает ТОЛЬКО внутренний цикл по j
            }
        }

        // проверяем флаг во внешнем цикле: если цель найдена, выходим и из него
        if (found) {
            break;
        }
    }

    if (found) {
        std::cout << "Цель " << target << " найдена: i = " << found_i << ", j = " << found_j << '\n';
    } else {
        std::cout << "Элемент не найден.\n";
    }

    return 0;
}


