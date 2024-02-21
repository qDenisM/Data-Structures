#include <iostream>
#include <string>

using namespace std;

void printMenu() {
    cout << "===== Управление Торговым Центром =====\n";
    cout << "1. Показать доступные торговые точки\n";
    cout << "2. Добавить новую торговую точку\n";
    cout << "3. Добавить новый договор аренды\n";
    cout << "4. Показать все договоры аренды\n";
    cout << "5. Выйти\n";
    cout << "Введите номер действия: ";
}

int main() {
    int choice;
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 5);

    return 0;
}