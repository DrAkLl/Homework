#include <iostream>
using namespace std;

class Logger {
public:
    virtual void log(string t) = 0;
};

class ConsoleLogger : public Logger {
public:
    void log(string t) override {
        cout << ": " << t << endl;
    }
};

class Application {
private:
    Logger* log;

public:
    Application(Logger* log) {
        this->log = log;
    }

    void run() {
        log->log("+");
        log->log("-");
    }
};

int main() {
    ConsoleLogger log;
    Application app(&log);

    app.run();
}