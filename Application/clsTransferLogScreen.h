#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClients.h"
#include"clsScreen.h"
#include"General.h"
using namespace std;
class clsTransferLogScreen:protected clsScreen
{
private:
	static void _PrintTransferRegister(clsBankClient::stTransferLog Client)
	{
		cout << setw(8) << left << "" << "| " << left << setw(23) << Client.DateTime;
		cout << "| " << left << setw(10) << Client.Accountnumber;
		cout << "| " << left << setw(12) << Client.AccountNumber2;
		cout << "| " << left << setw(10) << Client.Amount;
		cout << "| " << left << setw(10) <<Client.Balance1;
		cout << "| " << left << setw(12) << Client.Balance2;
		cout << "| " << left << setw(10) <<Client.User;
	}

public:
	static void ShowTransferLogScreen()
	{
		vector<clsBankClient::stTransferLog>vTransfer = clsBankClient::GetTransferRgisterLog();
		string title = "\t Transfer Register List Screen";
		string SubTitle = "\t    (" + to_string(vTransfer.size()) + ") Register(s).";
		_DrawScreenHeader(title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(10) << "s.Acct";
		cout << "| " << left << setw(12) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(10) << "User";

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vTransfer.size() == 0)
		{
			cout << "\t\t\t\tNo Transfer Available In the System!";

		}
		else
		{
			for (clsBankClient::stTransferLog t : vTransfer)
			{
				_PrintTransferRegister(t);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

};

