#include <iostream>
#include <string>
using namespace std;

class BattleUnit {
private:
    int health;
    int damage;
    string unitType;
    static int totalHealth;
    static int totalDamage;

public:
    BattleUnit(int health, int damage, string unitType)
        : health(health), damage(damage), unitType(unitType) {
        totalHealth += health;
        totalDamage += damage;
    }
    
    int GetHealth() const { return health; }
    int GetDamage() const { return damage; }
    string GetUnitType() const { return unitType; }
    static int GetTotalHealth() { return totalHealth; }
    static int GetTotalDamage() { return totalDamage; }
    
    void SetHealth(int health) {
        totalHealth = totalHealth - this->health + health;
        this->health = health; }
    
    void SetDamage(int damage) {
        totalDamage = totalDamage - this->damage + damage;
        this->damage = damage; }
    
    void SetUnitType(const string& unitType) {
        this->unitType = unitType; }
    
    void increaseHealth(int amount) {
        health += amount;
        totalHealth += amount; }
    
    void decreaseHealth(int amount) {
        health -= amount;
        totalHealth -= amount; }
    
    void increaseDamage(int amount) {
        damage += amount;
        totalDamage += amount; }
    
    void decreaseDamage(int amount) {
        damage -= amount;
        totalDamage -= amount; }
};


int BattleUnit::totalHealth = 0;
int BattleUnit::totalDamage = 0;

int main() {
    BattleUnit unit1(100, 20, "пехота");
    BattleUnit unit2(150, 30, "конница");

    cout << "здоровье unit1: " << unit1.GetHealth() << endl;
    cout << "здоровье unit2: " << unit2.GetHealth() << endl;
    cout << "общее здоровье армии: " << BattleUnit::GetTotalHealth() << endl;
    cout << "общий урон армии: " << BattleUnit::GetTotalDamage() << endl;

    unit1.increaseHealth(50);
    cout << "после увеличения здоровья unit1 на 50:" << endl;
    cout << "здоровье unit1: " << unit1.GetHealth() << endl;
    cout << "общее здоровье армии: " << BattleUnit::GetTotalHealth() << endl;

}
