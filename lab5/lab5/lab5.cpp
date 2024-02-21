#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_TRADING_POINTS = 100;

struct TradingPoint {
    string name;
    string address;
};

TradingPoint tradingPoints[MAX_TRADING_POINTS];
int numTradingPoints = 0;

void readTradingPointsFromFile() {
    string filename;
    cout << "Введите название файла для загрузки торговой точки: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }

    numTradingPoints = 0;
    while (numTradingPoints < MAX_TRADING_POINTS && getline(file, tradingPoints[numTradingPoints].name) &&
        getline(file, tradingPoints[numTradingPoints].address)) {
        numTradingPoints++;
    }

    file.close();
}

void displayTradingPoints() {
    for (int i = 0; i < numTradingPoints; ++i) {
        cout << "Название: " << tradingPoints[i].name << ", Адрес: " << tradingPoints[i].address << endl;
    }
}

void addTradingPoint() {
    if (numTradingPoints < MAX_TRADING_POINTS) {
        TradingPoint tp;
        cout << "Введите название торговой точки: ";
        cin >> ws;
        getline(cin, tp.name);
        cout << "Введите адрес торговой точки: ";
        getline(cin, tp.address);

        tradingPoints[numTradingPoints++] = tp;
    }
    else {
        cout << "Достигнуто максимальное число торговых точек." << endl;
    }
}

void saveTradingPointsToFile() {
    string filename;
    cout << "Введите название файла для сохранения торговой точки: ";
    cin >> filename;

    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла " << filename << endl;
        return;
    }

    for (int i = 0; i < numTradingPoints; ++i) {
        file << tradingPoints[i].name << endl;
        file << tradingPoints[i].address << endl;
    }

    file.close();
}

void printMenu() {
    cout << "===== Управление Торговым Центром =====\n";
    cout << "1. Показать доступные торговые точки\n";
    cout << "2. Добавить новую торговую точку\n";
    cout << "3. Сохранить торговые точки в файл\n";
    cout << "4. Загрузить торговые точки из файла\n";
    cout << "5. Выйти\n";
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
            displayTradingPoints();
            break;
        case 2:
            addTradingPoint();
            break;
        case 3:
            saveTradingPointsToFile();
            break;
        case 4:
            readTradingPointsFromFile();
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
