#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Pudge {
private:
    int Health;
    int Armour;
    string* abilities;
    int abilityCount;

public:

    Pudge(int health, int armour, const string initAbilities[], int count)
        : Health(health), Armour(armour), abilityCount(count) {
        abilities = new string[abilityCount];
        for (int i = 0; i < abilityCount; ++i) {
            abilities[i] = initAbilities[i];
        }
    }

    ~Pudge() {
        delete[] abilities;
    }

    void FreshMeat(int bonus) {
        Health += bonus;
        Armour += bonus;
    }

    void printStatus() const {
        cout << "Здоровье: " << Health << ", Броня: " << Armour << endl;
    }

    void printRandomAbility() const {
        if (abilityCount == 0) {
            cout << "Нет способностей для выбора" << endl;
            return;
        }
        int randomIndex = rand() % abilityCount;
        cout << "Случайная способность: " << abilities[randomIndex] << endl;
    }

    int getDamage(int stat, int abilityIndex) const {
        if (abilityIndex < 0 || abilityIndex >= abilityCount) {
            cerr << "Ошибка: неверный индекс способности" << endl;
            return 0;
        }
        string ability = abilities[abilityIndex];
        int multiplier = 1;
        if (ability == "Hook")
            multiplier = 2;
        else if (ability == "Rot")
            multiplier = 1;
        else if (ability == "Dismember")
            multiplier = 3;
        else
            multiplier = 1;
        return stat * multiplier;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int numAbilities = 3;
    string abilities[numAbilities] = {"Hook", "Rot", "Dismember"};

    Pudge pudge(100, 50, abilities, numAbilities);
    pudge.FreshMeat(20);
    pudge.printStatus();
    pudge.printRandomAbility();

    int stat = 10;
    int abilityIndex = 0;
    int damage = pudge.getDamage(stat, abilityIndex);
    cout << "Урон от способности \"" << abilities[abilityIndex]
         << "\" при стате " << stat << " равен: " << damage << endl;

    return 0;
}