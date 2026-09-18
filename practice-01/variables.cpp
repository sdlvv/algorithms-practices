#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    // настройка кодировки консоли под windows
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    // объявление переменных разных типов
    std::string name;
    int age;
    double height;
    char initial;
    bool isStudent;

    // ввод данных
    std::cout << "=== Анкета ===" << std::endl;
    std::cout << "Введите ваше имя: ";
    std::getline(std::cin, name);

    std::cout << "Введите ваш возраст: ";
    std::cin >> age;

    std::cout << "Введите ваш рост (в метрах): ";
    std::cin >> height;

    initial = name[0]; // первая буква имени
    isStudent = (age >= 16 && age<= 25);

    // вывод результатов
    std::cout << std::endl;
    std::cout << "=== Результаты ===" << std::endl;
    std::cout << "Имя: " << name << std::endl;
    std::cout << "Инициал " << initial << std::endl;
    std::cout << "Возраст: " << age << " лет" << std::endl;
    std::cout << "Рост: " << height << " м" << std::endl;
    std::cout << "Студент: " << (isStudent ? "Да" : "Нет") << std::endl;
    std::cout << "Через 10 лет вам будет: " << (age + 10) << " лет" << std::endl;

    return 0;
}