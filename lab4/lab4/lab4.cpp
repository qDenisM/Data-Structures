#include <iostream>
#include <string>

using namespace std;


struct TradePoint {
    int id;
    string name;
    string location;
};

struct RentalContract {
    int id;
    int tradePointId;
    string terms;
};


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
    setlocale(LC_ALL, "ru");
    const int MAX_TRADE_POINTS = 100;
    const int MAX_CONTRACTS = 100; 

    TradePoint tradePoints[MAX_TRADE_POINTS]; 
    RentalContract contracts[MAX_CONTRACTS]; 

    int tradePointCount = 0; 
    int contractCount = 0; 

    int choice;
    do {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            
            for (int i = 0; i < tradePointCount; ++i) {
                cout << "Торговая точка #" << tradePoints[i].id << ": " << tradePoints[i].name << " (" << tradePoints[i].location << ")\n";
            }
            break;
        case 2:
            
            if (tradePointCount < MAX_TRADE_POINTS) {
                TradePoint newTradePoint;
                newTradePoint.id = tradePointCount + 1;
                cout << "Введите название торговой точки: ";
                cin >> newTradePoint.name;
                cout << "Введите местоположение торговой точки: ";
                cin >> newTradePoint.location;
                tradePoints[tradePointCount++] = newTradePoint;
            }
            else {
                cout << "Достигнуто максимальное количество торговых точек.\n";
            }
            break;
        case 3:
            
            if (contractCount < MAX_CONTRACTS) {
                RentalContract newContract;
                newContract.id = contractCount + 1;
                cout << "Введите ID торговой точки для договора аренды: ";
                cin >> newContract.tradePointId;
                cout << "Введите условия договора аренды: ";
                cin >> newContract.terms;
                contracts[contractCount++] = newContract;
            }
            else {
                cout << "Достигнуто максимальное количество договоров аренды.\n";
            }
            break;
        case 4:
            
            for (int i = 0; i < contractCount; ++i) {
                cout << "Договор аренды #" << contracts[i].id << " для торговой точки #" << contracts[i].tradePointId << ": " << contracts[i].terms << "\n";
            }
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
