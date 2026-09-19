
// Часть 2
// (2) Ввод чисел до нуля с подсчётом количества, суммы и среднего.

#include <iostream>
#include <locale>

int main() {
    std::locale::global(std::locale("en_US.UTF-8"));
    std::cin.imbue(std::locale());
    std::cout.imbue(std::locale());

    int value;
    int count = 0;
    long long sum = 0;

    std::cout << "Вводите числа (0 - для завершения): \n";

    while (std::cin >> value && value != 0)
    {
        sum += value;
        count++;
    }

    if (count == 0) {
        std::cout << "Вы не ввели ни одного числа до нуля. \n";
        return 0;
    }

    // принудительно переводим тип long long (sum) в double, чтобы среднее арифметическое было точнее
    double average = static_cast<double>(sum) / count;

    std::cout << "Количество " <<  count << '\n';
    std::cout << "Сумма: " << sum << '\n';
    std::cout << "Среднее значение: " << average << '\n';

    return 0;
}