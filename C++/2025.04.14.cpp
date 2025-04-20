#include <iostream>
using namespace std;

class Sword {
public:
    virtual void describe() const = 0;
    virtual ~Sword() {}
};

class NorwegianSword : public Sword {
public:
    void describe() const override {
        cout << "норв меч: тяжелый и прочный\n";
    }
};

class JapaneseSword : public Sword {
public:
    void describe() const override {
        cout << "япон меч: острый и изящный\n";
    }
};

class Blacksmith {
public:
    virtual Sword* createSword() const = 0;
    virtual ~Blacksmith() {}
};

class NorwegianBlacksmith : public Blacksmith {
public:
    Sword* createSword() const override {
        return new NorwegianSword();
    }
};

class JapaneseBlacksmith : public Blacksmith {
public:
    Sword* createSword() const override {
        return new JapaneseSword();
    }
};

void requestSword(const Blacksmith& blacksmith) {
    Sword* sword = blacksmith.createSword();
    sword->describe();
    delete sword;
}

int main() {
    NorwegianBlacksmith norseSmith;
    JapaneseBlacksmith japaneseSmith;

    requestSword(norseSmith);
    requestSword(japaneseSmith);

}

//#######################################################################################################################

#include <iostream>
using namespace std;

class Government {
private:
    static Government* instance;
    string countryName;

    Government() : countryName("неназванная страна") {}
    Government(const Government&) = delete;
    Government& operator=(const Government&) = delete;

public:
    static Government& getInstance() {
        static Government instance;
        return instance;
    }

    void setCountryName(const string& name) {
        countryName = name;
    }

    void display() const {
        cout << "правительство страны " << countryName << endl;
    }
};

int main() {
    Government& qwe1 = Government::getInstance();
    qwe1.setCountryName("Россия");
    qwe1.display();

    Government& qwe2 = Government::getInstance();
    qwe2.display();
}