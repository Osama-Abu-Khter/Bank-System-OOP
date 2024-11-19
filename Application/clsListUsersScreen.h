#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;

class clsListUsersScreen:protected clsScreen
{
private:
	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left <<User.UserName;
		cout << "| " << setw(20) << left << User.FullName();
		cout << "| " << setw(12) << left <<User.GetPhone();
		cout << "| " << setw(20) << left << User.GetEmail();
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permission;

	}

public:
	static void ShowUserListScreen()
	{
		vector<clsUser> vUser = clsUser::GetUsersList();
		string title = "\t User List Screen";
		string SubTitle = "\t    (" + to_string(vUser.size()) + ") User(s).";
		_DrawScreenHeader(title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Premissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if(vUser.size()==0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else
		
			for (clsUser u : vUser)
			{
				_PrintUserRecordLine(u);
				cout << endl;
			}

		
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;



	}

};

