#include <iostream>
using namespace std;

class Vehicle {
public:

    Vehicle() {}
    virtual ~Vehicle() {}
    virtual void info() {}

};

class Car : public Vehicle {
private:

    int* data;
public:

    Car() {
        data = new int[5];
        for (int i = 0; i < 5; i++) {
            data[i] = i;
        }
    }
    
    ~Car() override {
        delete[] data;
    }
    
    void info() override {}
};


class Bike : public Vehicle {
private:
    int* data;
    
public:

    Bike() {
        data = new int[3];
        for (int i = 0; i < 3; i++) {
            data[i] = i + 10;
        }
    }

    ~Bike() override {
        delete[] data;
    }

    void info() override {
        cout << "мотоцикл" << endl;
    }

};

int main() {
    
    const int max = 2;
    Vehicle* vehicles[max];

    vehicles[0] = new Car();
    vehicles[1] = new Bike();
    
    for (int i = 0; i < max; i++) {
        vehicles[i]->info();
    }
    
    for (int i = 0; i < max; i++) {
        delete vehicles[i];
    }
}
