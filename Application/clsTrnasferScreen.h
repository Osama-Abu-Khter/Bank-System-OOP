#pragma once
#include<iostream>
#include<string>
#include"clsDate.h"
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClients.h"
#include"General.h"
using namespace std;

class clsTrnasferScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\nClient Card:";
		cout << "\n_______________________________";
		cout << "\n\nFull Name   : " << Client.FullName();
		cout << "\nAcc.Number  : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance; 
		cout << "\n_______________________________";
	}

	
	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}
	static string _ReadAccountNumberTo(clsBankClient Client)
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)||Client.AccountNumber()==AccountNumber)
		{
			if (Client.AccountNumber() == AccountNumber)
			{
				cout << "\nAccount Number used now, choose another one: ";

			}
			else
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}
	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadNumber<float>();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadNumber<double>();
		}
		return Amount;
	}
	

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen");

		

			clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

			_PrintClient(SourceClient);

			clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumberTo( SourceClient));

			_PrintClient(DestinationClient);

			float Amount = ReadAmount(SourceClient);


			cout << "\nAre you sure you want to perform this operation? y/n? ";
			char Answer = 'n';
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y')
			{
				if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
				{
					cout << "\nTransfer done successfully\n";
				}
				else
				{
					cout << "\nTransfer Faild \n";
				}
			}

			_PrintClient(SourceClient);
			_PrintClient(DestinationClient);
			


			
		



	}


};

