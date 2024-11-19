#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsString.h"
using namespace std;

class clsLoginRegisterScreen:protected clsScreen
{
private:

	static void _PrintLoginRegister(clsUser::stLoginRegisterRecord vUser)
	{
		cout << setw(8) << left << "" << "| " << left << setw(35) << vUser.DateTime;
		cout << "| " << left << setw(20) <<vUser.UserName;
		cout << "| " << left << setw(20) << vUser.Password;
		cout << "| " << left << setw(10) << vUser.Permissions;

	}
public:
	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLogRegister))
		{
			return;
		}
		vector<clsUser::stLoginRegisterRecord>vUser = clsUser::GetLoginRegisterList();
		string title = "\t Login Register List Screen";
		string SubTitle = "\t    (" + to_string(vUser.size()) + ") Register(s).";
		_DrawScreenHeader(title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permission";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vUser.size() == 0)
		{
			cout << "\t\t\t\tNo Users Available In the System!";

		}
		else
		{
			for (clsUser::stLoginRegisterRecord u : vUser)
			{
				_PrintLoginRegister(u);
				cout << endl;
			}
		
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}

};
