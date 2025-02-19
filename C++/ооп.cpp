#include <iostream>
#include <string>
using namespace std;

class FoodProduct {
private:
    string name;
    string manufacturer;
    float price;
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

    FoodProduct(const string& name, const string& manufacturer, float price, int weight, bool isSpoile)
    {
        this->name = name;
        this->manufacturer = manufacturer;
        this->price = price;
        this->weight = weight;
        this->isSpoiled = isSpoiled;
    }

    string getName() const { return name; }
    string getManufacturer() const { return manufacturer; }
    float getPrice() const { return price; }
    int getWeight() const { return weight; }
    bool getIsSpoiled() const { return isSpoiled; }

    void setName(const string& n) { name = n; }
    void setManufacturer(const string& man) { manufacturer = man; }
    void setPrice(float p) { price = p; }
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

void AddEmptyObject(int &productCount, int max, FoodProduct* products)
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

void AddObject(int &productCount, int max, FoodProduct* products)
{
    if (productCount < max) {
        string name;
        string manufacturer;
        float price;
        int weight;
        int spoiledInt;
        bool isSpoiled;

        cout << "Введите название продукта: ";
        cin >> name;
        cout << "Введите производителя: ";
        cin >> manufacturer;
        cout << "Введите цену: ";
        cin >> price;
        cout << "Введите вес: ";
        cin >> weight;
        cout << "Продукт испорчен? (0 - свежий, 1 - испорчен): ";
        cin >> spoiledInt;
        isSpoiled = (spoiledInt != 0);

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
    }
    else {
        int index;
        cout << "Введите индекс объекта (от 0 до " << productCount - 1 << "): ";
        cin >> index;
        if (index < 0 || index >= productCount) {
            cout << "Некорректный индекс" << endl;
        }
        else {
            cout << "Какое поле редактировать?" << endl;
            cout << "1. Название" << endl;
            cout << "2. Производитель" << endl;
            cout << "3. Цена" << endl;
            cout << "4. Вес" << endl;
            cout << "5. Состояние (0 - свежий, 1 - испорчен)" << endl;

            int fieldChoice;
            cin >> fieldChoice;
            if (fieldChoice == 1) {
                string newName;
                cout << "Введите новое название: ";
                cin >> newName;
                products[index].setName(newName);
            }
            else if (fieldChoice == 2) {
                string newManufacturer;
                cout << "Введите нового производителя: ";
                cin >> newManufacturer;
                products[index].setManufacturer(newManufacturer);
            }
            else if (fieldChoice == 3) {
                float newPrice;
                cout << "Введите новую цену: ";
                cin >> newPrice;
                products[index].setPrice(newPrice);
            }
            else if (fieldChoice == 4) {
                int newWeight;
                cout << "Введите новый вес: ";
                cin >> newWeight;
                products[index].setWeight(newWeight);
            }
            else if (fieldChoice == 5) {
                int newStatus;
                cout << "Введите состояние (0 - свежий, 1 - испорчен): ";
                cin >> newStatus;
                products[index].setIsSpoiled(newStatus != 0);
            }
            else {
                cout << "Ошибка: Введите число в диапазоне от 1 до 5" << endl;
            }
            cout << "Объект изменён" << endl;
        }
    }
}

void View(int productCount, FoodProduct* products)
{
    if (productCount == 0) {
        cout << "Нет объектов для вывода" << endl;
    }
    else {
        for (int i = 0; i < productCount; i++) {
            cout << "\nИндекс " << i << ": " << endl;
            products[i].printInfo();
        }
    }
}

void Sort(int productCount, FoodProduct* products)
{
    if (productCount == 0) {
        cout << "Нет объектов для сортировки" << endl;
    }
    else {
        cout << "Сортировать по:" << endl;
        cout << "1. Названию" << endl;
        cout << "2. Производителю" << endl;
        cout << "3. Цене" << endl;
        cout << "4. Весу" << endl;
        int sortChoice;
        cin >> sortChoice;
        if (sortChoice < 1 || sortChoice > 4) {
            cout << "Ошибка: Введите число в диапазоне от 1 до 4" << endl;
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
                    FoodProduct temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
        cout << "Сортировка завершена" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Ru");

    const int max = 100;
    FoodProduct products[max];
    
    int productCount = 0;
    int choice = 123;

    while (choice != 0) {
        cout << "\nМеню:" << endl;
        cout << "1. Добавить пустой объект (конструктор по умолчанию)" << endl;
        cout << "2. Добавить объект с данными (конструктор с параметрами)" << endl;
        cout << "3. Редактировать поле объекта по индексу" << endl;
        cout << "4. Вывести информацию обо всех объектах" << endl;
        cout << "5. Отсортировать объекты по выбранному полю (по возрастанию)" << endl;
        cout << "0. Выход" << endl;
        cout << "\nВаш выбор: ";
        cin >> choice;

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
            cout << "Ошибка: Введите число в диапазоне от 0 до 5" << endl;
            break;
        }
    }
}