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

    std::cout << "=== Размеры типов данных ===" << std::endl;
    std::cout << "bool:       " << sizeof(bool) << " байт" << std::endl;
    std::cout << "char:       " << sizeof(char) << " байт" << std::endl;
    std::cout << "short:      " << sizeof(short) << " байт" << std::endl;
    std::cout << "int:        " << sizeof(int) << " байт" << std::endl;
    std::cout << "long:       " << sizeof(long) << " байт" << std::endl;
    std::cout << "long long:  " << sizeof(long long) << " байт" << std::endl;
    std::cout << "float       " << sizeof(float) << " байт" << std::endl;
    std::cout << "double:     " << sizeof(double) << " байт" << std::endl;

    return 0;
}
