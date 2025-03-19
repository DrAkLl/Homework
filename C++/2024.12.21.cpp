#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void random(int* A, int* B, int size) {
    cout << "\n1 массив:\n";
    for (int i = 0; i < size; i++) {
        int r = rand() % 51;
        cout << r << " ";
        A[i] = r;
    }

    cout << "\n2 массив:\n";
    for (int i = 0; i < size; i++) {
        int r = rand() % 51;
        cout << r << " ";
        B[i] = r;
    }
    cout << endl;
}

// Функции для нахождения максимума, минимума и среднего значения
int Max(int* A, int* B, int size) {
    int maxVal = A[0];
    for (int i = 0; i < size; i++) {
        if (A[i] > maxVal) maxVal = A[i];
        if (B[i] > maxVal) maxVal = B[i];
    }
    cout << "max: ";
    return maxVal;
}

double Avg(int* A, int* B, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += A[i] + B[i];
    }
    cout << "avg: ";
    return sum / (2 * size);
}

int Min(int* A, int* B, int size) {
    int minVal = A[0];
    for (int i = 0; i < size; i++) {
        if (A[i] < minVal) minVal = A[i];
        if (B[i] < minVal) minVal = B[i];
    }
    cout << "min: ";
    return minVal;
}


template <typename T>
T Action(int* A, int* B, int size, T (*func)(int*, int*, int)) {
    return func(A, B, size);
}


void display(int* A, int* B, int size) {
    cout << "\n1 массив:\n";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }

    cout << "\n2 массив:\n";
    for (int i = 0; i < size; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    int size;
    cout << "Введите размер массивов: ";
    cin >> size;

    int* A = new int[size];
    int* B = new int[size];

    random(A, B, size);

    int choice;
    while (true) {
        cout << "\n---- меню ----" << endl;
        cout << "1. max" << endl;
        cout << "2. avg" << endl;
        cout << "3. min" << endl;
        cout << "9. массивы" << endl;
        cout << "0. выход" << endl;
        cout << "--------------" << endl;
        cin >> choice;

        if (choice == 1) {
            int result = Action(A, B, size, Max);
            cout << result << endl;
        } else if (choice == 2) {
            double result = Action(A, B, size, Avg);
            cout << result << endl;
        } else if (choice == 3) {
            int result = Action(A, B, size, Min);
            cout << result << endl;
        } else if (choice == 9) {
            display(A, B, size);
        } else if (choice == 0) {
            cout << "выход" << endl;
            break;
        } else {
            cout << "неверный выбор" << endl;
        }
    }

    delete[] A;
    delete[] B;

    return 0;
}