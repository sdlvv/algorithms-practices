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

// 1. замена отрицательных нулями
void replaceNegativesWithZero(int arr[], int size) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] < 0) {
                arr[i] = 0;
            }
        }
    }

// 2. обратный порядок массива
void reverseArray(int arr[], int size) {
        // до середины, меняя крайние элементы навстречу друг другу
        for (int i = 0; i < size / 2; ++i) {
            int temp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = temp;
        }
    }

// 3. иклический сдвиг вправо на 1 позицию
void shiftRightByOne(int arr[], int size) {
        if (size <= 1) {
            return; // массив из 0 или 1 элемента сдвигать бессмысленно
        }

        int last = arr[size - 1]; // спасаем последний элемент, чтобы не стерся

        // с конца в начало, перетягивая соседа слева на текущее место
        for (int i = size - 1; i > 0; --i) {
            arr[i] = arr[i - 1];
        }

        arr[0] = last; // ставим спасенного в голову массива
    }

// удаление элемента по индексу со сдвигом влево и уменьшением size
bool removeAtIndex(int arr[], int& size, int index) {
        // защита от выхода за границы памяти
        if (index < 0 || index >= size) {
            return false;
        }

        // начиная с удаляемого места, накрываем каждый элемент его соседом справа
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }

        --size; // уменьшаем рабочий размер в main через ссылку
        return true;
    }

int main() {
#ifdef _WIN32
        SetConsoleCP(65001);
        SetConsoleOutputCP(65001);
#endif

        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        const int CAPACITY = 20;
        int currentSize = CAPACITY;
        int numbers[CAPACITY];

        fillArray(numbers, currentSize, -50, 50);
        std::cout << "Исходный массив:\n";
        printArray(numbers, currentSize);

        // шаг 1
        replaceNegativesWithZero(numbers, currentSize);
        std::cout << "\n1. Отрицательные заменены на нули:\n";
        printArray(numbers, currentSize);

        // шаг 2
        reverseArray(numbers, currentSize);
        std::cout << "\n2. В обратном порядке:\n";
        printArray(numbers, currentSize);

        // шаг 3
        shiftRightByOne(numbers, currentSize);
        std::cout << "\n3. Циклический сдвиг вправо на 1:\n";
        printArray(numbers, currentSize);

        // шаг 4
        int indexToRemove = 0;
        std::cout << "\n4. Введите индекс для удаления (от 0 до " << currentSize - 1 << "): ";
        std::cin >> indexToRemove;

        if (removeAtIndex(numbers, currentSize, indexToRemove)) {
            std::cout << "После удаления (новый размер = " << currentSize << "):\n";
            printArray(numbers, currentSize);
        } else {
            std::cout << "Ошибка: некорректный индекс, выход за границы массива.\n";
        }

        return 0;
    }