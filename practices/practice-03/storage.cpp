#include <iostream>
#include <string>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

const int MAX_TEAMS = 100;

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    std::cout << "=== ХОККЕЙНАЯ АРЕНА: ГОЛЫ КОМАНД ЗА СЕЗОН ===" << std::endl;

    std::string teams[MAX_TEAMS];
    int goals[MAX_TEAMS];
    int count = 0;

    std::cout << "Вводите название команды и количество голов (Enter вместо названия — завершение):\n\n";

    while (count < MAX_TEAMS) {
        std::string teamName;
        std::cout << "Команда [" << (count + 1) << "]: ";
        std::getline(std::cin, teamName);

        if (teamName.empty()) {
            break;
        }

        int g;
        std::cout << "Голы за сезон: ";
        while (!(std::cin >> g) || g < 0) {
            std::cout << "Ошибка ввода! Введите неотрицательное целое число: ";
            std::cin.clear();
            while (std::cin.get() != '\n');
        }
        // сбрасываем символ перевода строки после cin >>
        std::cin.ignore(10000, '\n');

        teams[count] = teamName;
        goals[count] = g;
        count++;
        std::cout << std::endl;
    }

    if (count == 0) {
        std::cout << "Список команд пуст." << std::endl;
        return 0;
    }

    if (count == MAX_TEAMS) {
        std::cout << "Достигнута максимальная вместимость: " << MAX_TEAMS << std::endl;
    }

    // 1. Вывод всех записей
    std::cout << "\n=== ВСЕ КОМАНДЫ (" << count << ") ===" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << (i + 1) << ". " << teams[i] << " — " << goals[i] << " голов\n";
    }

    // 2. Статистика: мин, макс, сумма, среднее
    int minGoals = goals[0], maxGoals = goals[0];
    int minIdx = 0, maxIdx = 0;
    long long sum = 0;

    for (int i = 0; i < count; i++) {
        if (goals[i] < minGoals) {
            minGoals = goals[i];
            minIdx = i;
        }
        if (goals[i] > maxGoals) {
            maxGoals = goals[i];
            maxIdx = i;
        }
        sum += goals[i];
    }
    double avg = static_cast<double>(sum) / count;

    std::cout << "\n=== СТАТИСТИКА ===" << std::endl;
    std::cout << "Всего команд: " << count << std::endl;
    std::cout << "Минимум: " << minGoals << " (" << teams[minIdx] << ")\n";
    std::cout << "Максимум: " << maxGoals << " (" << teams[maxIdx] << ")\n";
    std::cout << "Сумма голов: " << sum << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Среднее по лиге: " << avg << std::endl;

    // 3. Выше среднего
    std::cout << "\n=== КОМАНДЫ С РЕЗУЛЬТАТОМ ВЫШЕ СРЕДНЕГО ===" << std::endl;
    int aboveCount = 0;
    for (int i = 0; i < count; i++) {
        if (goals[i] > avg) {
            std::cout << "  " << teams[i] << " (" << goals[i] << " голов)\n";
            aboveCount++;
        }
    }
    if (aboveCount == 0) {
        std::cout << "  Нет команд выше среднего значения.\n";
    }

    // 4. Линейный поиск по значению (находит все совпадения)
    int target;
    std::cout << "\nВведите искомое количество голов: ";
    std::cin >> target;

    int foundCount = 0;
    std::cout << "Результаты поиска:\n";
    for (int i = 0; i < count; i++) {
        if (goals[i] == target) {
            std::cout << "  [" << (i + 1) << "] " << teams[i] << " — " << goals[i] << " голов\n";
            foundCount++;
        }
    }

    if (foundCount == 0) {
        std::cout << "  Команд с таким показателем не найдено.\n";
    }

    return 0;
}