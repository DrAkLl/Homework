#include <iostream>
using namespace std;

class Folder {
public:
    virtual int fold(int arr[], int size) = 0;
};

class SumFolder : public Folder {
public:
    int fold(int arr[], int size) override {
        int sum = 0;
        for (int i = 0; i < size; i++) 
            sum += arr[i];
        return sum;
    }
};

class ProductFolder : public Folder {
public:
    int fold(int arr[], int size) override {
        int p = 1;
        for (int i = 0; i < size; i++) 
            p *= arr[i];
        return p;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    int size;
    cout << "Размер массива: ";
    cin >> size;
    
    int* arr = new int[size];
    cout << "Введите элементы: ";
    for (int i = 0; i < size; i++) cin >> arr[i];
    
    SumFolder s;
    ProductFolder p;
    
    cout << "Сумма: " << s.fold(arr, size) << endl;
    cout << "Произведение: " << p.fold(arr, size) << endl;
    delete[] arr;
}