#include <iostream>
using namespace std;

class InvalidInput {};
class DivisionByZero {};

int main() {
    setlocale(LC_ALL, "ru");

    float a, b;

    try {
        
        if (!(cin >> a)) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw InvalidInput{};
        }

        cout << "/" << endl;

        if (!(cin >> b)) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw InvalidInput{};
        }

        if (b == 0) throw DivisionByZero{};

        cout << "=" << endl;

        cout << a / b;
    }
    catch (const InvalidInput&) {
        ;
    }
    catch (const DivisionByZero&) {
        cout << "ошибка: нельзя делить на 0" << endl;
    }
    catch (...) {
        cout << "ошибка: хз" << endl;
    }
}