
// Часть 1.
// (4) Проверка числа на простоту.

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

bool is_prime (long long n) {
    // числа меньше либо равные 1 простыми не являются
    if (n <= 1) {
        return false;
    }

    // двойка - единственное частное простое число
    if (n == 2) {
        return true;
    }

    // все остальные четные числа сразу отсекаются

    if (n % 2 == 0) {
        return false;
    }

    // проверяем только нечетные делители от 3 до sqrt(n)

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false; // нашли делитель - число составное
        }
    }

    return true; // делителей нет - число простое
}

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    long long n;
    std::cout << "Введите число для проверки: ";

    if (!(std::cin >> n)) {
        std::cout << "Ошибка ввода.\n";
        return 1;
    }

    if (is_prime(n)) {
        std::cout << n << " - простое число.\n";
    } else {
        std::cout << n << " - составное число (или <=1).\n";
    }

    return 0;
}
