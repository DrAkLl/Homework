#include <iostream>
#include <string>
using namespace std;

// Вычислительная машина
class ComputingMachine {
protected:
    string model;
    int power;

    bool compareBase(const ComputingMachine& other) const {
        return (model == other.model && power == other.power);
    }

public:
    ComputingMachine() {
        model = "";
        power = 0;
    }

    ComputingMachine(const string& model, int power) {
        this->model = model;
        if (power < 0) {
            cout << "Ошибка: мощность не может быть отрицательной. Устанавлино 0." << endl;
            this->power = 0;
        } else {
            this->power = power;
        }
    }

    virtual ~ComputingMachine() {}

    virtual void printInfo() const {
        cout << "Модель: " << model << endl;
        cout << "Мощность: " << power << endl;
    }

    virtual bool operator==(const ComputingMachine& other) const {
        return (model == other.model && power == other.power);
    }

    virtual ComputingMachine operator+(const ComputingMachine& other) const {
        string newModel = model + " " + other.model;
        int newPower = power + other.power;
        return ComputingMachine(newModel, newPower);
    }

    virtual ComputingMachine& operator++() {
        power++;
        model += "*";
        return *this;
    }
};

// Пк
class PC : public ComputingMachine {
protected:
    string cpu;
    int ram;

public:
    PC() : ComputingMachine() {
        cpu = "";
        ram = 0;
    }

    PC(const string& model, int power, const string& cpu, int ram)
        : ComputingMachine(model, power) {
        this->cpu = cpu;
        if (ram < 0) {
            cout << "Ошибка: ОЗУ не может быть отрицательным. Устанавлино 0." << endl;
            this->ram = 0;
        } else {
            this->ram = ram;
        }
    }

    virtual void printInfo() const override {
        cout << "Модель: " << model << endl;
        cout << "Мощность: " << power << endl;
        cout << "Процессор: " << cpu << endl;
        cout << "ОЗУ: " << ram << endl;
    }

    virtual bool operator==(const ComputingMachine& other) const override {
        const PC* pc = dynamic_cast<const PC*>(&other);
        if (pc)
            return compareBase(other) && (cpu == pc->cpu) && (ram == pc->ram);
        return false;
    }

    virtual PC operator+(const ComputingMachine& other) const override {
        const PC* pc = dynamic_cast<const PC*>(&other);
        if (pc) {
            string newModel = model + " " + pc->model;
            int newPower = power + pc->power;
            string newCpu = cpu + " " + pc->cpu;
            int newRam = ram + pc->ram;
            return PC(newModel, newPower, newCpu, newRam);
        } else {
            return *this;
        }
    }

    virtual PC& operator++() override {
        power++;
        model += "*";
        ram++;
        cpu += "+";
        return *this;
    }
};

// Ноутбук
class Laptop : public PC {
protected:
    int batteryLife;
    string batteryType;

public:
    Laptop() : PC() {
        batteryLife = 0;
        batteryType = "";
    }

    Laptop(const string& model, int power, const string& cpu, int ram, int batteryLife, const string& batteryType)
        : PC(model, power, cpu, ram) {
        if (batteryLife < 0) {
            cout << "Ошибка: время работы батареи не может быть отрицательным. Устанавлино 0." << endl;
            this->batteryLife = 0;
        } else {
            this->batteryLife = batteryLife;
        }
        this->batteryType = batteryType;
    }

    virtual void printInfo() const override {
        cout << "Модель: " << model << endl;
        cout << "Мощность: " << power << endl;
        cout << "Процессор: " << cpu << endl;
        cout << "ОЗУ: " << ram << endl;
        cout << "Время работы батареи: " << batteryLife << " часов" << endl;
        cout << "Тип батареи: " << batteryType << endl;
    }

    virtual bool operator==(const ComputingMachine& other) const override {
        const Laptop* lp = dynamic_cast<const Laptop*>(&other);
        if (lp)
            return compareBase(other) && (cpu == lp->cpu) && (ram == lp->ram) &&
                   (batteryLife == lp->batteryLife) && (batteryType == lp->batteryType);
        return false;
    }

