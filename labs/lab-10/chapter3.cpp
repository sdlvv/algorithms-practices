#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#endif

const int N = 5; // размер квадратной матрицы 5х5

// 1. заполнение матрицы случайными числами
void fillMatrix(int m[][N], int rows, int minVal, int maxVal) {
    int range = maxVal - minVal + 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < N; ++j) {
            m[i][j] = std::rand() % range + minVal;
        }
    }
}

// 1. вывод матрицы в виде ровной таблицы
void printMatrix(const int m[][N], int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(4) << m[i][j]; // под каждое число выделяем 4 знакоместа
        }
        std::cout << '\n';
    }
}

// для вывода одномерного массива сумм
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

// 2. подсчёт суммы каждой строки (результат в массив rowSums)
void calcRowSums(const int m[][N], int rows, int rowSums[]) {
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += m[i][j]; // фиксируем строку i, бежим по столбцам j
        }
        rowSums[i] = sum;
    }
}

// 2. подсчёт суммы каждого столбца (результат в массив colSums)
void calcColSums(const int m[][N], int rows, int colSums[]) {
    for (int j = 0; j < N; ++j) {
        int sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += m[i][j]; // фиксируем столбец j, спускаемся вниз по строкам i
        }
        colSums[j] = sum;
    }
}

// 3. сумма главной диагонали
int sumMainDiagonal(const int m[][N], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += m[i][i];
    }
    return sum;
}

// 3. сумма побочной диагонали j = size - 1 - i
int sumSecondaryDiagonal(const int m[][N], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += m[i][size - 1 - i];
    }
    return sum;
}

// 4. поиск максимума и его координат через ссылки &
int findMaxElement(const int m[][N], int rows, int& maxRow, int& maxCol) {
    int maxVal = m[0][0];
    maxRow = 0;
    maxCol = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < N; ++j) {
            if (m[i][j] > maxVal) {
                maxVal = m[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }
    return maxVal;
}

// 5. транспонирование квадратной матрицы на месте
void transposeMatrix(int m[][N], int size) {
    // меняем только элементы выше главной диагонали
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int matrix[N][N];

    // 1. заполнение и вывод
    fillMatrix(matrix, N, -20, 20);
    std::cout << "Исходная матрица 5x5:\n";
    printMatrix(matrix, N);

    // 2. суммы строк и столбцов
    int rowSums[N];
    int colSums[N];
    calcRowSums(matrix, N, rowSums);
    calcColSums(matrix, N, colSums);

    std::cout << "\nСуммы по строкам: ";
    printArray(rowSums, N);
    std::cout << "Суммы по столбцам: ";
    printArray(colSums, N);

    // 3. диагонали
    std::cout << "\nСумма главной диагонали: " << sumMainDiagonal(matrix, N) << '\n';
    std::cout << "Сумма побочной диагонали: " << sumSecondaryDiagonal(matrix, N) << '\n';

    // 4. максимум с координатами
    int maxR = 0, maxC = 0;
    int maxVal = findMaxElement(matrix, N, maxR, maxC);
    std::cout << "\nМаксимум: " << maxVal
              << " (строка " << maxR << ", столбец " << maxC << ")\n";

    // 5. транспонирование
    transposeMatrix(matrix, N);
    std::cout << "\nТранспонированная матрица:\n";
    printMatrix(matrix, N);

    return 0;
}