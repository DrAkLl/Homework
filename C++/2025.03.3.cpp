#include <iostream>
using namespace std;

class A {

    int a, b;

public:

    A() {
        a = 0;
        b = 0;
    }


    A(int a, int b) {
        this->a = a;
        this->b = b;
    }


    friend int sum(const A &a, const B &b);
};

class B {

    int x, y;

public:

    B() {
        x = 0;
        y = 0;
    }

    B(int x, int y) {
        this->x = x;
        this->y = y;
    }


    friend int sum(const A &a, const B &b);
};


int sum(const A &obj1, const B &obj2) {
    return obj1.a + obj1.b + obj2.x + obj2.y;
}

int main() {

    A obj1(10, 20);
    B obj2(30, 40);

    cout << "Сумма всех полей: " << sum(obj1, obj2) << endl;
}
