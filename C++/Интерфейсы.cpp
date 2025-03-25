// 1 --------------------
#include <iostream>
#include <set>
using namespace std;

class NumberAnalyzer {
public:
    virtual int count(int number) = 0;
};

class DigitCount : public NumberAnalyzer {
public:
    int count(int number) override {
        if (number == 0) return 1;
        int c = 0;
        number = abs(number);
        while (number > 0) {
            c++;
            number /= 10;
        }
        return c;
    }
};

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++) 
        if (n % i == 0) return false;
    return true;
}

class PrimeFactorsCount : public NumberAnalyzer {
public:
    int count(int number) override {
        if (number == 0) return 0;
        number = abs(number);
        set<int> factors;
        for (int i = 2; i <= number; i++) {
            if (number % i == 0 && isPrime(i)) {
                factors.insert(i);
                while (number % i == 0) number /= i;
            }
        }
        return factors.size();
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int num;
    cout << "Введите число: ";
    cin >> num;
    
    DigitCount d;
    PrimeFactorsCount p;
    
    cout << "Цифр: " << d.count(num) << endl;
    cout << "Простых множителей: " << p.count(num) << endl;
}

// 2 --------------------
#include <iostream>
using namespace std;

class NumberComparator {
public:
    virtual bool match(int a, int b) = 0;
};

class GreaterThan : public NumberComparator {
public:
    bool match(int a, int b) override {
        return a > b;
    }
};

int gcd(int a, int b) {
    a = abs(a); b = abs(b);
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

class Coprime : public NumberComparator {
public:
    bool match(int a, int b) override {
        return gcd(a, b) == 1;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    int a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;
    
    GreaterThan gt;
    Coprime cp;
    
    cout << a << " > " << b << "? " << (gt.match(a, b) ? "Да" : "Нет") << endl;
    cout << "Взаимно простые? " << (cp.match(a, b) ? "Да" : "Нет") << endl;
}

