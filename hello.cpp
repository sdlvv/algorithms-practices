#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    // настройка кодировки консоли для windows
    #ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Меня зовут Зелимхан" << std::endl;
    std::cout << "Я изучаю C++" << std::endl;
    return 0;
}
