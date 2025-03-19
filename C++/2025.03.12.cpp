#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

class Shape {
protected:

    int id;
    static int idCounter;

public:

    Shape() { id = ++idCounter; }

    virtual ~Shape() { cout << "Удаляется фигура с id: " << id << endl; }

    int getId() const { return id; }

    virtual double getArea() const = 0;

    virtual void printInfo() const = 0;

    double operator+(const Shape& other) const {
        return this->getArea() + other.getArea();
    }

    bool operator==(const Shape& other) const {
        return fabs(this->getArea() - other.getArea()) < 1e-6;
    }

};

int Shape::idCounter = 0;

class Circle : public Shape {
protected:

    double radius;

public:

    Circle(double r) {
        radius = (r < 0 ? 0 : r);
    }

    virtual ~Circle() { cout << "Удаляется Круг с id: " << id << endl; }

    virtual double getArea() const override {
        return PI * radius * radius;
    }

    virtual void printInfo() const override {
        cout << "Тип: Круг" << endl;
        cout << "ID: " << id << endl;
        cout << "Радиус: " << radius << endl;
        cout << "Площадь: " << getArea() << endl;
    }

    double getCircumference() const { return 2 * PI * radius; }

};

class Sphere : public Circle {
public:

    Sphere(double r) : Circle(r) {}

    virtual ~Sphere() { cout << "Удаляется Сфера с id: " << id << endl; }

    virtual double getArea() const override {
        return 4 * PI * radius * radius;
    }

    virtual void printInfo() const override {
        cout << "Тип: Сфера" << endl;
        cout << "ID: " << id << endl;
        cout << "Радиус: " << radius << endl;
        cout << "Площадь поверхности: " << getArea() << endl;
        cout << "Объём: " << getVolume() << endl;
    }

    double getVolume() const { return (4.0 / 3.0) * PI * radius * radius * radius; }

};

class Rectangle : public Shape {
protected:

    double width, height;

public:

    Rectangle(double w, double h) {
        width = (w < 0 ? 0 : w);
        height = (h < 0 ? 0 : h);
    }

    virtual ~Rectangle() { cout << "Удаляется Прямоугольник с id: " << id << endl; }
    virtual double getArea() const override {
        return width * height;
    }

    virtual void printInfo() const override {
        cout << "Тип: Прямоугольник" << endl;
        cout << "ID: " << id << endl;
        cout << "Ширина: " << width << ", Высота: " << height << endl;
        cout << "Площадь: " << getArea() << endl;
    }

    double getPerimeter() const { return 2 * (width + height); }

};

class Cuboid : public Rectangle {
protected:

    double depth;

public:

    Cuboid(double w, double h, double d) : Rectangle(w, h) {
        depth = (d < 0 ? 0 : d);
    }

    virtual ~Cuboid() { cout << "Удаляется Параллелепипед с id: " << id << endl; }
    virtual double getArea() const override {
        return 2 * (width * height + width * depth + height * depth);
    }

    virtual void printInfo() const override {
        cout << "Тип: Параллелепипед" << endl;
        cout << "ID: " << id << endl;
        cout << "Ширина: " << width << ", Высота: " << height << ", Глубина: " << depth << endl;
        cout << "Площадь поверхности: " << getArea() << endl;
        cout << "Объём: " << getVolume() << endl;
    }

    double getVolume() const { return width * height * depth; }

};

void AddElement(int& count, const int max, Shape** shapes) {
    if (count >= max) {
        cout << "Массив заполнен" << endl;
        return;
    }
    int tchoice;
    cout << "\nВыберите тип фигуры:" << endl;
    cout << "1. Круг" << endl;
    cout << "2. Сфера" << endl;
    cout << "3. Прямоугольник" << endl;
    cout << "4. Параллелепипед" << endl;
    cout << "Ваш выбор: ";
    cin >> tchoice;
    double r, w, h, d;
    switch (tchoice) {
    case 1:
        cout << "Введите радиус: ";
        ;cin >> r;
        shapes[count++] = new Circle(r);
        break;
    case 2:
        cout << "Введите радиус: ";
        cin >> r;
        shapes[count++] = new Sphere(r);
        break;
    case 3:
        cout << "Введите ширину: ";
        cin >> w;
        cout << "Введите высоту: ";
        cin >> h;
        shapes[count++] = new Rectangle(w, h);
        break;
    case 4:
        cout << "Введите ширину: ";
        cin >> w;
        cout << "Введите высоту: ";
        cin >> h;
        cout << "Введите глубину: ";
        cin >> d;
        shapes[count++] = new Cuboid(w, h, d);
        break;
    default:
        cout << "Некорректный выбор" << endl;
        return;
    }
    cout << "Объект добавлен" << endl;
}

void RemoveElement(int& count, Shape** shapes) {
    if (count == 0) {
        cout << "Нет объектов для удаления" << endl;
        return;
    }
    int index;
    cout << "Введите индекс удаляемого объекта (от 0 до " << count - 1 << "): ";
    cin >> index;
    if (index < 0 || index >= count) {
        cout << "Некорректный индекс" << endl;
        return;
    }
    delete shapes[index];
    for (int i = index; i < count - 1; i++) {
        shapes[i] = shapes[i + 1];
    }
    count--;
    cout << "Объект удалён" << endl;
}

void ViewElements(int count, Shape** shapes) {
    if (count == 0) {
        cout << "Нет объектов для вывода" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "\nИндекс " << i << ":" << endl;
        shapes[i]->printInfo();
    }
}


int main() {
    setlocale(LC_ALL, "ru");

    const int max = 100;
    Shape** shapes = new Shape * [max];
    int count = 0;
    int choice = 123;

    while (choice != 0) {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить новую фигуру" << endl;
        cout << "2. Удалить фигуру по индексу" << endl;
        cout << "3. Вывести все фигуры" << endl;
        cout << "0. Завершение работы" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;
        switch (choice) {
        case 1:
            AddElement(count, max, shapes);
            break;
        case 2:
            RemoveElement(count, shapes);
            break;
        case 3:
            ViewElements(count, shapes);
            break;
        case 0:
            cout << "Завершение работы" << endl;
            break;
        default:
            cout << "Введите число от 0 до 3" << endl;
            break;
        }
    }

    for (int i = 0; i < count; i++) {
        delete shapes[i];
    }
    delete[] shapes;

}