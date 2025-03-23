#include <iostream>
#include <string>
using namespace std;

class ElectricVehicle {
protected:

    int batteryLevel;

public:

    ElectricVehicle() {
        batteryLevel = 0;
    }
    void charge(int amount) {
        batteryLevel += amount;
        cout << "Заряд батареи увеличен на " << amount << " единиц" << endl;
    }
    void showBattery() {
        cout << "Текущий уровень заряда батареи: " << batteryLevel << endl;
    }
};

class LandTransport {
protected:

    int speed;

public:

    LandTransport() {
        speed = 0;
    }
    virtual void accelerate(int value) {
        speed += value;
        cout << "Скорость увеличена на " << value << " кмч" << endl;
    }
    virtual void brake(int value) {
        speed -= value;
        if (speed < 0) speed = 0;
        cout << "Скорость уменьшена на " << value << " кмч" << endl;
    }
    virtual void showSpeed() {
        cout << "Текущая скорость: " << speed << " кмч" << endl;
    }
    virtual void printTransportType() {
        cout << "Наземный транспорт" << endl;
    }
};

class WaterTransport {
protected:

    int depth;

public:

    WaterTransport() {
        depth = 0;
    }
    virtual void dive(int value) {
        depth += value;
        cout << "Глубина увеличена на " << value << endl;
    }
    virtual void surface(int value) {
        depth -= value;
        if (depth < 0) depth = 0;
        cout << "Глубина уменьшена на " << value << endl;
    }
    virtual void showDepth() {
        cout << "Текущая глубина: " << depth << endl;
    }
    virtual void printTransportType() {
        cout << "Водный транспорт" << endl;
    }
};

class ElectricCar : virtual public ElectricVehicle, public LandTransport {
public:

    ElectricCar() : ElectricVehicle(), LandTransport() {}
    void drive() {
        cout << "Электромобиль едет по дороге" << endl;
        showBattery();
        showSpeed();
    }
    virtual void printTransportType() override {
        cout << "Электромобиль наземный транспорт" << endl;
    }
    void mode() {
        cout << "Режим наземного транспорта" << endl;
    }
    virtual void accelerate(int value) override {
        speed += value;
        cout << "Электромобиль ускоряется на " << value << " кмч" << endl;
    }
    virtual void brake(int value) override {
        speed -= value;
        if (speed < 0) speed = 0;
        cout << "Электромобиль тормозит на " << value << " кмч" << endl;
    }
};

class ElectricBoat : virtual public ElectricVehicle, public WaterTransport {
public:

    ElectricBoat() : ElectricVehicle(), WaterTransport() {}
    void sail() {
        cout << "Электрическая лодка плывет по воде" << endl;
        showBattery();
        showDepth();
    }
    virtual void printTransportType() override {
        cout << "Электрическая лодка водный транспорт" << endl;
    }
    void mode() {
        cout << "Режим водного транспорта" << endl;
    }
    virtual void dive(int value) override {
        depth += value;
        cout << "Электрическая лодка погружается на " << value << endl;
    }
    virtual void surface(int value) override {
        depth -= value;
        if (depth < 0) depth = 0;
        cout << "Электрическая лодка всплывает на " << value << endl;
    }
};

class AmphibiousVehicle : public ElectricCar, public ElectricBoat {
public:

    AmphibiousVehicle() : ElectricCar(), ElectricBoat() {}
    void switchToLandMode() {
        cout << "Переключение в режим наземного транспорта" << endl;
        ElectricCar::mode();
        ElectricCar::printTransportType();
        drive();
    }
    void switchToWaterMode() {
        cout << "Переключение в режим водного транспорта" << endl;
        ElectricBoat::mode();
        ElectricBoat::printTransportType();
        sail();
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    ElectricCar car;
    ElectricBoat boat;
    AmphibiousVehicle amphibious;

    cout << "\nElectricCar:" << endl;
    car.charge(50);
    car.accelerate(60);
    car.drive();
    car.brake(20);
    car.showSpeed();
    car.showBattery();

    cout << "\nElectricBoat:" << endl;
    boat.charge(70);
    boat.dive(10);
    boat.sail();
    boat.surface(5);
    boat.showDepth();
    boat.showBattery();

    cout << "\nAmphibiousVehicle:" << endl;
    amphibious.charge(100);
    amphibious.switchToLandMode();
    amphibious.accelerate(80);
    amphibious.showSpeed();
    amphibious.switchToWaterMode();
    amphibious.dive(15);
    amphibious.showDepth();
    amphibious.showBattery();

}