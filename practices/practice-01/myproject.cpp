#include <iostream>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif

int main () {

#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    std::cout << "=== ХОККЕЙНАЯ АРЕНА ===" << std::endl;
    std::cout << std::endl;

    // название и категория
    std::string arenaName; // название арены
    char arenaCategory; // категория арены (A, B, C)

    // сеансы
    int sessionsPerDay; //  количество сеансов массового катания в день
    int sessionDuration; // длительность одного сеанса (мин)
    int iceCapacity; // максимум посетителей на льду за сеанс
    double ticketPrice; // цена билета за один сеанс (руб)

    // услуги
    bool hasSkateRental; // есть ли прокат коньков
    double skateRentalPrice = 0.0; // цена проката коньков (руб)
    bool hasSharpening; // есть ли заточка на коньках
    double sharpeningPrice = 0.0; // цена заточки коньков (руб)

    int answer; // вспомогательная переменная для ответа (да / нет)

    // ввод данных
std::cout << "Введите название арены: ";
    std::getline(std::cin, arenaName);

    std::cout << "Введите категорию арены (A, B или C): ";
    std::cin >> arenaCategory;

    std::cout << "Введите количество сеансов в день: ";
    std::cin >> sessionsPerDay;

    std::cout << "Введите длительность сеанса (мин): ";
    std::cin >> sessionDuration;

    std::cout << "Введите вместимость льда (чел. за сеанс): ";
    std::cin >> iceCapacity;

    std::cout << "Введите цену билета на сеанс (руб): ";
    std::cin >> ticketPrice;

    std::cout << "Есть прокат коньков? (1 - да, 0 - нет): ";
    std::cin >> answer;
    hasSkateRental = (answer == 1);
    if (hasSkateRental) {
        std::cout << "Введите цену проката коньков (руб): ";
        std::cin >> skateRentalPrice;
    }

    std::cout << "Есть заточка коньков? (1 - да, 0 - нет): ";
    std::cin >> answer;
    hasSharpening = (answer == 1);
    if (hasSharpening) {
        std::cout << "Введите цену заточки коньков (руб): ";
        std::cin >> sharpeningPrice;
    }

    // вычисления
    // общее время катания за день в часах
    double totalIceHours = static_cast<double>(sessionsPerDay * sessionDuration) / 60.0;

    // максимальное число посетителей в день
    int maxVisitorsPerDay = sessionsPerDay * iceCapacity;

    // максимальная дневная выручка от продажи билетов
    double maxTicketRevenue = maxVisitorsPerDay * ticketPrice;

    // стоимость посещения для одного человека со всеми доступными услугами
    double fullVisitCost = ticketPrice + skateRentalPrice + sharpeningPrice;

    // стоимость одной минуты катания
    double pricePerMinute = (sessionDuration > 0) ? ticketPrice / sessionDuration : 0.0;

    // вывод результатов
    std::cout << std::fixed << std::setprecision(2);  // 2 знака после запятой

    std::cout << std::endl;
    std::cout << "======= ИНФОРМАЦИЯ ОБ АРЕНЕ =======" << std::endl;
    std::cout << "Название:              " << arenaName << std::endl;
    std::cout << "Категория:             " << arenaCategory << std::endl;

    std::cout << std::endl << "--- Сеансы ---" << std::endl;
    std::cout << "Сеансов в день:        " << sessionsPerDay << std::endl;
    std::cout << "Длительность сеанса:   " << sessionDuration << " мин." << std::endl;
    std::cout << "Вместимость льда:      " << iceCapacity << " чел." << std::endl;
    std::cout << "Цена билета:           " << ticketPrice << " руб." << std::endl;
    std::cout << "Цена минуты катания:   " << pricePerMinute << " руб." << std::endl;

    std::cout << std::endl << "--- Услуги ---" << std::endl;
    std::cout << "Прокат коньков:        " << (hasSkateRental ? "Да" : "Нет");
    if (hasSkateRental) {
        std::cout << " (" << skateRentalPrice << " руб.)";
    }
    std::cout << std::endl;

    std::cout << "Заточка коньков:       " << (hasSharpening ? "Да" : "Нет");
    if (hasSharpening) {
        std::cout << " (" << sharpeningPrice << " руб.)";
    }
    std::cout << std::endl;

    std::cout << std::endl << "--- Расчёты ---" << std::endl;
    std::cout << "Время катания в день:  " << totalIceHours << " ч." << std::endl;
    std::cout << "Макс. посетителей/день:" << maxVisitorsPerDay << " чел." << std::endl;
    std::cout << "Макс. выручка/день:    " << maxTicketRevenue << " руб." << std::endl;
    std::cout << "Посещение со всеми услугами: " << fullVisitCost << " руб." << std::endl;
    std::cout << "===================================" << std::endl;

    return 0;
}