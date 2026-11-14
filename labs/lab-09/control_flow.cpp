#include <iostream>
#include <string>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    int choice;
    int totalSessions = 0;       // Всего сеансов
    int hockeySessions = 0;      // Аренда командами
    int publicSkateSessions = 0; // Массовый прокат
    int totalIceMinutes = 0;     // Суммарное время аренды (мин)
    int peakHourSessions = 0;    // Сеансы в вечерний час пик (18:00 - 22:00)

    do {
        std::cout << "\n=== УПРАВЛЕНИЕ ХОККЕЙНОЙ АРЕНОЙ ===" << std::endl;
        std::cout << "(1) Забронировать лед" << std::endl;
        std::cout << "(2) Анализ загрузки арены" << std::endl;
        std::cout << "(0) Выход" << std::endl;
        std::cout << "Выберите действие: ";

        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода! Завершение программы." << std::endl;
            break;
        }

        switch (choice) {
            case 1: {
                int n;
                std::cout << "Сколько сеансов необходимо внести в расписание? ";
                std::cin >> n;

                if (n <= 0) {
                    std::cout << "Ошибка: количество должно быть положительным" << std::endl;
                    break;
                }

                int i = 1;

                while (i <= n) {
                    std::cout << "\n--- Сеанс #" << i << " ---" << std::endl;
                    ++i;

                    // 1. Валидация категории бронирования через do-while
                    int sessionType;
                    do {
                        std::cout << "Тип бронирования (1 - Командная тренировка/матч, 2 - Массовый прокат): ";
                        std::cin >> sessionType;
                        if (sessionType != 1 && sessionType != 2) {
                            std::cout << "Ошибка: выберите 1 или 2" << std::endl;
                        }
                    } while (sessionType != 1 && sessionType != 2);

                    // 2. Ввод принадлежности к команде
                    std::string teamName;
                    if (sessionType == 1) {
                        std::cout << "Введите название команды: \n";
                        std::cin.ignore();
                        std::getline(std::cin, teamName);
                    } else {
                        teamName = "Массовый прокат";
                    }

                    // 3. Валидация часа начала сеанса (академический диапазон работы арены 6:00 - 23:00)
                    int startHour;
                    do {
                        std::cout << "Час начала сеанса (от 6 до 23): ";
                        std::cin >> startHour;
                        if (startHour < 6 || startHour > 23) {
                            std::cout << "Ошибка: арена доступна для бронирования с 6 до 23 часов" << std::endl;
                        }
                    } while (startHour < 6 || startHour > 23);

                    // 4. Валидация длительности сеанса в минутах
                    int durationMinutes;
                    do {
                        std::cout << "Продолжительность сеанса в минутах (от 45 до 180): ";
                        std::cin >> durationMinutes;
                        if (durationMinutes < 45 || durationMinutes > 180) {
                            std::cout << "Ошибка: длительность должна быть от 45 до 180 минут" << std::endl;
                        }
                    } while (durationMinutes < 45 || durationMinutes > 180);

                    // Подсчет статистических счетчиков
                    if (sessionType == 1) {
                        hockeySessions++;
                    } else {
                        publicSkateSessions++;
                    }

                    // Определение вечернего пикового интервала (18:00 - 22:00)
                    if (startHour >= 18 && startHour <= 22) {
                        peakHourSessions++;
                    }

                    totalIceMinutes += durationMinutes;
                    totalSessions++;
                }

                std::cout << "\nУспешно добавлено сеансов: " << n << std::endl;
                break;
            }

            case 2: {
                if (totalSessions == 0) {
                    std::cout << "Нет данных для отображения" << std::endl;
                    break;
                }

                double hockeyRate = (double)hockeySessions / totalSessions * 100.0;
                double publicSkateRate = (double)publicSkateSessions / totalSessions * 100.0;
                double avgDuration = (double)totalIceMinutes / totalSessions;

                // Базовый эксплуатационный фонд льда для расчёта (например, 14 часов в сутки = 840 минут)
                const int DAILY_CAPACITY_MINUTES = 840;
                double utilizationRate = ((double)totalIceMinutes / DAILY_CAPACITY_MINUTES) * 100.0;

                std::cout << "\n=== АНАЛИЗ ЗАГРУЗКИ АРЕНЫ ===" << std::endl;
                std::cout << "Всего запланировано сеансов: " << totalSessions << std::endl;
                std::cout << "Общее забронированное время: " << totalIceMinutes << " мин. ("
                          << std::fixed << std::setprecision(1) << (totalIceMinutes / 60.0) << " ч.)" << std::endl;
                std::cout << "Средняя длительность сеанса: " << avgDuration << " мин." << std::endl;

                std::cout << "\nРаспределение по типу аренды:" << std::endl;
                std::cout << "  Командные тренировки/матчи: " << hockeySessions
                          << " (" << hockeyRate << "%)" << std::endl;
                std::cout << "  Массовый прокат: " << publicSkateSessions
                          << " (" << publicSkateRate << "%)" << std::endl;
                std::cout << "  Сеансов в пиковые часы (18:00-22:00): " << peakHourSessions << std::endl;

                // Классификация текущей загрузки арены через if/else
                std::string loadStatus;
                if (utilizationRate >= 90.0) {
                    loadStatus = "ПЕРЕГРУЗКА (требуется техническое окно для заливки)";
                } else if (utilizationRate >= 60.0) {
                    loadStatus = "ОПТИМАЛЬНАЯ ЗАГРУЗКА";
                } else if (utilizationRate >= 30.0) {
                    loadStatus = "УМЕРЕННАЯ ЗАГРУЗКА";
                } else {
                    loadStatus = "НИЗКАЯ ЗАГРУЗКА (свободный лед)";
                }

                std::cout << "\nОценка заполненности расписания: " << loadStatus
                          << " (" << utilizationRate << "% от базовой дневной нормы)" << std::endl;
                break;
            }

            case 0:
                std::cout << "Завершение работы программы" << std::endl;
                break;

            default:
                std::cout << "Неверный выбор. Повторите ввод" << std::endl;
        }

    } while (choice != 0);

    return 0;
}