#include <iostream>
#include <string>

using namespace std;

struct TradingPoint {
    string name;
    float area;
};

void printMenu() {
    cout << "===== Управление Торговым Центром =====\n";
    cout << "1. Показать доступные торговые точки\n";
    cout << "2. Добавить новую торговую точку\n";
    cout << "3. Сортировать пузырькой сортировкой торговые точки\n";
    cout << "4. Сортировать быстрой сортировкой торговые точки\n";
    cout << "5. Выйти\n";
    cout << "Введите номер действия: ";
}

void sortTradingPoints(TradingPoint* tradingPoints, int numPoints) {
    for (int i = 0; i < numPoints - 1; i++) {
        for (int j = 0; j < numPoints - i - 1; j++) {
            if (tradingPoints[j].name > tradingPoints[j + 1].name ||
                (tradingPoints[j].name == tradingPoints[j + 1].name && tradingPoints[j].area > tradingPoints[j + 1].area)) {
                TradingPoint temp = tradingPoints[j];
                tradingPoints[j] = tradingPoints[j + 1];
                tradingPoints[j + 1] = temp;
            }
        }
    }
}

int partition(TradingPoint* arr, int low, int high) {
    TradingPoint pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // Compare by area first, then by name if areas are equal
        if (arr[j].area < pivot.area || (arr[j].area == pivot.area && arr[j].name < pivot.name)) {
            i++; // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(TradingPoint* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayTradingPoints(TradingPoint* tradingPoints, int numPoints) {
    cout << "===== Торговые точки =====\n";
    for (int i = 0; i < numPoints; i++) {
        cout << "Торговая точка " << i + 1 << ":\n";
        cout << "Название: " << tradingPoints[i].name << "\n";
        cout << "Площадь: " << tradingPoints[i].area << "\n\n";
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int choice;
    const int maxTradingPoints = 100;
    TradingPoint tradingPoints[maxTradingPoints];
    int numPoints = 0;

    do {
        printMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            displayTradingPoints(tradingPoints, numPoints);
            break;
        case 2:
            
            if (numPoints < maxTradingPoints) {
                cout << "Введите название торговой точки: ";
                cin >> tradingPoints[numPoints].name;
                cout << "Введите площадь торговой точки: ";
                cin >> tradingPoints[numPoints].area;
                numPoints++;
            }
            else {
                cout << "Достигнуто максимальное число торговых точек.\n";
            }
            break;
        case 3:
            
            sortTradingPoints(tradingPoints, numPoints);
            cout << "Торговые точки отсортированы.\n";
            break;
        case 4:
            quickSort(tradingPoints, 0, numPoints - 1);
            cout << "Торговые точки отсортированы.\n";
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
