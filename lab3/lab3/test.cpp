#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ��������� ��� �������� ���������� � �������
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

// ������ ��� �������� ���������� � ��������
vector<Client> clients;

// ������ ��� ������ �������� �� ���������� ������
vector<string> passportIndex;

// ������� ��� ���������� ������ �������
void AddClient()
{
    Client client;

    cout << "������� �������: ";
    cin >> client.lastName;

    cout << "������� ���: ";
    cin >> client.firstName;

    cout << "������� ��������: ";
    cin >> client.patronymic;

    cout << "������� ���������� ������: ";
    cin >> client.passportData;

    cout << "������� �����, ������� ������ ������ �� ����: ";
    cin >> client.loanAmount;

    cout << "������� ������������: ";
    cin >> client.commission;

    cout << "������� ���� �������� (� ����): ";
    cin >> client.returnDays;

    client.returned = false;

    clients.push_back(client);
    passportIndex.push_back(client.passportData); // ��������� ���������� ������ � ������

    cout << "������ ������� ��������.\n";
}

// ������� ��� ����������� ���������� � ��������
void DisplayClients()
{
    if (clients.empty())
    {
        cout << "��� ������ � ��������.\n";
        return;
    }

    cout << "���������� � ��������:\n";
    for (const auto& client : clients)
    {
        cout << "�������: " << client.lastName << "\n";
        cout << "���: " << client.firstName << "\n";
        cout << "��������: " << client.patronymic << "\n";
        cout << "���������� ������: " << client.passportData << "\n";
        cout << "����� �� ����: " << client.loanAmount << "\n";
        cout << "������������: " << client.commission << "\n";
        cout << "���� �������� (� ����): " << client.returnDays << "\n";
        cout << "����������: " << (client.returned ? "��" : "���") << "\n";
        cout << "--------------------------\n";
    }
}

// ������� ��� ���������� ���������� � �������� �����
void UpdateReturnStatus()
{
    if (clients.empty())
    {
        cout << "��� ������ � ��������.\n";
        return;
    }

    string passportData;
    cout << "������� ���������� ������ �������: ";
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
        cout << "���������� � �������� ������� ���������.\n";
    }
    else
    {
        cout << "������ � ���������� ����������� ������� �� ������.\n";
    }
}

// ������� ��� ���������� ��������� ������ �� ������� � ������ ��������� �������
void FindClientByPassport()
{
    if (passportIndex.empty())
    {
        cout << "��� ������ � ��������.\n";
        return;
    }

    string passportData;
    cout << "������� ���������� ������ �������: ";
    cin >> passportData;

    // �������� ����� �� �������
    for (size_t i = 0; i < passportIndex.size(); ++i)
    {
        if (passportIndex[i] == passportData)
        {
            const Client& client = clients[i];
            cout << "�������: " << client.lastName << "\n";
            cout << "���: " << client.firstName << "\n";
            cout << "��������: " << client.patronymic << "\n";
            cout << "���������� ������: " << client.passportData << "\n";
            cout << "����� �� ����: " << client.loanAmount << "\n";
            cout << "������������: " << client.commission << "\n";
            cout << "���� �������� (� ����): " << client.returnDays << "\n";
            cout << "����������: " << (client.returned ? "��" : "���") << "\n";
            return;
        }
    }

    cout << "������ � ���������� ����������� ������� �� ������.\n";
}

int main()
{
    setlocale(LC_ALL, "ru");
    int choice;

    while (true)
    {
        cout << "���������� ����:\n";
        cout << "1. �������� �������\n";
        cout << "2. ���������� ���������� � ��������\n";
        cout << "3. �������� ���������� � �������� �����\n";
        cout << "4. ����� ������� �� ���������� ������\n";
        cout << "5. �����\n";

        cout << "�������� ��������: ";
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
            cout << "��������� ���������.\n";
            return 0;
        default:
            cout << "������������ �����. ���������� �����.\n";
            break;
        }

        cout << "\n";
    }
}