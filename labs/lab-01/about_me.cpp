#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
/*
 * Программа: О себе
 * Автор: [Ваше имя]
 * Дата: [Текущая дата]
 * Группа: [Ваша группа]
 */

int main() {
    // настройка кодировки консоли для windows
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
    // Заголовок
    std::cout << "================================" << std::endl;
    std::cout << "       Информация о студенте    " << std::endl;
    std::cout << "================================" << std::endl;

    // Личные данные
    std::cout << std::endl;
    std::cout << "Имя: Зелимхан" << std::endl;
    std::cout << "Группа: ИСПкр-252" << std::endl;
    std::cout << "Возраст: 17" << std::endl;

    // Увлечения
    std::cout << std::endl;
    std::cout << "Мои увлечения:" << std::endl;
    std::cout << "  1. Программировние" << std::endl;
    std::cout << "  2. Игры" << std::endl;
    std::cout << "  3. Фильмы, сериалы" << std::endl;

    // Мотивация
    std::cout << std::endl;
    std::cout << "Почему я изучаю программирование: " << std::endl;
    std::cout << "мне нравится инженерия, логика и системы; хочу стать разработчиком" << std::endl;

    std::cout << std::endl;
    std::cout << "================================" << std::endl;

    return 0;
}

