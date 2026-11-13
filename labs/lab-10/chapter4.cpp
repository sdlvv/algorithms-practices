#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#endif

const int N = 6; // размер квадратной матрицы 6x6

// 1. заполнение случайными числами от minVal до maxVal
void fillMatrixRandom(int m[][N], int rows, int minVal, int maxVal) {
    int range = maxVal - minVal + 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < N; ++j) {
            m[i][j] = std::rand() % range + minVal;
        }
    }
}

// 1. заполнение матрицы вручную с клавиатуры построчно
void fillMatrixManual(int m[][N], int rows) {
    std::cout << "Введите элементы матрицы 6x6 (по 6 целых чисел в строке):\n";
    for (int i = 0; i < rows; ++i) {
        std::cout << "Строка " << i << ": ";
        for (int j = 0; j < N; ++j) {
            std::cin >> m[i][j];
        }
    }
}

// 2. вывод матрицы в виде таблицы
void printMatrix(const int m[][N], int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(4) << m[i][j];
        }
        std::cout << '\n';
    }
}

// 3. среднее арифметическое всех элементов матрицы
double calcMatrixAverage(const int m[][N], int rows) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < N; ++j) {
            sum += m[i][j];
        }
    }
    return static_cast<double>(sum) / (rows * N);
}

// 4. замена элементов, меньших среднего, на 0 + возврат количества замен
int replaceBelowAverageWithZero(int m[][N], int rows, double avg) {
    int replacements = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < N; ++j) {
            if (m[i][j] < avg) {
                m[i][j] = 0;
                ++replacements;
            }
        }
    }
    return replacements;
}

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int matrix[N][N];
    int mode = 0;

    std::cout << "Выберите способ заполнения матрицы 6x6:\n"
              << "1 — случайными числами от -20 до 20\n"
              << "2 — ввод с клавиатуры\n"
              << "Ваш выбор: ";
    std::cin >> mode;

    if (mode == 2) {
        fillMatrixManual(matrix, N);
    } else {
        fillMatrixRandom(matrix, N, -20, 20);
    }

    std::cout << "\nМатрица ДО преобразования:\n";
    printMatrix(matrix, N);

    double avg = calcMatrixAverage(matrix, N);
    std::cout << "\nСреднее арифметическое элементов: " << avg << '\n';

    int count = replaceBelowAverageWithZero(matrix, N, avg);

    std::cout << "\nМатрица ПОСЛЕ преобразования:\n";
    printMatrix(matrix, N);
    std::cout << "\nКоличество замен: " << count << '\n';

    return 0;
}