#include <iostream>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	
    int n;
    cout << "размер вектора: ";
    cin >> n;
    vector<int> numbers(n);

    int number;
    for (int i = 0; i < numbers.size(); ++i) {
        cout << i << ": ";
        cin >> numbers[i];
    }

    for (int i = numbers.size() - 1; i >= 0; --i) {
        cout << numbers[i] << " ";
    }

}


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Ru");

    int n;
    cout << "размер вектора: ";
    cin >> n;
    vector<string> numbers(n);

    for (int i = 0; i < numbers.size(); ++i) {
        cout << i << ": ";
        cin >> numbers[i];
    }

    string j;
    cout << "добавить ещё елемент: ";
    cin >> j;
    numbers.push_back(j);

    for (int i = numbers.size() - 1; i >= 0; --i) {
        cout << numbers[i] << " ";
    }
}
