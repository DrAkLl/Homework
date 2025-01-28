#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я';
}

int main() {
    setlocale(LC_ALL, "Russian");

    ofstream outFile("example.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < 10; i++) {
            outFile << "привет, мир!\n";
        }
        outFile.close();
    }

    ifstream inFile("example.txt");
    if (inFile.is_open()) {
        int lineCount = 0;
        string line;
        while (getline(inFile, line)) {
            lineCount++;
            int vowelCount = 0;
            for (char c : line) {
                if (isVowel(c)) vowelCount++;
            }
            cout << "Строка " << lineCount << ": " << line << " (гласных: " << vowelCount << ")" << endl;
        }
        cout << "Всего строк: " << lineCount << endl;
        inFile.close();
    }

    ofstream numFile("numbers.txt");
    if (numFile.is_open()) {
        for (int i = 0; i < 20; i++) {
            numFile << i + 1 << " ";
        }
        numFile.close();
    }

    ifstream srcFile("numbers.txt");
    ofstream destFile("numbers_copy.txt");
    if (srcFile.is_open() && destFile.is_open()) {
        string content;
        while (getline(srcFile, content)) {
            destFile << content << endl;
        }
        srcFile.close();
        destFile.close();
    }

    return 0;
}
