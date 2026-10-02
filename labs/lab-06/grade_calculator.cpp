#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
#include <iomanip>
#include <string>

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif
    int labScore = 0;
    int examScore = 0;
    int totalScore = 0;
    std::string grade;
    char letterGrade;
    std::string status;

    std::cout << "=== СИСТЕМА ОЦЕНИВАНИЯ СТУДЕНТОВ (РАСШИРЕННАЯ) ===" << std::endl << std::endl;

    // 1. Ввод и валидация баллов за лабораторные
    std::cout << "Введите баллы за лабораторные работы (0-40): ";
    std::cin >> labScore;

    if (labScore < 0 || labScore > 40) {
        std::cout << "Ошибка: баллы за лабораторные должны быть от 0 до 40" << std::endl;
        return 1;
    }

    // Дополнительное задание 1: Проверка допуска к экзамену
    if (labScore < 20) {
        std::cout << std::endl;
        std::cout << "ВНИМАНИЕ: Студент НЕ ДОПУЩЕН к экзамену (набрано "
                  << labScore << " из 20 необходимых баллов за лабораторные)." << std::endl;
        std::cout << "Итоговый статус: НЕ ЗАЧТЕНО (Недопуск)" << std::endl;
        return 0;
    }

    // 2. Ввод и валидация экзаменационных баллов
    std::cout << "Введите баллы за экзамен (0-60): ";
    std::cin >> examScore;

    if (examScore < 0 || examScore > 60) {
        std::cout << "Ошибка: баллы за экзамен должны быть от 0 до 60" << std::endl;
        return 1;
    }

    totalScore = labScore + examScore;

    // Определение российской шкалы
    if (totalScore >= 90) {
        grade = "5 (Отлично)";
        status = "ЗАЧТЕНО";
    } else if (totalScore >= 75) {
        grade = "4 (Хорошо)";
        status = "ЗАЧТЕНО";
    } else if (totalScore >= 60) {
        grade = "3 (Удовлетворительно)";
        status = "ЗАЧТЕНО";
    } else {
        grade = "2 (Неудовлетворительно)";
        status = "НЕ ЗАЧТЕНО";
    }

    // Дополнительное задание 2: Определение международной буквенной оценки
    if (totalScore >= 90) {
        letterGrade = 'A';
    } else if (totalScore >= 80) {
        letterGrade = 'B';
    } else if (totalScore >= 70) {
        letterGrade = 'C';
    } else if (totalScore >= 60) {
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }

    // Вывод результатов
    std::cout << std::endl;
    std::cout << "Ваш общий балл: " << totalScore << " из 100" << std::endl << std::endl;
    std::cout << "Оценка (РФ): " << grade << std::endl;
    std::cout << "Оценка (ECTS): " << letterGrade << std::endl;
    std::cout << "Статус: " << status << std::endl;

    // Анализ результатов
    std::cout << std::endl << "=== АНАЛИЗ РЕЗУЛЬТАТОВ ===" << std::endl;

    if (examScore < 20) {
        std::cout << "Внимание: набрано менее 20 баллов за экзамен." << std::endl;
        std::cout << "Рекомендуется пересдача экзамена." << std::endl;
    }

    if (labScore >= 35) {
        std::cout << "Отличная работа на лабораторных." << std::endl;
    }

    // Дополнительное задание 3: Проверка влияния на диплом с отличием
    std::cout << std::endl << "Анализ для диплома с отличием:" << std::endl;
    if (totalScore < 75) {
        std::cout << "  Внимание: получение оценки '3' или '2' лишает права на диплом с отличием!" << std::endl;
    } else if (totalScore >= 90) {
        std::cout << "  Отличный результат (оценка 5). Полностью удовлетворяет условиям для диплома с отличием (GPA >= 4.75)." << std::endl;
    } else {
        std::cout << "  Результат 'Хорошо' (оценка 4). Допускается для диплома с отличием, если суммарный средний балл останется не ниже 4.75 (не более 25% четвёрок)." << std::endl;
    }

    // Стипендия
    std::cout << std::endl;
    if (totalScore >= 75 && examScore >= 30) {
        std::cout << "Имеются основания для получения академической стипендии." << std::endl;
    } else if (totalScore >= 60) {
        std::cout << "Баллов недостаточно для получения стипендии." << std::endl;
    }

    return 0;
}