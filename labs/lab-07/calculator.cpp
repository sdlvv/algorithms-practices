#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    int choise;
    double a, b, result;

do {
    std::cout << "=== КАЛЬКУЛЯТОР ===" << std::endl;
    std::cout << "1. Сложение (+)" << std::endl;
    std::cout << "2. Вычитание (-)" << std::endl;
    std::cout << "3. Умножение (*)" << std::endl;
    std::cout << "4. Деление (/)" << std::endl;
    std::cout << "5. Остаток от деления (%)" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Выберите операцию: ";
    std::cin >> choise;

    switch (choise) {
        case 1:
            std::cout << "Введите два числа: ";
            std::cin >> a >> b;
            result = a + b;
            std::cout << a << " + " << b << " = " << result << std::endl;
            break;

        case 2:
            std::cout << "Введите два числа: ";
            std::cin >> a >> b;
            result = a - b;
            std::cout << a << " - " << b << " = " << result << std::endl;
            break;

        case 3:
            std::cout << "Введите два числа: ";
            std::cin >> a >> b;
            result = a * b;
            std::cout << a << " * " << b << " = " << result << std::endl;
            break;

        case 4:
            std::cout << "Введите два числа: ";
            std::cin >> a >> b;
            if (b == 0) {
                std::cout << "Ошибка: деление на ноль!" << std::endl;
            } else {
                result = a / b;
                std::cout << a << " / " << b << " = " << result << std::endl;
            }
            break;

        case 5:
            int c, d;
            std::cout << "Введите два числа: ";
            std::cin >> c >> d;
            result = c % d;
            std::cout << c << " % " << d << " = " << result << std::endl;
            break;

        case 0:
            std::cout << "До свидания!" << std::endl;
            break;

        default:
            std::cout << "Неверный выбор!" << std::endl;
            break;
    }
} while (choise != 0);
    return 0;
}