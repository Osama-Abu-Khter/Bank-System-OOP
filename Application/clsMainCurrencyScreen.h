#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsListCurrencyScreen.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrency.h"
#include"clsCurrecnyCalculator.h"
using namespace std;


class clsMainCurrencyScreen:protected clsScreen
{

private:
	enum enCurrencyOption{ListCurrencies=1,FindCrruency=2,UpdateRate=3,CurrencyCalculator=4,MainMenue=5};
	static short _ReadNumberCurrencyOption()
	{
		short number = 0;
		cout<<setw(37)<<left<<"" << "Choose what do you want to do? [1 to 5]?";
		number = clsInputValidate::ReadNumberBetween<short>(1, 5);
		return number;
	}
	static void _ShowListCurrencyScreen()
	{
	//	cout << "\nList Currency will be here...";
	
		clsListCurrencyScreen::ShowListCurrencyScreen();
 	}
	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency will be here...";
		clsFindCurrency::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nUpdate Rate will be here...";
		clsUpdateCurrency::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\n Currency Calculator will be here...";
		clsCurrecnyCalculator::ShowCurrencyCalculatorScreen();
	}
	static void _GetBachToCurrencyScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Menue...\n";
		system("pause>0");
		ShowCurencyExchangeScreen();
	}
	
	static void _PerformCurrencyOption(enCurrencyOption Option)
	{

		switch (Option)
		{

		case enCurrencyOption::ListCurrencies:
			system("cls");
			_ShowListCurrencyScreen();
			_GetBachToCurrencyScreen();
			break;
		case enCurrencyOption::FindCrruency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GetBachToCurrencyScreen();
			break;
		case enCurrencyOption::UpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GetBachToCurrencyScreen();
			break;
		case enCurrencyOption::CurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GetBachToCurrencyScreen();
			break;
		case enCurrencyOption::MainMenue:
		{

		}

		}
		
	}

public:
	static void ShowCurencyExchangeScreen()
	{
		
		system("cls");
		_DrawScreenHeader("\t Currency Exhange Main Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currency.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currecny.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformCurrencyOption((enCurrencyOption)_ReadNumberCurrencyOption());
	}


};

