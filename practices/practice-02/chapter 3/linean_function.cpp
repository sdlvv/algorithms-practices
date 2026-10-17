#include <iostream>
#include <iomanip> // только для красивой таблицы
#ifdef _WIN32
#include <windows.h>
#endif

double f(double x) {
    return x * x * x - 3.0 * x + 1.0;
}

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    double a, b, h;
    std::cout << "Введите a, b и шаг h: ";
    if (!(std::cin >> a >> b >> h) || h <= 0.0 || a > b) {
        std::cout << "Ошибка ввода!\n";
        return 1;
    }

    // количество шагов
    int steps = (b - a) / h;


    double min_y = f(a);
    double max_y = f(a);
    double prev_y = f(a);
    int sign_changes = 0;


    std::cout << "\n    x         f(x)\n";
    std::cout << "------------------------\n";
    std::cout << std::fixed << std::setprecision(4);


    for (int i = 0; i <= steps; ++i) {

        double x = a + i * h;
        if (i == steps) {
            x = b;
        }

        double y = f(x);


        std::cout << std::setw(10) << x << std::setw(12) << y << '\n';

        // ищем минимум и максимум
        if (y < min_y) min_y = y;
        if (y > max_y) max_y = y;

        // простая смена знака
        if (i > 0) {
            if (prev_y * y < 0.0) {
                sign_changes++;
            }
            prev_y = y;
        }
    }

    // итоги
    std::cout << "------------------------\n";
    std::cout << "Минимум f(x):  " << min_y << '\n';
    std::cout << "Максимум f(x):  " << max_y << '\n';
    std::cout << "Смен знака:    " << sign_changes << '\n';

    return 0;
}