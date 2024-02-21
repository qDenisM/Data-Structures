#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct LeaseAgreement {
    string tenantLastName;
};

LeaseAgreement leaseAgreements[100]; 
int numLeaseAgreements = 0;

void printMenu() {
    cout << "===== Управление Торговым Центром =====\n";
    cout << "1. Добавить фамилию арендатора\n";
    cout << "2. Поиск договора аренды по фамилии арендатора\n";
    cout << "3. Выйти\n";
    cout << "Введите номер действия: ";
}

void searchLeaseAgreementByLastName() {
    string lastName;
    cout << "Введите фамилию арендатора для поиска: ";
    cin >> lastName;

    bool found = false;
    for (int i = 0; i < numLeaseAgreements; ++i) {
        if (leaseAgreements[i].tenantLastName.find(lastName) != string::npos) {
            found = true;
            cout << "Фамилия арендатора: " << leaseAgreements[i].tenantLastName << endl;
        }
    }

    if (!found) {
        cout << "Договор аренды с фамилией арендатора '" << lastName << "' не найден.\n";
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Введите фамилию арендатора: ";
            cin >> leaseAgreements[numLeaseAgreements].tenantLastName;
            numLeaseAgreements++;
            break;
        case 2:
            searchLeaseAgreementByLastName();
            break;
        case 3:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 3);

    return 0;
}
