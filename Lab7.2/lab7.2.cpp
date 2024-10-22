#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;


void CreateMatrix(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}


void PrintMatrix(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

// Функція для знаходження максимального елемента в рядку
int MaxInRow(int* row, const int colCount) {
    int max = row[0];
    for (int j = 1; j < colCount; j++) {
        if (row[j] > max) {
            max = row[j];
        }
    }
    return max;
}

// Функція для знаходження суми максимальних елементів у парних рядках
int SumOfMaxInEvenRows(int** a, const int rowCount, const int colCount) {
    int sum = 0;
    for (int i = 0; i < rowCount; i += 2) { 
        sum += MaxInRow(a[i], colCount);
    }
    return sum;
}

int main() {
    srand((unsigned)time(NULL));

    int rowCount, colCount;
    cout << " (k): ";
    cin >> rowCount;
    cout << " (n): ";
    cin >> colCount;

    int Low = 1, High = 100; 

    
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++) {
        a[i] = new int[colCount];
    }

    
    CreateMatrix(a, rowCount, colCount, Low, High);
    PrintMatrix(a, rowCount, colCount);

    
    int sum = SumOfMaxInEvenRows(a, rowCount, colCount);
    cout << "Sum of maximum elements in even rows: " << sum << endl;

    
    for (int i = 0; i < rowCount; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}