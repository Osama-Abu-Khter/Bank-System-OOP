#pragma once

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"clsString.h"

using namespace std;


class clsCurrency
{
private:

	enum enMode{ EmptyMode=0,UpdateMode=1};
	enMode _Mode;
	string _CurrencyCountry;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	static clsCurrency _ConvertLineToCurrencyObject(string line, string seperator = "#//#")
	{
		vector<string>vCurrency = clsString::Split(line, seperator);
		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2],stod( vCurrency[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string seperator = "#//#")
	{
		string line = "";
		line += Currency.CurrencyCountry() + seperator;
		line += Currency.CurrencyCode() + seperator;
		line += Currency.CurrencyName() + seperator;
		line += to_string(Currency.Rate());
		return line;
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static vector<clsCurrency>_LoadCurrencyDateFromFile()
	{
		vector<clsCurrency>vCurrency;
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open())
		{
			string DateLine = "";
			while (getline(myfile, DateLine))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(DateLine);
				vCurrency.push_back(Currency);
			}
			myfile.close();
		}
		return vCurrency;
	}
	static void _SaveCurrencyDateToFile(vector<clsCurrency> Currency)
	{
		string DateLine = "";
		fstream myfile;
		myfile.open("Currencies.txt", ios::out);
		if (myfile.is_open())
		{
			for (clsCurrency c : Currency)
			{
				DateLine = _ConvertCurrencyObjectToLine(c);
				myfile << DateLine << endl;
		     }
			myfile.close();
		}
	}

	void _Update()
	{
		vector<clsCurrency>vCurrency=_LoadCurrencyDateFromFile();
		for (clsCurrency &c : vCurrency)
		{
			if (c.CurrencyCode() == CurrencyCode())
			{
				c = *this;
				break;
			}
		}
		_SaveCurrencyDateToFile(vCurrency);
	}


public:
	clsCurrency(enMode Mode, string CurrencyCountry, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_CurrencyCountry = CurrencyCountry;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	string CurrencyCountry()
	{
		return _CurrencyCountry;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();
	}
	float Rate()
	{
		return _Rate;
	}
	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open())
		{
			string DateLine = "";
			while (getline(myfile, DateLine))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(DateLine);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					myfile.close();
					return Currency;
				}
			}
			myfile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string CurrencyCountry)
	{
		CurrencyCountry = clsString::UpperAllString(CurrencyCountry);
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open())
		{
			string DateLine = "";
			while (getline(myfile, DateLine))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(DateLine);
				if (clsString::UpperAllString(Currency.CurrencyCountry()) == CurrencyCountry)
				{
					myfile.close();
					return Currency;
				}
			}
			myfile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}
	static vector<clsCurrency>GetCurrencyList()
	{
		return _LoadCurrencyDateFromFile();
	}
	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}
	float ConvertToAnotherCurrecny(float Amount, clsCurrency Currecny2)
	{
		float AmountInUSD = ConvertToUSD(Amount);
		if (Currecny2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}
		return (float) (AmountInUSD * Currecny2.Rate());
	}
};

