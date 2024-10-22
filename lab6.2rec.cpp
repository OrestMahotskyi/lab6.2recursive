#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивна функція для генерації масиву
void generateArray(int arr[], int size, int index = 0) {
    if (index == size) return;
    arr[index] = rand() % 100; // Генерація чисел від 0 до 99
    generateArray(arr, size, index + 1);
}

// Рекурсивна функція для виведення масиву
void printArray(const int arr[], int size, int index = 0) {
    if (index == size) {
        cout << endl;
        return;
    }
    cout << setw(4) << arr[index];
    printArray(arr, size, index + 1);
}

// Рекурсивна функція для пошуку індексу мінімального елемента
void findMinIndex(const int arr[], int size, int &minIndex, int index = 1) {
    if (index == size) return;
    if (arr[index] < arr[minIndex]) {
        minIndex = index;
    }
    findMinIndex(arr, size, minIndex, index + 1);
}

// Рекурсивна функція для пошуку індексу максимального елемента
void findMaxIndex(const int arr[], int size, int &maxIndex, int index = 1) {
    if (index == size) return;
    if (arr[index] > arr[maxIndex]) {
        maxIndex = index;
    }
    findMaxIndex(arr, size, maxIndex, index + 1);
}

// Рекурсивна функція для обчислення суми індексів
int sumOfIndexes(int minIndex, int maxIndex) {
    return minIndex + maxIndex;
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел
    const int SIZE = 10;
    int arr[SIZE];

    // Генерація та виведення початкового масиву
    generateArray(arr, SIZE);
    cout << "Initial array:" << endl;
    printArray(arr, SIZE);

    // Пошук індексів мінімального та максимального елементів
    int minIndex = 0, maxIndex = 0;
    findMinIndex(arr, SIZE, minIndex);
    findMaxIndex(arr, SIZE, maxIndex);

    // Обчислення суми індексів
    int sumIndexes = sumOfIndexes(minIndex, maxIndex);

    // Виведення результатів
    cout << "Min element index: " << minIndex << ", Max element index: " << maxIndex << endl;
    cout << "Sum of indexes: " << sumIndexes << endl;

    return 0;
}
