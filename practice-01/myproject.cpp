#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    // настройка кодировки консоли для Windows
    #ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    std::cout << "=== IT-КУРСЫ ===" << std::endl;
    std::cout << std::endl;

    // Объявление переменных разных типов
    std::string courseName; // название курса
    std::string direction; // направление
    std::string technologies; // стек технологий
    double pricePerMonth; // цена за месяц
    int durationMonths; // длительность курса
    int availableSeats; // количество допустных мест
    bool isRecruiting;

    // ввод данных
    std::cout << "Введите название курса: ";
    std::getline(std::cin, courseName);

    std::cout << "Введите направление: ";
    std::getline(std::cin, direction);

    std::cout << "Введите технологии: ";
    std::getline(std::cin, technologies);

    std::cout << "Введите стоимость за месяц (руб): ";
    std::cin >> pricePerMonth;

    std::cout << "Введите длительность курса (мес): ";
    std::cin >> durationMonths;

    std::cout << "Введите количество свободных мест: ";
    std::cin >> availableSeats;

    isRecruiting = (availableSeats > 0);

    // вычисления
    double discount = pricePerMonth * 0.1; // Скидка 10%
    double finalMonthlyPrice = pricePerMonth - discount;
    double totalCost = finalMonthlyPrice * durationMonths;

    // вывод результатов
    std::cout << std::endl;
    std::cout << "=== ИНФОРМАЦИЯ О КУРСЕ ===" << std::endl;
    std::cout << "Название:          " << courseName << std::endl;
    std::cout << "Направление:       " << direction << std::endl;
    std::cout << "Технологии:        " << technologies << std::endl;
    std::cout << "Длительность:      " << durationMonths << " мес." << std::endl;
    std::cout << "Цена за месяц:     " << pricePerMonth << " руб." << std::endl;
    std::cout << "Скидка (10%):      " << discount << " руб." << std::endl;
    std::cout << "Цена со скидкой:   " << finalMonthlyPrice << " руб./мес." << std::endl;
    std::cout << "Свободных мест:    " << availableSeats << " шт." << std::endl;
    std::cout << "Набор открыт:      " << (isRecruiting ? "Да" : "Нет") << std::endl;
    std::cout << "Общая стоимость:   " << totalCost << " руб." << std::endl;

    return 0;
}