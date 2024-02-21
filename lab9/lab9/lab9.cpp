#include <iostream>
#include <string>

using namespace std;

struct TradingPoint {
    string name;
    string address;
};

struct LeaseAgreement {
    string tenantName;
    string tradingPointName;
};

const int MAX_TRADING_POINTS = 100;
const int MAX_LEASE_AGREEMENTS = 100;

TradingPoint tradingPoints[MAX_TRADING_POINTS];
LeaseAgreement leaseAgreements[MAX_LEASE_AGREEMENTS];
int tradingPointCount = 0;
int leaseAgreementCount = 0;

int findTradingPointIndex(const string& tradingPointName) {
    for (int i = 0; i < tradingPointCount; ++i) {
        if (tradingPoints[i].name == tradingPointName) {
            return i;
        }
    }
    return -1;
}

int binarySearchBySurname(const string& surname) {
    int left = 0;
    int right = leaseAgreementCount - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (leaseAgreements[mid].tenantName == surname) {
            return mid;
        }
        else if (leaseAgreements[mid].tenantName < surname) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

void printMenu() {
    cout << "===== Управление Торговым Центром =====\n";
    cout << "1. Показать доступные торговые точки\n";
    cout << "2. Добавить новую торговую точку\n";
    cout << "3. Добавить новый договор аренды\n";
    cout << "4. Поиск договора аренды по фамилии арендатора\n";
    cout << "5. Поиск индекса в массиве торговых точек по названию\n";
    cout << "6. Показать все договоры аренды\n";
    cout << "7. Выйти\n";
    cout << "Введите номер действия: ";
}

int main() {
    setlocale(LC_ALL, "ru");
    int choice;
    string surname;
    string tpName;
    int index = -1; 
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            for (int i = 0; i < tradingPointCount; ++i) {
                cout << "Торговая точка: " << tradingPoints[i].name << endl;
                cout << "Адрес: " << tradingPoints[i].address << endl;
            }
            break;
        case 2:
            if (tradingPointCount < MAX_TRADING_POINTS) {
                cout << "Введите название торговой точки: ";
                cin >> tradingPoints[tradingPointCount].name;
                cout << "Введите адрес торговой точки: ";
                cin >> tradingPoints[tradingPointCount].address;
                tradingPointCount++;
            }
            else {
                cout << "Достигнуто максимальное количество торговых точек." << endl;
            }
            break;
        case 3:
            if (leaseAgreementCount < MAX_LEASE_AGREEMENTS) {
                cout << "Введите имя арендатора: ";
                cin >> leaseAgreements[leaseAgreementCount].tenantName;
                cout << "Введите название торговой точки: ";
                cin >> leaseAgreements[leaseAgreementCount].tradingPointName;
                leaseAgreementCount++;
            }
            else {
                cout << "Достигнуто максимальное количество договоров аренды." << endl;
            }
            break;
        case 4:
            cout << "Введите фамилию арендатора для поиска договора: ";
            cin >> surname;
            index = binarySearchBySurname(surname);
            if (index != -1) {
                cout << "Договор аренды найден:" << endl;
                cout << "Арендатор: " << leaseAgreements[index].tenantName << endl;
                cout << "Торговая точка: " << leaseAgreements[index].tradingPointName << endl;
            }
            else {
                cout << "Договор аренды не найден." << endl;
            }
            break;
        case 5:
            cout << "Введите название торговой точки для поиска: ";
            cin >> tpName;
            index = findTradingPointIndex(tpName);
            if (index != -1) {
                cout << "Торговая точка найдена:" << endl;
                cout << "Название: " << tradingPoints[index].name << endl;
                cout << "Адрес: " << tradingPoints[index].address << endl;
            }
            else {
                cout << "Торговая точка не найдена." << endl;
            }
            break;
        case 6:
            for (int i = 0; i < leaseAgreementCount; ++i) {
                cout << "Арендатор: " << leaseAgreements[i].tenantName << endl;
                cout << "Торговая точка: " << leaseAgreements[i].tradingPointName << endl;
            }
            break;
        case 7:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 7);

    return 0;
}

