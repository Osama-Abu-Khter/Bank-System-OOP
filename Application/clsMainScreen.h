#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientLiestScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUsersScreen.h"
#include"General.h"
#include"clsLoginRegisterScreen.h"
#include"clsMainCurrencyScreen.h"
using namespace std;

class clsMainScreen:protected clsScreen
{
private:
	enum enMainMenueOption
	{
		enClientList = 1,enAddClient=2, enDelete=3, enUpdate=4,enFind=5,enTransaction=6,
		enManageUsers=7,enLoginRegisterlist=8, enCurrencyExchange=9,enLogout=10
	};
	static void _GetBackToMainMeneue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowMainMenue();
	}
	static int _ReadMainMenueOption()
	{
		int number = 0;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
		number = clsInputValidate::ReadNumberBetween<int>(1, 10);
		return number;

	}
	static void _ShowClientLiest()
	{
		clsClientLiestScreen::ShowClientListScreen();

	}
	static void _ShowAddClient()
	{
	//	cout << "Add Client  will be here ...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	static void _ShowDeleteClient()
	{
		//cout << "Delete Client  will be here ...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowUpdateClient()
	{
		//cout << "Update Client  will be here ...\n";
		clsUpdateClientScreen::_ShowUpdateClientScreen();

	}
	static void _ShowFindClient()
	{
		//cout << "Find Client  will be here ...\n";
		clsFindClientScreen::ShowFindScreen();
	}
	static void _ShowTransaction()
	{
		//cout << "Transaction will be here ...\n";
		clsTransactionScreen::ShowTransactionScreen();
	}
	static void _ShowManageUsers()
	{
		//cout << "Manage Users will be here ...\n";
		clsManageUsersScreen::ShowManageUsersScreen();
	}
	static void _ShowLoginRegister()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}
	static void _ShowCurrencyExchange()
	{
		clsMainCurrencyScreen::ShowCurencyExchangeScreen();
	}
	static void _ShowLogout()
	{
		//cout << "Logout will be here ...\n";
		CurrentUser = clsUser::Find("", "");
	}

	static void _PerformMainMeneueOption(enMainMenueOption MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOption::enClientList:
			system("cls");
			_ShowClientLiest();
			_GetBackToMainMeneue();
			break;
		case enMainMenueOption::enAddClient:
			system("cls");
			_ShowAddClient();
			_GetBackToMainMeneue();
		case enMainMenueOption::enDelete:
			system("cls");
			_ShowDeleteClient();
			_GetBackToMainMeneue();
		case enMainMenueOption::enUpdate:
			system("cls");
			_ShowUpdateClient();
			_GetBackToMainMeneue();
		case enMainMenueOption::enFind:
			system("cls");
			_ShowFindClient();
			_GetBackToMainMeneue();
		case enMainMenueOption::enTransaction:
			system("cls");
			_ShowTransaction();
			_GetBackToMainMeneue();
		case enMainMenueOption::enManageUsers:
			system("cls");
			_ShowManageUsers();
			_GetBackToMainMeneue();
		case enMainMenueOption::enLoginRegisterlist:
			system("cls");
			_ShowLoginRegister();
			_GetBackToMainMeneue();
		case enMainMenueOption::enCurrencyExchange:
			system("cls");
			_ShowCurrencyExchange();
			_GetBackToMainMeneue();
			break;
		case enMainMenueOption::enLogout:
			system("cls");
			_ShowLogout();
			break;
		}
	}

	public:
		static void ShowMainMenue()
		{
			system("cls");
			_DrawScreenHeader("\t\tMain Screen");
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
			cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
			cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
			cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
			cout << setw(37) << left << "" << "\t[5] Find Client.\n";
			cout << setw(37) << left << "" << "\t[6] Transactions.\n";
			cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
			cout << setw(37) << left << "" << "\t[8] Login Register List.\n";
			cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
			cout << setw(37) << left << "" << "\t[10] Logout.\n";

			cout << setw(37) << left << "" << "===========================================\n";
			_PerformMainMeneueOption((enMainMenueOption)_ReadMainMenueOption());
		}
};

