#include <iostream>
#include <string>
using namespace std;

class FoodProduct
{
private:
    string name;
    string manufacturer;
    int price;
    int weight;
    bool isSpoiled;

public:
    FoodProduct()
    {
        name = "";
        manufacturer = "";
        price = 0;
        weight = 0;
        isSpoiled = false;
    }

    FoodProduct(const string& name, const string& manufacturer, int price, int weight, bool isSpoiled)
    {
        this->name = name;
        this->manufacturer = manufacturer;
        this->price = price;
        this->weight = weight;
        this->isSpoiled = isSpoiled;
    }

    string getName() const { return name; }
    string getManufacturer() const { return manufacturer; }
    int getPrice() const { return price; }
    int getWeight() const { return weight; }
    bool getIsSpoiled() const { return isSpoiled; }

    void setName(const string& n) { name = n; }
    void setManufacturer(const string& man) { manufacturer = man; }
    void setPrice(int p) { price = p; }
    void setWeight(int w) { weight = w; }
    void setIsSpoiled(bool spoiled) { isSpoiled = spoiled; }

    void printInfo() const
    {
        cout << "Название: " << name << endl;
        cout << "Производитель: " << manufacturer << endl;
        cout << "Цена: " << price << endl;
        cout << "Вес: " << weight << endl;
        cout << "Состояние: " << (isSpoiled ? "Испорчен" : "Свежий") << endl;
    }
};

void AddEmptyObject(int& productCount, int max, FoodProduct* products)
{
    if (productCount < max) {
        products[productCount] = FoodProduct();
        productCount++;
        cout << "Пустой объект добавлен" << endl;
    }
    else {
        cout << "Массив заполнен" << endl;
    }
}

