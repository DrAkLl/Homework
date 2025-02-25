#include <iostream>
using namespace std;

class Point {
private:
    double x;
    double y;
    double z;

public:

    Point() : x(0), y(0), z(0) {}

    Point(double x, double y, double z) : x(x), y(y), z(z) {}


    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y && z == other.z);
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }


    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y, z - other.z);
    }

    Point& operator++() {
        ++x;
        ++y;
        ++z;
        return *this;
    }

    Point operator++(int) {
        Point t = *this;
        ++(*this);
        return t;
    }


    void print() const {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
};

int main() {

    Point p1(1, 2, 3);
    Point p2(3, 4, 5);

    if (p1 < p2) {
        cout << "p1 < p2" << endl;
    } else {
        cout << "p1 не меньше p2" << endl;
    }

    Point p3 = p2 - p1;
    cout << "p2 - p1 = ";
    p3.print();
    cout << endl;

    cout << "p1 до инкремента: ";
    p1.print();
    cout << endl;

    ++p1;
    cout << "++p1: ";
    p1.print();
    cout << endl;

    p1++;
    cout << "p1++: ";
    p1.print();
    cout << endl;



}