    virtual Laptop operator+(const ComputingMachine& other) const override {
        const Laptop* lp = dynamic_cast<const Laptop*>(&other);
        if (lp) {
            string newModel = model + " " + lp->model;
            int newPower = power + lp->power;
            string newCpu = cpu + " " + lp->cpu;
            int newRam = ram + lp->ram;
            int newBatteryLife = batteryLife + lp->batteryLife;
            string newBatteryType = batteryType + " " + lp->batteryType;
            return Laptop(newModel, newPower, newCpu, newRam, newBatteryLife, newBatteryType);
        }
        return *this;
    }

    virtual Laptop& operator++() override {
        power++;
        model += "*";
        ram++;
        cpu += "+";
        batteryLife++;
        batteryType += "+";
        return *this;
    }
};

// Планшет
class Tablet : public ComputingMachine {
protected:
    int screenSize;
    string os;

public:
    Tablet() : ComputingMachine() {
        screenSize = 0;
        os = "";
    }

    Tablet(const string& model, int power, int screenSize, const string& os)
        : ComputingMachine(model, power) {
        if (screenSize < 0) {
            cout << "Ошибка: размер экрана не может быть отрицательным. Устанавлино 0." << endl;
            this->screenSize = 0;
        } else {
            this->screenSize = screenSize;
        }
        this->os = os;
    }

    virtual void printInfo() const override {
        cout << "Модель: " << model << endl;
        cout << "Мощность: " << power << endl;
        cout << "Размер экрана: " << screenSize << " дюймов" << endl;
        cout << "ОС: " << os << endl;
    }

    virtual bool operator==(const ComputingMachine& other) const override {
        const Tablet* tb = dynamic_cast<const Tablet*>(&other);
        if (tb)
            return compareBase(other) && (screenSize == tb->screenSize) && (os == tb->os);
        return false;
    }

    virtual Tablet operator+(const ComputingMachine& other) const override {
        const Tablet* tb = dynamic_cast<const Tablet*>(&other);
        if (tb) {
            string newModel = model + " " + tb->model;
            int newPower = power + tb->power;
            int newScreenSize = screenSize + tb->screenSize;
            string newOs = os + " " + tb->os;
            return Tablet(newModel, newPower, newScreenSize, newOs);
        }
        return *this;
    }

    virtual Tablet& operator++() override {
        power++;
        model += "*";
        screenSize++;
        os += "+";
        return *this;
    }
};


