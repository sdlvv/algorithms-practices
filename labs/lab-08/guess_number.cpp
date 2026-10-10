#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    srand(time(0));  // инициализация генератора случайных чисел
    int secret = rand() % 100 + 1;  // число от 1 до 100
    int guess;
    int attempts = 0;

    std::cout << "=== УГАДАЙ ЧИСЛО ===" << std::endl;
    std::cout << "Я загадал число от 1 до 100. Попробуй угадать!" << std::endl;


    while (guess != secret) {
        std::cin >> guess;

        if (guess > secret) {
            std::cout << "Меньше!" << std::endl;
        } else if (guess < secret) {
            std::cout << "Больше!" << std::endl;
        }

        if (guess == secret) {
            std::cout << "Угадал!" << std::endl;
            std::cout << "Загаданное число: " << secret << std::endl;
            std::cout << "Количество попыток: " << attempts << std::endl;
        }
        ++attempts;
    }

    return 0;
}