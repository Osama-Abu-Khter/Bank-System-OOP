#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
using namespace std;
class clsDeleteUserScreen:protected clsScreen
{
private:
	static void _PrintUserCard(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermission  : " << User.Permission;
		cout << "\n___________________\n";
	}

public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t Delete User Screen");
		string username = "";
		cout << "\nPlease Enter User Name: ";
		username = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(username))
		{
			cout << "\nUser Name is not found, Choose another one: ";
			username = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(username);
		_PrintUserCard(User);
		cout << "\nAre you sure you want to delete this user? y/n?";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer =='y')
		{
			if (User.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";
				_PrintUserCard(User);
			}
			else
			{
				cout << "\nError User Was not Deleted\n";
			}
		}
	}
};

