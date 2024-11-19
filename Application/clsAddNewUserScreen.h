#pragma once
#include<iostream>
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;

class clsAddNewUserScreen:protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser &User)
	{
		cout << "\nEnter First Name: ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last Name: ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Premissions: ";
		User.Permission = _ReadPermissionsToSet();
	}
	static int _ReadPermissionsToSet()
	{
		int Premission = 0;
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
			Premission += clsUser::enPermissions::pListClient;
		}
		cout << "\nShow Add New Client ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premission += clsUser::enPermissions::pAddNewClient;

		}
		cout << "\nShow Delete Client ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premission += clsUser::enPermissions::pDleteClient;
		}
		cout << "\nShow Update Client ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premission += clsUser::enPermissions::pUpdateClient;
		}
		cout << "\nShow Find Client ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premission += clsUser::enPermissions::pFindClient;

		}
		cout << "\nShow Transaction ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premission += clsUser::enPermissions::pTransaction;
		}
		cout << "\nShow Manage User ? y/n ? " ;
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premission += clsUser::enPermissions::pManageUser;
		}
		cout << "\nShow Login Register Screen? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Premission += clsUser::enPermissions::pLogRegister;
		}
		
		return Premission;
	}
	static void _Print(clsUser User)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " <<User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermission  : " << User.Permission;
		cout << "\n___________________\n";

	}

public:
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t Add New User Screen ");
		string UserName = "";
		cout << "\nPlease Enter User Name: ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name Is Already Used, Choose another one: ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(User);

		clsUser::enSaveResults SaveResult;
		SaveResult = User.Save();
		switch (SaveResult)
		{
		case clsUser::svFaildEmptyOpject:
			cout << "\nError User was not saved because it's Empty";
			break;
		case clsUser::svSucceeded:
			cout << "\nUser Addeded Successfully :-)\n";
			_Print(User);
			break;
		case clsUser::svFaildUserNameExists:
			cout << "\nError User was not saved because User Name is used!\n";
			break;
		}
	}
};

