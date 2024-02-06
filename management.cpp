#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class BankAccount {
private:
    int accNo;
    string name;
    string Fname;
    string cnic;
    string P_no;
    string email;
    float amount;

public:
    int search;
    void createAccount();
    void depositAmount();
    void withdrawAmount();
    void checkInfo();
};

void BankAccount::createAccount() {
    srand(time(0));
    accNo = rand() * rand() + rand() * rand();

    cout << "Enter Your name :: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Your Father name :: ";
    getline(cin, Fname);

    cout << "Enter Your cnic :: ";
    getline(cin, cnic);

    cout << "Enter Your phone no. :: ";
    getline(cin, P_no);

    cout << "Enter Your email :: ";
    getline(cin, email);

    cout << "Enter Your amount :: ";
    cin >> amount;

    cout << endl
         << accNo << " This is your account number... \n";
    cout << "Please save it \n\n";

    ofstream file("data.txt", ios::out | ios::app);
    file << accNo << "\t" << name << "\t" << Fname << "\t" << cnic << "\t" << P_no << "\t" << email << "\t" << amount << endl;
    file.close();
}

void BankAccount::depositAmount() {
    cout << "Enter amount to deposit :: ";
    float newAmount;
    cin >> newAmount;

    ifstream file("data.txt", ios::in);
    ofstream file1("data1.txt", ios::out | ios::app);

    while (file >> accNo >> name >> Fname >> cnic >> P_no >> email >> amount) {
        if (accNo == search) {
            cout << "\ncurrent amount :: " << amount;
            amount += newAmount;
            cout << "\nupdated amount :: " << amount << endl;
        }
        file1 << accNo << "\t" << name << "\t" << Fname << "\t" << cnic << "\t" << P_no << "\t" << email << "\t" << amount << endl;
    }

    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt", "data.txt");
}

void BankAccount::withdrawAmount() {
    cout << "Enter amount to withdraw :: ";
    float newAmount;
    cin >> newAmount;

    ifstream file("data.txt", ios::in);
    ofstream file1("data1.txt", ios::out | ios::app);

    while (file >> accNo >> name >> Fname >> cnic >> P_no >> email >> amount) {
        if (accNo == search) {
            cout << "\ncurrent amount :: " << amount;
            amount -= newAmount;
            cout << "\nupdated amount :: " << amount << endl;
        }
        file1 << accNo << "\t" << name << "\t" << Fname << "\t" << cnic << "\t" << P_no << "\t" << email << "\t" << amount << endl;
    }

    file.close();
    file1.close();
    remove("data.txt");
    rename("data1.txt", "data.txt");
}

void BankAccount::checkInfo() {
    ifstream file("data.txt", ios::in);
    if (!file) {
        cout << "File opening error !";
        return;
    }
    while (file >> accNo >> name >> Fname >> cnic >> P_no >> email >> amount) {
        if (accNo == search) {
            cout << "\n---------------------------\n";
            cout << endl
                 << "\t::: account Number ::: ";
            cout << "\t   " << accNo << endl;
            cout << "\t::: User Name      ::: ";
            cout << "\t   " << name << "\n";
            cout << "\t::: Father Name    ::: ";
            cout << "\t   " << Fname << "\n";
            cout << "\t::: CNIC number    ::: ";
            cout << "\t   " << cnic << "\n";
            cout << "\t::: Phone Number   ::: ";
            cout << "\t   " << P_no << "\n";
            cout << "\t::: Email          ::: ";
            cout << "\t   " << email << "\n";
            cout << "\t::: Current amount ::: ";
            cout << "\t   " << amount << endl;
            cout << "\n---------------------------\n\n";
            return; // Stop after finding the account info
        }
    }

    file.close();
    cout << "Account not found!" << endl;
}

int main() {
    BankAccount obj;
    char choice;

    cout << "\n\n\n\t\t......:::Bahram's Bank:::......";
    cout << "\n\t\t:: press 1 to Login  Account :: ";
    cout << "\n\t\t:: press 2 to Create Account ::";
    cout << "\n\t\t:: press 0 to Exit           ::";
    cout << "\n\t\t:: ......................... ::\n\t\t\t\t";
    cin >> choice;

    switch (choice) {
    case '1':
        cout << "Enter your account no :: ";
        cin >> obj.search;
        while (1) {
            cout << "\n\n\n\t\t.......:::Bahram's Bank:::.......";
            cout << "\n\t\t:: press 1 to Deposit  Amount  :: ";
            cout << "\n\t\t:: press 2 to Withdraw Amount  ::";
            cout << "\n\t\t:: press 3 to Check    Info    ::";
            cout << "\n\t\t:: press 0 to Exit     Menu    ::";
            cout << "\n\t\t:: ........................... ::\n\t\t\t\t";
            cin >> choice;

            switch (choice) {
            case '1':
                obj.depositAmount();
                break;
            case '2':
                obj.withdrawAmount();
                break;
            case '3':
                obj.checkInfo();
                break;
            case '0':
                return 0;
            default:
                cout << "Invalid Choice...!";
                break;
            }
        }
        break;
    case '2':
        obj.createAccount();
        break;
    case '0':
        return 0;
    default:
        cout << "Invalid Choice...!";
        break;
    }

    return 0;
}
