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

// 3 --------------------
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
        for (int i = 0; i < size; i++) sum += arr[i];
        return sum;
    }
};

class ProductFolder : public Folder {
public:
    int fold(int arr[], int size) override {
        int p = 1;
        for (int i = 0; i < size; i++) p *= arr[i];
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

// 4 --------------------
#include <iostream>
using namespace std;

class Folder {
public:
    virtual int fold(int arr[], int size) = 0;
};

class EvenCount : public Folder {
public:
    int fold(int arr[], int size) override {
        int cnt = 0;
        for (int i = 0; i < size; i++) 
            if (arr[i] % 2 == 0) cnt++;
        return cnt;
    }
};

class OddCount : public Folder {
public:
    int fold(int arr[], int size) override {
        int cnt = 0;
        for (int i = 0; i < size; i++) 
            if (arr[i] % 2 != 0) cnt++;
        return cnt;
    }
};

int main() {
    setlocale(LC_ALL, "russian");
    int size;
    cout << "Размер массива: ";
    cin >> size;
    int* arr = new int[size];
    cout << "Введите элементы: ";
    for (int i = 0; i < size; i++) cin >> arr[i];
    
    EvenCount e;
    OddCount o;
    
    cout << "Четные: " << e.fold(arr, size) << endl;
    cout << "Нечетные: " << o.fold(arr, size) << endl;
    delete[] arr;
}

// 5 --------------------
#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

class Folder {
public:
    virtual int fold(int arr[], int size) = 0;
};

class PrimeCount : public Folder {
public:
    int fold(int arr[], int size) override {
        int cnt = 0;
        for (int i = 0; i < size; i++)
            if (isPrime(arr[i])) cnt++;
        return cnt;
    }
};

class NonPrimeCount : public Folder {
public:
    int fold(int arr[], int size) override {
        int cnt = 0;
        for (int i = 0; i < size; i++)
            if (!isPrime(arr[i])) cnt++;
        return cnt;
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
    
    PrimeCount p;
    NonPrimeCount np;
    
    cout << "Простые: " << p.fold(arr, size) << endl;
    cout << "Непростые: " << np.fold(arr, size) << endl;
    delete[] arr;
}

// 6 --------------------
#include <iostream>
#include <cctype>
using namespace std;

class StringAnalyzer {
public:
    virtual int analyse(string str) = 0;
};

class LowercaseCount : public StringAnalyzer {
public:
    int analyse(string str) override {
        int cnt = 0;
        for (char c : str) 
            if (islower(c)) cnt++;
        return cnt;
    }
};

class UppercaseCount : public StringAnalyzer {
public:
    int analyse(string str) override {
        int cnt = 0;
        for (char c : str) 
            if (isupper(c)) cnt++;
        return cnt;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string s;
    cout << "Введите строку: ";
    getline(cin, s);
    
    LowercaseCount l;
    UppercaseCount u;
    
    cout << "Строчные: " << l.analyse(s) << endl;
    cout << "Заглавные: " << u.analyse(s) << endl;
}

// 7 --------------------
#include <iostream>
#include <cctype>
using namespace std;

class StringAnalyzer {
public:
    virtual int analyse(string str) = 0;
};

class VowelCount : public StringAnalyzer {
public:
    int analyse(string str) override {
        int cnt = 0;
        for (char c : str) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                cnt++;
        }
        return cnt;
    }
};

class ConsonantCount : public StringAnalyzer {
public:
    int analyse(string str) override {
        int cnt = 0;
        for (char c : str) {
            char lower = tolower(c);
            if (isalpha(c) && !(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u'))
                cnt++;
        }
        return cnt;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    string s;
    cout << "Введите строку: ";
    getline(cin, s);
    
    VowelCount v;
    ConsonantCount c;
    
    cout << "Гласные: " << v.analyse(s) << endl;
    cout << "Согласные: " << c.analyse(s) << endl;
}