// добавление нового элемента
void AddElement(int& count, const int max, ComputingMachine** machines) {
    if (count >= max) {
        cout << "Массив заполнен" << endl;
        return;
    }
    int typeChoice;
    cout << "\nВыберите тип элемента:" << endl;
    cout << "1. Вычислительная машина" << endl;
    cout << "2. Персональный компьютер" << endl;
    cout << "3. Ноутбук" << endl;
    cout << "4. Планшет" << endl;
    cout << "Ваш выбор: ";
    if (!(cin >> typeChoice)) {
        cout << "Ошибка ввода" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    string tempStr;
    int tempInt;
    switch (typeChoice) {
        case 1: {
            string model;
            int power;
            cout << "Введите модель: ";
            cin >> model;
            cout << "Введите мощность (>=0): ";
            if (!(cin >> tempInt)) {
                cout << "Ошибка ввода, элемент не добавлен" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }
            power = tempInt;
            machines[count++] = new ComputingMachine(model, power);
            break;
        }
        case 2: {
            string model, cpu;
            int power, ram;
            cout << "Введите модель: ";
            cin >> model;
            cout << "Введите мощность (>=0): ";
            if (!(cin >> tempInt)) {
                cout << "Ошибка ввода, элемент не добавлен" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }
            power = tempInt;
            cout << "Введите тип процессора: ";
            cin >> cpu;
            cout << "Введите объём ОЗУ (>=0): ";
            if (!(cin >> tempInt)) {
                cout << "Ошибка ввода, элемент не добавлен" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }
            ram = tempInt;
            machines[count++] = new PC(model, power, cpu, ram);
            break;
        }
        case 3: {
            string model, cpu, batteryType;
            int power, ram, batteryLife;
            cout << "Введите модель: ";
            cin >> model;
            cout << "Введите мощность (>=0): ";
            if (!(cin >> tempInt)) {
                cout << "Ошибка ввода, элемент не добавлен" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }
            power = tempInt;
            cout << "Введите тип процессора: ";
            cin >> cpu;
            cout << "Введите объём ОЗУ (>=0): ";
            if (!(cin >> tempInt)) {
                cout << "Ошибка ввода, элемент не добавлен" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }
            ram = tempInt;
            cout << "Введите время работы батареи (>=0): ";
            if (!(cin >> tempInt)) {
                cout << "Ошибка ввода, элемент не добавлен" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }
            batteryLife = tempInt;
            cout << "Введите тип батареи: ";
            cin >> batteryType;
            machines[count++] = new Laptop(model, power, cpu, ram, batteryLife, batteryType);
            break;
        }
        case 4: {
            string model, os;
            int power, screenSize;
            cout << "Введите модель: ";
            cin >> model;
            cout << "Введите мощность (>=0): ";
            if (!(cin >> tempInt)) {
                cout << "Ошибка ввода, элемент не добавлен" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }
            power = tempInt;
            cout << "Введите размер экрана (>=0): ";
            if (!(cin >> tempInt)) {
                cout << "Ошибка ввода, элемент не добавлен" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                return;
            }
            screenSize = tempInt;
            cout << "Введите операционную систему: ";
            cin >> os;
            machines[count++] = new Tablet(model, power, screenSize, os);
            break;
        }
        default:
            cout << "Некорректный выбор" << endl;
            break;
    }
    cout << "Элемент добавлен" << endl;
}

// удаление элемента
void RemoveElement(int& count, ComputingMachine** machines) {
    if (count == 0) {
        cout << "Нет элементов для удаления" << endl;
        return;
    }
    int index;
    cout << "Введите индекс удаляемого элемента (от 0 до " << count - 1 << "): ";
    if (!(cin >> index)) {
        cout << "Ошибка ввода" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    if (index < 0 || index >= count) {
        cout << "Некорректный индекс" << endl;
        return;
    }
    delete machines[index];
    for (int i = index; i < count - 1; i++) {
        machines[i] = machines[i + 1];
    }
    count--;
    cout << "Элемент удалён" << endl;
}

// вывод
void ViewElements(int count, ComputingMachine** machines) {
    if (count == 0) {
        cout << "Нет элементов для вывода" << endl;
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "\nИндекс " << i << ":" << endl;
        machines[i]->printInfo();
    }
}

// сравнения двух элементов
void CompareElements(int count, ComputingMachine** machines) {
    if (count < 2) {
        cout << "Недостаточно элементов для сравнения" << endl;
        return;
    }
    int index1, index2;
    cout << "Введите первый индекс (от 0 до " << count - 1 << "): ";
    if (!(cin >> index1)) {
        cout << "Ошибка ввода" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    cout << "Введите второй индекс (от 0 до " << count - 1 << "): ";
    if (!(cin >> index2)) {
        cout << "Ошибка ввода" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    if (index1 < 0 || index1 >= count || index2 < 0 || index2 >= count) {
        cout << "Некорректный индекс" << endl;
        return;
    }
    if (*machines[index1] == *machines[index2])
        cout << "Элементы равны" << endl;
    else
        cout << "Элементы не равны" << endl;
}


int main() {
    setlocale(LC_ALL, "ru");

    const int max = 100;
    ComputingMachine** machines = new ComputingMachine*[max];
    int count = 0;

    int choice = 123;
    while (choice != 0) {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить новый элемент" << endl;
        cout << "2. Удалить элемент по индексу" << endl;
        cout << "3. Вывести все элементы" << endl;
        cout << "4. Сравнить два элемента по индексам" << endl;
        cout << "0. Завершение работы" << endl;
        cout << "Ваш выбор: ";
        if (!(cin >> choice)) {
            cout << "Ошибка ввода" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        switch (choice) {
            case 1:
                AddElement(count, max, machines);
                break;
            case 2:
                RemoveElement(count, machines);
                break;
            case 3:
                ViewElements(count, machines);
                break;
            case 4:
                CompareElements(count, machines);
                break;
            case 0:
                cout << "Завершение работы" << endl;
                break;
            default:
                cout << "Введите число от 0 до 4" << endl;
                break;
        }
    }
    delete[] machines;
}