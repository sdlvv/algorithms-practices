#include <iostream>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    std::cout << "    ";
    for (int top = 1; top <= 10; top++) { // верхняя шапка с числами от 1 до 10
        std::cout << std::setw(4) << top;
    }
    std::cout << std::endl;
    for (int i = 1; i <= 10; i++) {
        std::cout << std::setw(2) << i << " "; // номер строки в начале

        for (int j = 1; j <= 10; j++) {
            std::cout << std::setw(4) << (i * j);
        }
        std::cout << std::endl;
    }
    return 0;
}