#include <iostream>
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
        number = number < 0 ? -number : number;
        while (number > 0) {
            c++;
            number /= 10;
        }
        return c;
    }
};

class PrimeFactorsCount : public NumberAnalyzer {
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i*i <= n; i++) 
            if (n % i == 0) return false;
        return true;
    }
    
public:
    int count(int number) override {
        if (number == 0) return 0;
        number = number < 0 ? -number : number;
        int factors[100] = {0};
        int idx = 0;
        
        for (int i = 2; i <= number; i++) {
            if (number % i == 0 && isPrime(i)) {
                factors[idx++] = i;
                while (number % i == 0) number /= i;
            }
        }
        return idx;
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

//----------------------------------------

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

class Coprime : public NumberComparator {
    int gcd(int a, int b) {
        a = a < 0 ? -a : a;
        b = b < 0 ? -b : b;
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    
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

//----------------------------------------

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

//----------------------------------------

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
            cnt += (arr[i] % 2 == 0);
        return cnt;
    }
};

class OddCount : public Folder {
public:
    int fold(int arr[], int size) override {
        int cnt = 0;
        for (int i = 0; i < size; i++)
            cnt += (arr[i] % 2 != 0);
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
    
    EvenCount e;
    OddCount o;
    
    cout << "Четные: " << e.fold(arr, size) << endl;
    cout << "Нечетные: " << o.fold(arr, size) << endl;
    delete[] arr;
}

//----------------------------------------

#include <iostream>
using namespace std;

class Folder {
public:
    virtual int fold(int arr[], int size) = 0;
};

class PrimeCount : public Folder {
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i*i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }
    
public:
    int fold(int arr[], int size) override {
        int cnt = 0;
        for (int i = 0; i < size; i++)
            if (isPrime(arr[i])) cnt++;
        return cnt;
    }
};

class NonPrimeCount : public Folder {
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i*i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }
    
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

//----------------------------------------

#include <iostream>
using namespace std;

class StringAnalyzer {
public:
    virtual int analyse(char str[]) = 0;
};

class LowercaseCount : public StringAnalyzer {
public:
    int analyse(char str[]) override {
        int cnt = 0;
        for (int i = 0; str[i]; i++)
            if (str[i] >= 'a' && str[i] <= 'z') cnt++;
        return cnt;
    }
};

class UppercaseCount : public StringAnalyzer {
public:
    int analyse(char str[]) override {
        int cnt = 0;
        for (int i = 0; str[i]; i++)
            if (str[i] >= 'A' && str[i] <= 'Z') cnt++;
        return cnt;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    char str[100];
    cout << "Введите строку: ";
    cin.ignore();
    cin.getline(str, 100);
    
    LowercaseCount l;
    UppercaseCount u;
    
    cout << "Строчные: " << l.analyse(str) << endl;
    cout << "Заглавные: " << u.analyse(str) << endl;
}

//----------------------------------------

#include <iostream>
using namespace std;

class StringAnalyzer {
public:
    virtual int analyse(char str[]) = 0;
};

class VowelCount : public StringAnalyzer {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
public:
    int analyse(char str[]) override {
        int cnt = 0;
        for (int i = 0; str[i]; i++)
            if (isVowel(str[i])) cnt++;
        return cnt;
    }
};

class ConsonantCount : public StringAnalyzer {
    bool isConsonant(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            char lower = c | 0x20; // to lowercase
            return lower != 'a' && lower != 'e' && lower != 'i' && 
                   lower != 'o' && lower != 'u';
        }
        return false;
    }
    
public:
    int analyse(char str[]) override {
        int cnt = 0;
        for (int i = 0; str[i]; i++)
            if (isConsonant(str[i])) cnt++;
        return cnt;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    char str[100];
    cout << "Enter string: ";
    cin.ignore();
    cin.getline(str, 100);
    
    VowelCount v;
    ConsonantCount c;
    
    cout << "Vowels: " << v.analyse(str) << "\n";
    cout << "Consonants: " << c.analyse(str) << "\n";
}