#include <iostream>
using namespace std;

class Folder {
public:
    virtual int fold(int pop[], int size) = 0;
};

class Sum : public Folder {
public:
    int fold(int pop[], int size) override {
        int sum = 0;
        for (int i = 0; i < size; i++) 
            sum += pop[i];
        return sum;
    }
};

class Product : public Folder {
public:
    int fold(int pop[], int size) override {
        int p = 1;
        for (int i = 0; i < size; i++) 
            p *= pop[i];
        return p;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    int size;
    cout << "Размер массива: ";
    cin >> size;
    
    int* pop = new int[size];

    cout << "Введите элементы: ";
    for (int i = 0; i < size; i++) cin >> pop[i];
    
    Sum s;
    Product p;
    
    cout << "Сумма: " << s.fold(pop, size) << endl;
    cout << "Произведение: " << p.fold(pop, size) << endl;

    delete[] pop;
}