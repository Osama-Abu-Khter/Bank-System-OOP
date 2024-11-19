#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
using namespace std;
class clsListCurrencyScreen:protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << left << setw(35) << Currency.CurrencyCountry();
		cout << "| " << left << setw(10) << Currency.CurrencyCode();
		cout << "| " << left << setw(30) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();
	}

public:
	static void ShowListCurrencyScreen()
	{
		vector<clsCurrency>vCurrency = clsCurrency::GetCurrencyList();
		string title = "\t Currencies List Screen";
		string subtitle = "\t (" +to_string( vCurrency.size() )+ ") Currency.";
		_DrawScreenHeader(title, subtitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Country";
		cout << "| " << left<<  setw(10) << "Code";
		cout << "| " << left << setw(30) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (vCurrency.size() == 0)
		{
			cout<<"\n\t\t\tCurrency not available in the system!";
		}
		else
		{
			for (clsCurrency c : vCurrency)
			{
				_PrintCurrency(c);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

	
};

