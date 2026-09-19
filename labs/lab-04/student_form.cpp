#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <iomanip>
#include <string>

int main() {
    #ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    // Объявление переменных для хранения данных
    std::string firstName;    // Имя
    std::string lastName;     // Фамилия
    int age;                  // Возраст
    double height;            // Рост в метрах
    double weight;            // Вес в килограммах
    std::string category; // Категория веса
    int course;               // Курс обучения

    std::cout << "=== АНКЕТА СТУДЕНТА ===" << std::endl;
    std::cout << std::endl;

    std::cout << "Введите имя: ";
    std::cin >> firstName;

    std::cout << "Введите фамилию: ";
    std::cin >> lastName;

    std::cout << "Введите возраст: ";
    std::cin >> age;

    std::cout << "Введите рост (в метрах, например 1.75): ";
    std::cin >> height;

    std::cout << "Введите вес (в кг): ";
    std::cin >> weight;

    std::cout << "Введите курс обучения (1-4): ";
    std::cin >> course;

    double bmi = weight / (height * height); // Вычисление индекса массы тела (ИМТ)

    if (bmi < 18.5) {                        // Категория веса
        category = "Недостаточный вес";
    } else if (bmi < 25.0) {
        category = "Норма";
    } else if (bmi < 30.0) {
        category = "Избыточный вес";
    } else {
        category = "Ожирение";
    }

    std::cout << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;
    std::cout << "         КАРТОЧКА СТУДЕНТА" << std::endl;
    std::cout << std::setfill('=') << std::setw(40) << "" << std::endl;

    std::cout << std::setfill(' ');  // Возврат пробела в качестве заполнителя

    std::cout << std::left;

    std::cout << "Фамилия:    " << lastName << '\n';
    std::cout << "Имя:        " << firstName << '\n';
    std::cout << "Возраст:    " << age << " лет\n";
    std::cout << "Курс:       " << course << '\n';
    std::cout << "Рост:       " << std::fixed << std::setprecision(2) << height << " м\n";
    std::cout << "Вес:        " << std::fixed << std::setprecision(1) << weight << " кг\n";
    std::cout << "ИМТ:        " << std::fixed << std::setprecision(1) << bmi << '\n';
    std::cout << "Категория:  " << category << '\n';

    std::cout << std::setfill('-') << std::setw(40) << "" << std::endl;

    return 0;
}
