#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"clsUser.h"
#include"General.h"
#include"clsDate.h"
using namespace std;
class clsRegisterLogins
{

protected:

	static void AddToFile(string FileName= "LoginRegister.txt",string line)
	{
		fstream myfile;
		myfile.open(FileName, ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << line << endl;
			myfile.close();
		}
	}
	static string HourRightNow()
	{
		time_t t = time(0);
		
		tm* now = localtime(&t);
		short hour, min, sec;
		hour = now->tm_hour;
		min = now->tm_min;
		sec = now->tm_sec;
		
		return  to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);
		
	}
	static string LineOffFile()
	{
		string line = "";
		string seperator = "#//#";
	//	line +=  + seperator;
		line += CurrentDate.DateToString(clsDate()) + " - ";
		line += HourRightNow() + seperator;
		line += CurrentUser.UserName + seperator;
		line += CurrentUser.Password + seperator;
		line += to_string(CurrentUser.Permission )+ seperator;
	}
	static void AddTooFile()
	{
		AddToFile(LineOffFile());
	}

};

