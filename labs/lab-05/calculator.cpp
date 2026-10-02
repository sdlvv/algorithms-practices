#include <iostream>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif
#include <cmath> // Для std::pow и std::sqrt

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    double num1 = 0, num2 = 0;
    char operation;
    double result = 0;
    bool valid = true;

    std::cout << "=== РАСШИРЕННЫЙ КАЛЬКУЛЯТОР ===" << std::endl;
    std::cout << "Доступные операции:" << std::endl;
    std::cout << "  + , - , * , / , %" << std::endl;
    std::cout << "  ^ (возведение в степень: num1 ^ num2)" << std::endl;
    std::cout << "  v (квадратный корень: v(num1))" << std::endl;
    std::cout << "  p (процент: num2% от num1)" << std::endl << std::endl;

    std::cout << "Введите первое число: ";
    std::cin >> num1;

    std::cout << "Введите операцию (+, -, *, /, %, ^, v, p): ";
    std::cin >> operation;

    // Для квадратного корня второе число не требуется
    if (operation != 'v') {
        std::cout << "Введите второе число: ";
        std::cin >> num2;
    }

    // Вычисления
    if (operation == '+') {
        result = num1 + num2;
    } else if (operation == '-') {
        result = num1 - num2;
    } else if (operation == '*') {
        result = num1 * num2;
    } else if (operation == '/') {
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            valid = false;
        }
    } else if (operation == '%') {
        int int1 = static_cast<int>(num1);
        int int2 = static_cast<int>(num2);
        if (int2 != 0) {
            result = int1 % int2;
        } else {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            valid = false;
        }
    } else if (operation == '^') {
        result = std::pow(num1, num2);
    } else if (operation == 'v') {
        if (num1 >= 0) {
            result = std::sqrt(num1);
        } else {
            std::cout << "Ошибка: извлечение корня из отрицательного числа!" << std::endl;
            valid = false;
        }
    } else if (operation == 'p') {
        // num2% от числа num1 (например: 15% от 200 = 30)
        result = num1 * (num2 / 100.0);
    } else {
        std::cout << "Ошибка: неизвестная операция!" << std::endl;
        valid = false;
    }

    // Вывод результата
    if (valid) {
        std::cout << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        if (operation == 'v') {
            std::cout << "sqrt(" << num1 << ") = " << result << std::endl;
        } else if (operation == 'p') {
            std::cout << num2 << "% от " << num1 << " = " << result << std::endl;
        } else {
            std::cout << num1 << " " << operation << " " << num2 << " = " << result << std::endl;
        }
    }

    return 0;
}