void AddObject(int& productCount, int max, FoodProduct* products)
{
    if (productCount < max) {
        string name;
        string manufacturer;
        int price;
        int weight;
        int spoiledInt;
        bool isSpoiled; 

        cout << "Введите название продукта: ";
        cin >> name;
        cout << "Введите производителя: ";
        cin >> manufacturer;
        cout << "Введите цену: ";
        if (!(cin >> price)) {
            cout << "Ошибка: неверный ввод, добавление объекта прервано" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        cout << "Введите вес: ";
        if (!(cin >> weight)) {
            cout << "Ошибка: неверный ввод, добавление объекта прервано" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        cout << "Продукт испорчен? (0 - свежий, 1 - испорчен): ";
        if (!(cin >> spoiledInt)) {
            cout << "Ошибка: неверный ввод, добавление объекта прервано" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        if (spoiledInt == 0) {
            isSpoiled = false;
        }
        else if (spoiledInt == 1) {
            isSpoiled = true;
        }
        else {
            cout << "Ошибка: введите число от 0 до 1" << endl;
            return;
        }
        FoodProduct productToAdd(name, manufacturer, price, weight, isSpoiled);
        products[productCount] = productToAdd;
        productCount++;
        cout << "Объект добавлен" << endl;
    }
    else {
        cout << "Массив заполнен" << endl;
    }
}

void Edit(int productCount, FoodProduct* products)
{
    if (productCount == 0) {
        cout << "Нет доступных объектов для редактирования" << endl;
        return;
    }
    int index;
    cout << "Введите индекс объекта (от 0 до " << productCount - 1 << "): ";
    if (!(cin >> index)) {
        cout << "Ошибка: неверный ввод, изменение объекта прервано" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    if (index < 0 || index >= productCount) {
        cout << "Некорректный индекс" << endl;
        return;
    }

    cout << "Какое поле редактировать?" << endl;
    cout << "1. Название" << endl;
    cout << "2. Производитель" << endl;
    cout << "3. Цена" << endl;
    cout << "4. Вес" << endl;
    cout << "5. Состояние (0 - свежий, 1 - испорчен)" << endl;
    int editChoice;
    if (!(cin >> editChoice)) {
        cout << "Ошибка: неверный ввод, изменение объекта прервано" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    switch (editChoice) {
    case 1: {
        cout << "Введите новое название: ";
        string newName;
        cin >> newName;
        products[index].setName(newName);
        break;
    }
    case 2: {
        cout << "Введите нового производителя: ";
        string newManufacturer;
        cin >> newManufacturer;
        products[index].setManufacturer(newManufacturer);
        break;
    }
    case 3: {
        cout << "Введите новую цену: ";
        int newPrice;
        if (!(cin >> newPrice)) {
            cout << "Ошибка: неверный ввод, изменение объекта прервано" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        products[index].setPrice(newPrice);
        break;
    }
    case 4: {
        cout << "Введите новый вес: ";
        int newWeight;
        if (!(cin >> newWeight)) {
            cout << "Ошибка: неверный ввод, изменение объекта прервано" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        products[index].setWeight(newWeight);
        break;
    }
    case 5: {
        cout << "Введите состояние (0 - свежий, 1 - испорчен): ";
        int newStatus;
        if (!(cin >> newStatus)) {
            cout << "Ошибка: неверный ввод, изменение объекта прервано" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        if (newStatus == 0) {
            products[index].setIsSpoiled(false);
        }
        else if (newStatus == 1) {
            products[index].setIsSpoiled(true);
        }
        else {
            cout << "Ошибка: введите число от 0 до 1" << endl;
            return;
        }
    }
    default:
        cout << "Ошибка: введите число от 1 до 5" << endl;
        return;
    }
    cout << "Объект изменён" << endl;
}

void View(int productCount, FoodProduct* products)
{
    if (productCount == 0) {
        cout << "Нет объектов для вывода" << endl;
    }
    else {
        for (int i = 0; i < productCount; i++) {
            cout << "\nИндекс " << i << ":" << endl;
            products[i].printInfo();
        }
    }
}

void Sort(int productCount, FoodProduct* products)
{
    if (productCount == 0) {
        cout << "Нет объектов для сортировки" << endl;
        return;
    }
    cout << "Сортировать по:" << endl;
    cout << "1. Названию" << endl;
    cout << "2. Производителю" << endl;
    cout << "3. Цене" << endl;
    cout << "4. Весу" << endl;
    int sortChoice;
    if (!(cin >> sortChoice)) {
        cout << "Ошибка: неверный ввод, сортировка прервана" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    if (sortChoice < 1 || sortChoice > 4) {
        cout << "Ошибка: введите число от 1 до 4" << endl;
        return;
    }
    for (int i = 0; i < productCount - 1; i++) {
        for (int j = 0; j < productCount - i - 1; j++) {
            bool needSwap = false;
            if (sortChoice == 1) {
                if (products[j].getName() > products[j + 1].getName())
                    needSwap = true;
            }
            else if (sortChoice == 2) {
                if (products[j].getManufacturer() > products[j + 1].getManufacturer())
                    needSwap = true;
            }
            else if (sortChoice == 3) {
                if (products[j].getPrice() > products[j + 1].getPrice())
                    needSwap = true;
            }
            else if (sortChoice == 4) {
                if (products[j].getWeight() > products[j + 1].getWeight())
                    needSwap = true;
            }
            if (needSwap) {
                FoodProduct t = products[j];
                products[j] = products[j + 1];
                products[j + 1] = t;
            }
        }
    }
    cout << "Сортировка завершена" << endl;
}

int main() {
    setlocale(LC_ALL, "Ru");

    const int max = 100;
    FoodProduct* products = new FoodProduct[max];
    int productCount = 0;

    int choice = 123;
    while (choice != 0) {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить пустой объект" << endl;
        cout << "2. Добавить объект с данными" << endl;
        cout << "3. Редактировать поле объекта по индексу" << endl;
        cout << "4. Вывести информацию обо всех объектах" << endl;
        cout << "5. Отсортировать объекты по выбранному полю (по возрастанию)" << endl;
        cout << "0. Выход" << endl;
        cout << "\nВаш выбор: ";
        if (!(cin >> choice)) {
            cout << "Ошибка: неверный ввод" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            AddEmptyObject(productCount, max, products);
            break;
        case 2:
            AddObject(productCount, max, products);
            break;
        case 3:
            Edit(productCount, products);
            break;
        case 4:
            View(productCount, products);
            break;
        case 5:
            Sort(productCount, products);
            break;
        case 0:
            cout << "Выход" << endl;
            break;
        default:
            cout << "Ошибка: введите число от 0 до 5" << endl;
            break;
        }
    }
    delete[] products;
}