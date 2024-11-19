#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClients.h"
#include<iomanip>
#include"clsInputValidate.h"
using namespace std;

class clsWithdrawScreen:protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
    static string _ReadAccountNumber()
    {
        string massege = "";
        cout << "\nPlease Enter the Account Number? ";
        massege = clsInputValidate::ReadString();
        return massege;
    }
public:
    static void ShowWithdrawScreen()
    {
        _DrawScreenHeader("\t Withdraw Screen ");
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        double num;
        char Read = 'n';
        cout << "\n\nPlease enter withdraw amount: ";
        num = clsInputValidate::ReadNumber<double>();
        cout << "\nAre you sure you want perfrom this transaction ? y/n ? ";
        cin >> Read;
        if (Read == 'y' || Read == 'Y')
        {
            if (Client.Withdraw(num))
            {
                cout << "\nAmount Withdraw Successfully.\n";
                cout << "\nNew Balance is: " << Client.AccountBalance << endl;
            }
            else
            {
                cout << "\Cannot withdraw, Insuffecient Balance!\n ";
                cout << "\nAmount to withdraw is: " << num << endl;
                cout << "\nYour Balance is: " << Client.AccountBalance << endl;
            }
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }
};

