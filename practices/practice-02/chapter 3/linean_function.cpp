#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <iomanip>
#include <cmath>
#include <string>

// Исследуемая функция: f(x) = x^3 - 3*x + 1
double f(double x) {
    return std::pow(x, 3) - 3.0 * x + 1.0;
}

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
    double a = 0.0, b = 0.0, h = 0.0;

    std::cout << "Введите a, b и шаг h: ";
    if (!(std::cin >> a >> b >> h) || h <= 0.0 || a > b) {
        std::cerr << "Ошибка: некорректные границы отрезка или шаг.\n";
        return 1;
    }

    // количество шагов вычисляем через округление
    int steps = static_cast<int>(std::round((b - a) / h));

    // инициализация экстремумов значением в первой точке
    double y0 = f(a);
    double min_y = y0;
    double max_y = y0;
    double prev_y = y0;
    int sign_changes = 0;

    // шапка таблицы с выравниванием по левому краю
    std::cout << "\n"
              << std::setw(12) << std::left << "x"
              << std::setw(12) << std::left << "f(x)" << '\n';
    std::cout << std::string(24, '-') << '\n';

    // фиксируем точность вывода чисел с плавающей точкой
    std::cout << std::fixed << std::setprecision(4);

    for (int i = 0; i <= steps; ++i) {
        double x = (i == steps) ? b : a + i * h;
        double y = f(x);

        // пункты 1 и 2: строковый вывод с фиксированной шириной колонок
        std::cout << std::setw(12) << std::left << x
                  << std::setw(12) << std::left << y << '\n';

        // пункт 3: типовой поиск экстремумов
        if (y < min_y) min_y = y;
        if (y > max_y) max_y = y;

        // пункт 4: фиксация смены знака (начиная со второй точки)
        if (i > 0) {
            if ((prev_y > 0.0 && y < 0.0) || (prev_y < 0.0 && y > 0.0)) {
                sign_changes++;
            }
            prev_y = y;
        }
    }

    // итоговые результаты
    std::cout << std::string(24, '-') << '\n';
    std::cout << "Минимум f(x):          " << min_y << '\n';
    std::cout << "Максимум f(x):          " << max_y << '\n';
    std::cout << "Количество смен знака: " << sign_changes << '\n';

    return 0;
}