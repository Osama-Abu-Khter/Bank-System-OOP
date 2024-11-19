#pragma once
#include<iostream>
#include"clsBankClients.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;

class clsAddNewClientScreen:protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient &Client)
	{
		cout << "\nEnter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "Enter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "Enter Email: ";
		Client.Email = clsInputValidate::ReadString();
		cout << "Enter Phone: ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "Enter Pin Code: ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "Enter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadNumber<float>();


	}
	 static void _Print(clsBankClient Client)
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

public:
	static void ShowAddNewClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		_DrawScreenHeader("\t Add New Client Screen ");
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Used, Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();

		}
		clsBankClient Client = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(Client);
		clsBankClient::enSaveResults SaveResult;
		SaveResult = Client.Save();
		switch (SaveResult)
		{
		case clsBankClient::svFaildEmptyObject:
			cout << "\nError account was not saved because it's Empty";
			break;
		case clsBankClient::svSucceeded:
			cout << "\nAccount Addeded Successfully :-)\n";
			_Print(Client);
			break;
		case clsBankClient::svFaildAccountNumberExists:
			cout << "\nError account was not saved because account number is used!\n";
			break;
		
		}

	}
};

