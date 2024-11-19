#pragma once
#include<iostream>
#include"clsBankClients.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;

class clsUpdateClientScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
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
	static void _ReadClientInfo(clsBankClient& Client)
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

public:
	static void _ShowUpdateClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}
		_DrawScreenHeader("\t Update Client Screen ");
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number not found, Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		char Answer = 'n';
		cout << "\nAre you sure you want this client to update y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Client Info:";
			cout << "\n____________________\n";
			_ReadClientInfo(Client);
			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client.Save();
			switch (SaveResult)
			{
			case clsBankClient::enSaveResults ::svFaildEmptyObject:
				cout << "\nError account was not saved because it's Empty";
				break;
			case clsBankClient::enSaveResults::svSucceeded:
				cout << "\nAccount Updated Successfully :-)\n";
				_PrintClient(Client);
				break;

			}
		}
	}
};

