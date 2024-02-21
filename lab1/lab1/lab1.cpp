#include <iostream>
#include <deque>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    deque<int> deque;
    int size;
    cout << "Введите количество элементов в деке: ";
    cin >> size;

    cout << "Введите элементы деки:" << endl;
    for (int i = 0; i < size; ++i) {
        int element;
        cin >> element;
        deque.push_back(element);
    }

    int product = 1;

    for (int num : deque) {
        product *= num;
    }

    cout << "Произведение всех элементов деки: " << product << endl;

    return 0;
}