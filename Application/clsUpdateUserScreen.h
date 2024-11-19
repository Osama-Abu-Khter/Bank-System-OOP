#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
using namespace std;
class clsUpdateUserScreen:protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name: ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name: ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permission: ";
		User.Permission = _ReadPermissionsToSet();
	}
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
	static int _ReadPermissionsToSet()
	{
		int permission = 0;
		char Answer = 'n';
		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}
		cout << "\nDo you want to give access to :\n ";
		cout << "\nShow Client List ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pListClient;
		}
		cout << "\nShow Add New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pAddNewClient;
		}
		cout << "\nShow Delete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pDleteClient;
		}
		cout << "\nShow Update Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pUpdateClient;
		}
		cout << "\nShow Find Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pFindClient;
		}
		cout << "\nShow Transaction? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pTransaction;

		}
		cout << "\nShow Manage User? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pManageUser;
		}
		cout << "\nShow Login Register Screen? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			permission += clsUser::enPermissions::pLogRegister;
		}
		
		return permission;

	}

public:
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\tUpdate User Screen");
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
		char Answer = 'n';
		cout << "\nAre you sure you want this client to update y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Info: ";
			cout << "\n_________________\n";
			_ReadUserInfo(User);
			clsUser::enSaveResults SaveResult;
			SaveResult = User.Save();
			switch (SaveResult)
			{
			case clsUser::enSaveResults::svFaildEmptyOpject:
			{
				cout << "\nError User was not saved because it's Empty";
				break;
			}
			case clsUser::enSaveResults::svSucceeded:
			{
				cout << "\nUser Updated Successfully :-)\n";
				_PrintUserCard(User);
				break;
			}
			}
		}
	}
};

