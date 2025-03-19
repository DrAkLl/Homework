#include <iostream>
using namespace std;

class Class {
public:
    int a;
    int b;
    int c;

    Class(int x = 0, int y = 0, int z = 0) {
        a = x;
        b = y;
        c = z;
    }

    Class(const Class &other) {
        a = other.a + 1;
        b = other.b + 1;
        c = other.c + 1;
    }

    void print() {
        cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    }
};

int main() {
    Class qwe1(1, 2, 3);
    Class qwe2 = qwe1;

    qwe1.print();
    qwe2.print();
}
