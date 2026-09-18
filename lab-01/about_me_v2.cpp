#include <iostream>
#ifdef _WIN32
#include <windows.h>
using namespace std;
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
    cout << "================================" << endl;
    cout << "       Информация о студенте    " << endl;
    cout << "================================" << endl;

    // Личные данные
    cout << endl;
    cout << "Имя: Зелимхан" << endl;
    cout << "Группа: ИСПкр-252" << endl;
    cout << "Возраст: 17" << endl;

    // Увлечения
    cout << endl;
    cout << "Мои увлечения:" << endl;
    cout << "  1. Программировние" << endl;
    cout << "  2. Игры" << endl;
    cout << "  3. Фильмы, сериалы" << endl;

    // Мотивация
    cout << endl;
    cout << "Почему я изучаю программирование: " << endl;
    cout << "мне нравится инженерия, логика и системы; хочу стать разработчиком" << endl;

    cout << endl;
    cout << "================================" << endl;

    return 0;
}

