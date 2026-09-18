#include <iostream>

int main() {
#ifdef _WIN32
    system("chcp 65001 > nul");  // Переключение консоли на кодировку UTF-8 (только Windows)
#endif

    std::cout << "Hello, World!" << std::endl;
    std::cout << "Меня зовут Зелимхан Сайдулаев" << std::endl;
    std::cout << "Я изучаю C++!" << std::endl;
    return 0;
}
