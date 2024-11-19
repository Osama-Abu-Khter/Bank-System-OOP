#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
using namespace std;



class clsManageUsersScreen:protected clsScreen
{
private:
	enum enManageUser {
		ListUser=1,AddNewUser=2,DeleteUser=3,UpdateUser=4,FindUser=5,MainMenue=6
	};
	static short _RaedQuestionManageUser()
	{
		short line ;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		line = clsInputValidate::ReadNumberBetween<short>(1, 6);
		return line;
	}
	static void _ListUser()
	{
		//cout << "\nList User will be here...";
		clsListUsersScreen::ShowUserListScreen();
	}
	static void _AddNewUser()
	{
		//cout << "\nAdd New User will be here...";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _DeleteUser()
	{
		//cout << "\nDelete User will be here...";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _UpdateUser()
	{
	//	cout << "\nUpdate User will be here...";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	static void _FindUser()
	{
		//cout << "\nFind User will be here...";
		clsFindUserScreen::ShowFindUserScreen();
  	
	}
	static void _GetBackToManageUserScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage User Menue...\n";
		system("pause>0");
		ShowManageUsersScreen();
	}
	static void _PerformManageUserOption(enManageUser Option)
	{
		switch (Option)
		{
		case enManageUser::ListUser:
		{
			system("cls");
			_ListUser();
			_GetBackToManageUserScreen();
			break;
		}
		case enManageUser::AddNewUser:
		{
			system("cls");
			_AddNewUser();
			_GetBackToManageUserScreen();
			break;
		}
		case enManageUser::DeleteUser:
		{
			system("cls");
			_DeleteUser();
			_GetBackToManageUserScreen();
			break;

		}
		case enManageUser::UpdateUser:
		{
			system("cls");
			_UpdateUser();
			_GetBackToManageUserScreen();
			break;
		}
		case enManageUser::FindUser:
		{
			system("cls");
			_FindUser();
			_GetBackToManageUserScreen();
			break;
		}
		case enManageUser::MainMenue:
		{

		}
		}
	}

public:
	
	static void ShowManageUsersScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pManageUser))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen ");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Sceen \n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List User.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User .\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformManageUserOption((enManageUser)_RaedQuestionManageUser());
	}
	
};

