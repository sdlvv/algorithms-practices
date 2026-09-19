
// Часть 1.
// (5) Разложение числа на цифры и вычисление их суммы.

#include <iostream>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    long long n;
    std::cout << "Введите целое число: ";

    if (!(std::cin >> n)) {
        std::cout << "Ошибка ввода.\n";
        return 1;
    }

    long long temp = std::abs(n); // abs(n) на случай, если пользователь подаст отрицательное число (модуль)
    int sum = 0;

    while (temp > 0) {
        int digit = temp % 10; // чтобы получить последную цифру числа
        sum += digit;
        temp /= 10;
    }
    std::cout << "Сумма цифр: " << sum << std::endl;

    return 0;
}