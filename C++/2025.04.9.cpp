#include <iostream>
using namespace std;

class Student {
public:
    virtual void react() = 0;
    virtual ~Student() = default;
};

class Professor {
    static const int max = 5;
    Student* group[max];
    int count = 0;

public:
    void addStudent(Student* s) {
        if (count < max) {
            group[count++] = s;
        }
    }

    void dismiss() {
        cout << "можете собираться и идти домой";
        for (int i = 0; i < count; ++i) {
            group[i]->react();
        }
    }
};

class Stud1 : public Student {
public:
    void react() override {
        cout << "1: быстро свалил прям бегом реальна";
    }
};

class Stud2 : public Student {
public:
    void react() override {
        cout << "2: спокойно сваливает";
    }
};

class Stud3 : public Student {
public:
    void react() override {
        cout << "3: даёт тп на фонтан";
    }
};

int main() {
    Professor teacher;
    
    Stud1 a;
    Stud2 b;
    Stud3 c;

    teacher.addStudent(&a);
    teacher.addStudent(&b);
    teacher.addStudent(&c);

    teacher.dismiss();
}