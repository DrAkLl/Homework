#include <iostream>

using namespace std;

class Pudge {
private:

    int Health;
    int Armour;

public:

    Pudge() : Health(100), Armour(50) { }

    Pudge(int health, int armour):Health(health), Armour(armour){}

    void FreshMeat() {
        const int increase = 25;
        Health += increase;
        Armour += increase;
        cout << "Pudge потребил свежего мяса: +" << increase << " к Health и Armour"<< endl; }

    void PrintStatus() const {
        cout << "текущее состояние: Health = " << Health << ", Armour = " << Armour << endl; }
    
    void TakeDamage(int damage) {
        cout << "Pudge получает урон: " << damage << endl;
        if (Armour >= damage) {
            Armour -= damage;
        } else {
            int remainingDamage = damage - Armour;
            Armour = 0;
            Health -= remainingDamage;
            if (Health < 0) {
                Health = 0;
            }
        }
    }
};

int main() {
    Pudge pudge;
    
    cout << "Начальное состояние:" << endl;
    pudge.PrintStatus();
    
    pudge.FreshMeat();
    
    cout << "\nПосле употребления свежего мяса:" << endl;
    pudge.PrintStatus();
    
    pudge.TakeDamage(30);
    cout << "\nПосле получения урона:" << endl;
    pudge.PrintStatus();
    
    return 0;
}
