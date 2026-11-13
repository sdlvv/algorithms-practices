#include <iostream>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#endif

// 1. заполнение. генерируем число + добавляем нижнюю границу (-50, minVal), т.к. rand() отрицательные числа не генерирует
void fillArray(int arr[], int size, int minVal, int maxVal) {
    int range = maxVal - minVal + 1;
        for (int i = 0; i < size; i++) {
            arr[i] = std::rand() % range + minVal;
    }
}

// 2. вывод массива, const т.к. массив менять нельзя
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

// 3. cумма, среднее, максимум и минимум
int calcSum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

double averageSum(const int arr[], int size) {
    return static_cast<double>(calcSum(arr, size)) / size;
}

int findMax(const int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int findMin(const int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

// 4. подсчёт по знаку: передаём счётчики по ссылке &, чтобы вернуть сразу три числа
void countSigns(const int arr[], int size, int& posCount, int& negCount, int& zeroCount) {
    posCount = 0;
    negCount = 0;
    zeroCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            ++posCount;
        } else if (arr[i] < 0) {
            ++negCount;
        } else if (arr[i] == 0) {
            ++zeroCount;
        }
    }
}

// 5. индекс первого элемента строго больше среднего
int findFirstAboveAverage(const int arr[], int size, double average) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > average) {
            return i; // нашли первый - сразу выходим
        }
    }
    return -1; // страховка на случай, если все индексы равны и среднего нет - сигнальный код ошибки
}

// дополнительно: количество нечетных чисел
int countEven(const int arr[], int size) {
    int evenCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        }
    }
    return evenCount;
}

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const int SIZE = 20;
    int numbers[SIZE];

    fillArray(numbers, SIZE, -50, 50);

    std::cout << "Массив: ";
    printArray(numbers, SIZE);

    int sum = calcSum(numbers, SIZE);
    double average = averageSum(numbers, SIZE);

    std::cout << "Сумма: " << sum << '\n';
    std::cout << "Среднее: " << average << '\n';
    std::cout << "Максимум: " << findMax(numbers, SIZE) << '\n';
    std::cout << "Минимум: " << findMin(numbers, SIZE) << '\n';

    int pos = 0, neg = 0, zero = 0;
    countSigns(numbers, SIZE, pos, neg, zero);
    std::cout << "Положительных: " << pos
              << ", отрицательных: " << neg
              << ", нулей: " << zero << '\n';

    int idx = findFirstAboveAverage(numbers, SIZE, average);
    if (idx != -1) {
        std::cout << "Первый элемент больше среднего: numbers[" << idx << "] = " << numbers[idx] << '\n';
    } else {
        std::cout << "Элементов больше среднего нет.\n";
    }

    int evenNumber = countEven(numbers, SIZE);
    std::cout << "Количество четных чисел: " << evenNumber << '\n';

    return 0;
}