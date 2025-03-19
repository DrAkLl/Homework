#include <iostream>
#include <string>
using namespace std;

class Animal {
private:

    string name;
    int weight;

protected:

    int hzzachemya;

public:

    Animal() {
        hzzachemya = 0;
    }


    Animal(const string& name, int weight) {
        this->name = name;
        this->weight = weight;
    }

    void print() const {
        cout << "Имя: " << name << endl;
        cout << "Вес: " << weight << endl;
        cout << endl;
    }
};


class Cat : public Animal {
public:

    Cat(const string& name, int weight) : Animal(name, weight) {}
};

class Dog : public Animal {
public:

    Dog(const string& name, int weight) : Animal(name, weight) {}
};


int main() {
    setlocale(LC_ALL, "Ru");

    Cat cat1("барсик", 3);
    Cat cat2("мурка", 4);
    Dog dog1("бобик", 11);
    Dog dog2("тузик", 12);

    cat1.print();
    cat2.print();
    dog1.print();
    dog2.print();
}