#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    const char* suits[] = {"Черви", "Бубны", "Крести", "Пики"};
    const char* ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Валет", "Дама", "Король", "Туз"};

    const int totalCards = 52;
    const int suitsCount = 4;
    const int ranksCount = 13;
    char deck[totalCards][30];
    bool used[totalCards] = {false};

    int index = 0;
    for (int i = 0; i < suitsCount; i++) {
        for (int j = 0; j < ranksCount; j++) {
            snprintf(deck[index], sizeof(deck[index]), "%s %s", ranks[j], suits[i]);
            index++;
        }
    }

    srand(time(0));

    int cardsDealt = 0;
    while (cardsDealt < totalCards) {
        cout << "Нажмите Enter, чтобы сдать карту...";
        cin.ignore();
        int randomIndex;
        do {
            randomIndex = rand() % totalCards;
        } while (used[randomIndex]);

        used[randomIndex] = true;
        cout << deck[randomIndex] << endl;
        cardsDealt++;
    }

    cout << "Нет больше карт." << endl;

}
