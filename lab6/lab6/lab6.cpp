#include <iostream>
#include <string>

using namespace std;

const int MAX_TRADING_POINTS = 100;
const int MAX_LEASE_CONTRACTS = 100;

struct TradingPoint {
    string name;
    string location;
    double area;
};

struct LeaseContract {
    string tradingPointName;
    string tenantName;
    double rentAmount;
};

TradingPoint tradingPoints[MAX_TRADING_POINTS];
LeaseContract leaseContracts[MAX_LEASE_CONTRACTS];

int tradingPointsCount = 0;
int leaseContractsCount = 0;

void addTradingPoint() {
    if (tradingPointsCount < MAX_TRADING_POINTS) {
        TradingPoint point;
        cout << "Введите название торговой точки: ";
        cin >> point.name;
        cout << "Введите местоположение торговой точки: ";
        cin >> point.location;
        cout << "Введите площадь торговой точки: ";
        cin >> point.area;
        tradingPoints[tradingPointsCount++] = point;
    }
    else {
        cout << "Невозможно добавить новую торговую точку. Максимальное количество достигнуто.\n";
    }
}

void deleteTradingPoint() {
    string name;
    cout << "Введите название торговой точки для удаления: ";
    cin >> name;
    for (int i = 0; i < tradingPointsCount; ++i) {
        if (tradingPoints[i].name == name) {
            for (int j = i; j < tradingPointsCount - 1; ++j) {
                tradingPoints[j] = tradingPoints[j + 1];
            }
            tradingPointsCount--;
            cout << "Торговая точка '" << name << "' удалена.\n";
            return;
        }
    }
    cout << "Торговая точка '" << name << "' не найдена.\n";
}

void editTradingPoint() {
    string name;
    cout << "Введите название торговой точки для изменения: ";
    cin >> name;
    for (int i = 0; i < tradingPointsCount; ++i) {
        if (tradingPoints[i].name == name) {
            cout << "Введите новое название: ";
            cin >> tradingPoints[i].name;
            cout << "Введите новое местоположение: ";
            cin >> tradingPoints[i].location;
            cout << "Введите новую площадь: ";
            cin >> tradingPoints[i].area;
            cout << "Торговая точка '" << name << "' изменена.\n";
            return;
        }
    }
    cout << "Торговая точка '" << name << "' не найдена.\n";
}

void deleteAllTradingPoints() {
    tradingPointsCount = 0;
    cout << "Все торговые точки удалены.\n";
}

void printTradingPoints() {
    for (int i = 0; i < tradingPointsCount; ++i) {
        cout << "Торговая точка '" << tradingPoints[i].name << "':\n";
        cout << "Местоположение: " << tradingPoints[i].location << "\n";
        cout << "Площадь: " << tradingPoints[i].area << "\n";
        cout << "\n";
    }
}

void printMenu() {
    cout << "===== Управление Торговым Центром =====\n";
    cout << "1. Показать доступные торговые точки\n";
    cout << "2. Добавить новую торговую точку\n";
    cout << "3. Удалить торговую точку\n";
    cout << "4. Редактировать торговую точку\n";
    cout << "5. Удалить все торговые точки\n";
    cout << "6. Выйти\n";
    cout << "Введите номер действия: ";
}

int main() {
    setlocale(LC_ALL, "ru");
    int choice;
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            printTradingPoints();
            break;
        case 2:
            addTradingPoint();
            break;
        case 3:
            deleteTradingPoint();
            break;
        case 4:
            editTradingPoint();
            break;
        case 5:
            deleteAllTradingPoints();
            break;
        case 6:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 6);

    return 0;
}
