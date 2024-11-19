#pragma once
#include<iostream>
#include"clsMainScreen.h"
#include"General.h"
#include"clsScreen.h"
#include"clsUser.h"
class clsLoginScreen:protected clsScreen
{
private:

	static bool  _Login()
	{
		bool FaildLogin = false;
		string UserName, Password;
		short FailLoginCount = 0;
		
			do {
				if (FaildLogin)
				{
					FailLoginCount++;
					cout << "\nInvalid User Name, Password!\n";
					cout << "You have " << (3-FailLoginCount)<< " Trials to login.\n\n";
					
				}
				if (FailLoginCount == 3)
				{
					cout << "Your are locked after 3 faild trail.\n\n";
					return false;
				}
				cout << "\nEnter User Name? ";
				cin >> UserName;
				cout << "\nEnter Password? ";
				cin >> Password;
				CurrentUser = clsUser::Find(UserName,  Password);
				FaildLogin = CurrentUser.IsEmpty();
			} while (FaildLogin);
			CurrentUser.RegistorLogin();
			clsMainScreen::ShowMainMenue();
			return true;
		
	}
public:
	static bool  ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		 return _Login();
	}
};

