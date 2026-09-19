#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    int n = {};
    std::cout << "Введите положительное число n: ";
    std::cin >> n;

    // если пользователь введет отрицательное число или 0
    if (n < 1) {
        std::cout << "Введите положительное число!";
        return 1;
    }

    // long long для больших вычислений
    long long sum = {0};
    long long count = {1};

    for (int i = 1; i <= n; i++) {
        sum += i;
        count *= i;
    }

    // базовый тип данных long long занимает ровно 64 бита памяти со знаком, его потолок - n=20 (большее n выдаст неверный результат)
    if (n > 20) {
        std::cout << "Для n > 20 вычисление произведения переполнит 64-битный тип данных и выдаст неверный результат.\n" << std::endl;
    }

    std::cout << "Сумма: \n" << sum << std::endl;
    std::cout << "Произведение: \n" << count << std::endl;

    return 0;

}