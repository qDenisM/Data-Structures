#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Структура для хранения информации о клиенте
struct Client
{
    string firstName;
    string lastName;
    string patronymic;
    string passportData;
    double loanAmount;
    double commission;
    int returnDays;
    bool returned;
};

// Вектор для хранения информации о клиентах
vector<Client> clients;

// Индекс для поиска клиентов по паспортным данным
vector<string> passportIndex;

// Функция для добавления нового клиента
void AddClient()
{
    Client client;

    cout << "Введите фамилию: ";
    cin >> client.lastName;

    cout << "Введите имя: ";
    cin >> client.firstName;

    cout << "Введите отчество: ";
    cin >> client.patronymic;

    cout << "Введите паспортные данные: ";
    cin >> client.passportData;

    cout << "Введите сумму, которую готовы выдать на руки: ";
    cin >> client.loanAmount;

    cout << "Введите комиссионные: ";
    cin >> client.commission;

    cout << "Введите срок возврата (в днях): ";
    cin >> client.returnDays;

    client.returned = false;

    clients.push_back(client);
    passportIndex.push_back(client.passportData); // Добавляем паспортные данные в индекс

    cout << "Клиент успешно добавлен.\n";
}

// Функция для отображения информации о клиентах
void DisplayClients()
{
    if (clients.empty())
    {
        cout << "Нет данных о клиентах.\n";
        return;
    }

    cout << "Информация о клиентах:\n";
    for (const auto& client : clients)
    {
        cout << "Фамилия: " << client.lastName << "\n";
        cout << "Имя: " << client.firstName << "\n";
        cout << "Отчество: " << client.patronymic << "\n";
        cout << "Паспортные данные: " << client.passportData << "\n";
        cout << "Сумма на руки: " << client.loanAmount << "\n";
        cout << "Комиссионные: " << client.commission << "\n";
        cout << "Срок возврата (в днях): " << client.returnDays << "\n";
        cout << "Возвращено: " << (client.returned ? "Да" : "Нет") << "\n";
        cout << "--------------------------\n";
    }
}

// Функция для обновления информации о возврате денег
void UpdateReturnStatus()
{
    if (clients.empty())
    {
        cout << "Нет данных о клиентах.\n";
        return;
    }

    string passportData;
    cout << "Введите паспортные данные клиента: ";
    cin >> passportData;

    bool found = false;
    for (auto& client : clients)
    {
        if (client.passportData == passportData)
        {
            client.returned = true;
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "Информация о возврате успешно обновлена.\n";
    }
    else
    {
        cout << "Клиент с указанными паспортными данными не найден.\n";
    }
}

// Функция для выполнения линейного поиска по индексу и вывода структуры клиента
void FindClientByPassport()
{
    if (passportIndex.empty())
    {
        cout << "Нет данных о клиентах.\n";
        return;
    }

    string passportData;
    cout << "Введите паспортные данные клиента: ";
    cin >> passportData;

    // Линейный поиск по индексу
    for (size_t i = 0; i < passportIndex.size(); ++i)
    {
        if (passportIndex[i] == passportData)
        {
            const Client& client = clients[i];
            cout << "Фамилия: " << client.lastName << "\n";
            cout << "Имя: " << client.firstName << "\n";
            cout << "Отчество: " << client.patronymic << "\n";
            cout << "Паспортные данные: " << client.passportData << "\n";
            cout << "Сумма на руки: " << client.loanAmount << "\n";
            cout << "Комиссионные: " << client.commission << "\n";
            cout << "Срок возврата (в днях): " << client.returnDays << "\n";
            cout << "Возвращено: " << (client.returned ? "Да" : "Нет") << "\n";
            return;
        }
    }

    cout << "Клиент с указанными паспортными данными не найден.\n";
}

int main()
{
    setlocale(LC_ALL, "ru");
    int choice;

    while (true)
    {
        cout << "Ломбардное меню:\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Отобразить информацию о клиентах\n";
        cout << "3. Обновить информацию о возврате денег\n";
        cout << "4. Поиск клиента по паспортным данным\n";
        cout << "5. Выход\n";

        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            AddClient();
            break;
        case 2:
            DisplayClients();
            break;
        case 3:
            UpdateReturnStatus();
            break;
        case 4:
            FindClientByPassport();
            break;
        case 5:
            cout << "Программа завершена.\n";
            return 0;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
            break;
        }

        cout << "\n";
    }
}