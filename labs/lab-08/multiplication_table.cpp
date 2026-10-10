#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    int n;

    do {
        std::cout << "Введите число (1-10): ";
        std::cin >> n;
    } while (n < 1 || n > 10);

    std::cout << "Таблица умножения для числа " << n << ":" << std::endl;
    for (int i = 1; i <= 10; i++) {
        std::cout << n << " * " << i << " = " << i << std::endl;
    }
    return 0;
}