#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    float celsius = 0.0f, 
    float fahrenheit = 0.0f;
    
    int choice = 0;
    cout << "1. C --> F\n";
    cout << "2. F --> C\n";
    cout << "Ваш выбор: ";
    if (!(cin >> choice)) {
        cout << "Неверный ввод" << endl;
        return 1;
    }

    if (choice == 1) {
        cout << "Введите температуру в C: ";
        if (!(cin >> celsius)) {
            cout << "Неверный ввод" << endl;
            return 1;
        }
        fahrenheit = celsius * 9.0f / 5.0f + 32.0f;
        cout << "Температура в F: " << fahrenheit << endl;
        cout << "Округлённое значение: " << static_cast<int>(fahrenheit) << endl;
    }
    else if (choice == 2) {
        cout << "Введите температуру в F: ";
        if (!(cin >> fahrenheit)) {
            cout << "Неверный ввод" << endl;
            return 1;
        }
        celsius = (fahrenheit - 32.0f) * 5.0f / 9.0f;
        cout << "Температура в C: " << celsius << endl;
        cout << "Округлённое значение: " << static_cast<int>(celsius) << endl;
    }
    else {
        cout << "Неверный выбор" << endl;
    }
}

--------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    
public:
    Vehicle() : brand(""), model("") { }
    Vehicle(const string &brand, const string &model) : brand(brand), model(model) { }
    
    virtual void printInfo() const {
        cout << "Марка: " << brand << ", модель: " << model;
    }
    
    virtual ~Vehicle() { }
};

class PassengerCar : public Vehicle {
private:
    int seatCount;
    
public:
    PassengerCar() : Vehicle(), seatCount(0) { }
    PassengerCar(const string &brand, const string &model, int seatCount)
        : Vehicle(brand, model), seatCount(seatCount) { }
    
    void printInfo() const override {
        cout << "Легковой автомобиль -> ";
        Vehicle::printInfo();
        cout << ", Количество мест: " << seatCount;
    }
};

class Truck : public Vehicle {
private:
    float loadCapacity;
    
public:
    Truck() : Vehicle(), loadCapacity(0.0f) { }
    Truck(const string &brand, const string &model, float loadCapacity)
        : Vehicle(brand, model), loadCapacity(loadCapacity) { }
    
    void printInfo() const override {
        cout << "Грузовой автомобиль -> ";
        Vehicle::printInfo();
        cout << ", Грузоподъемность: " << loadCapacity << " тонн";
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    
    const int max = 10;
    Vehicle* fleet[max];
    
    int count = 0;
    int choice = -1;
    
    while (choice != 0) {
        cout << "\nМеню автопарка:" << endl;
        cout << "1. Добавить легковой автомобиль" << endl;
        cout << "2. Добавить грузовой автомобиль" << endl;
        cout << "3. Показать все автомобили" << endl;
        cout << "0. Выход" << endl;
        cout << "Ваш выбор: ";
        
        if (!(cin >> choice)) {
            cout << "Ошибка ввода" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        
        if (choice == 1) {
            if (count >= max) {
                cout << "Нет места для добавления новых автомобилей" << endl;
                continue;
            }
            string brand, model;
            int seats;
            cout << "Введите марку: ";
            cin >> brand;
            cout << "Введите модель: ";
            cin >> model;
            cout << "Введите количество мест: ";
            if (!(cin >> seats)) {
                cout << "Ошибка ввода" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            fleet[count++] = new PassengerCar(brand, model, seats);
            cout << "Легковой автомобиль добавлен." << endl;
        }
        else if (choice == 2) {
            if (count >= max) {
                cout << "Нет места для добавления новых автомобилей" << endl;
                continue;
            }
            string brand, model;
            float capacity;
            cout << "Введите марку: ";
            cin >> brand;
            cout << "Введите модель: ";
            cin >> model;
            cout << "Введите грузоподъемность (в тоннах): ";
            if (!(cin >> capacity)) {
                cout << "Ошибка ввода" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            fleet[count++] = new Truck(brand, model, capacity);
            cout << "Грузовой автомобиль добавлен." << endl;
        }
        else if (choice == 3) {
            if (count == 0) {
                cout << "Автопарк пуст." << endl;
            }
            else {
                cout << "\nСписок автомобилей:" << endl;
                for (int i = 0; i < count; i++) {
                    fleet[i]->printInfo();
                    if (dynamic_cast<PassengerCar*>(fleet[i]) != nullptr)
                        cout << " (Тип: Легковой)";
                    else if (dynamic_cast<Truck*>(fleet[i]) != nullptr)
                        cout << " (Тип: Грузовой)";
                    else
                        cout << " (Тип: Неизвестный)";
                    cout << endl;
                }
            }
        }
        else if (choice == 0) {
            cout << "Выход из программы." << endl;
        }
        else {
            cout << "Введите корректное число от 0 до 3." << endl;
        }
    }
}
