#pragma once
#include<iostream>
#include"clsPerson.h"
#include"clsString.h"
#include<vector>
#include<fstream>
#include"clsDate.h"
#include"clsBankClients.h"
#include"clsUtil.h"
using namespace std;
class clsUser:public clsPerson
{

private:
	enum enMode {EmptyMode=0,UpdateMode=1,AddNew=2};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	string _DateTime;
	bool _MarkedForDeletes = false;

	string _PerPareLogInRecord(string seperator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + seperator;
		LoginRecord += UserName + seperator;
		LoginRecord += clsUtil::EncryptText(Password) + seperator;
		LoginRecord += to_string(Permission);
		return LoginRecord;
	}

	

	static clsUser _ConvertLineToRecordObject(string line,string separetor="#//#")
	{
		vector<string>vUser = clsString::Split(line,separetor);
		return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4]
			, clsUtil::DecryptionText(vUser[5]), stoi(vUser[6]));
	}
	static clsUser _GetEmptyUserObject() {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static string _ConvertUserObjectToLine(clsUser User, string separetor = "#//#")
	{
		string UserRecord ="";
		UserRecord += User.FirstName + separetor;
		UserRecord += User.LastName + separetor;
		UserRecord += User.Email + separetor;
		UserRecord += User.Phone + separetor;
		UserRecord += User.UserName + separetor;
		UserRecord += clsUtil::EncryptText(User.Password) + separetor;
		UserRecord += to_string(User.Permission);
		return UserRecord;


	}
	static vector<clsUser>_LoadUserDateFromFile()
	{
		vector<clsUser>vUser;
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser User = clsUser::_ConvertLineToRecordObject(line);
				vUser.push_back(User);
			}
			myfile.close();
		}
		return vUser;
	}
	static void _SaveUserDateToFile(vector<clsUser>vUser)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::out);
		string DateLine;
		if (myfile.is_open())
		{
			for (clsUser& c : vUser)
			{
				if (c._MarkedForDeletes == false)
				{
					DateLine = _ConvertUserObjectToLine(c);
					myfile << DateLine << endl;
				}
			}
			myfile.close();
		}
	}

	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;


		vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password =clsUtil::DecryptionText(LoginRegisterDataLine[2]);
		LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

		return LoginRegisterRecord;

	}
	
	void _Update() {
		vector<clsUser>vUser = _LoadUserDateFromFile();
		for (clsUser& c : vUser)
		{
			if (c.UserName == UserName)
			{
				c = *this;
				break;
			}
		}
		_SaveUserDateToFile(vUser);
	}
	void _AddDateLineToFile(string DateLine)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << DateLine << endl;
			myfile.close();
		}


	}
	void _AddNew()
	{
		_AddDateLineToFile(_ConvertUserObjectToLine(*this));
	}



public:

	enum enPermissions {
		eAll=-1, pListClient=1,pAddNewClient=2,pDleteClient=4,pUpdateClient=8,
		pFindClient=16,pTransaction=32,pManageUser=64,pLogRegister=128
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permission) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permission;
	}
	
	
	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;

	};
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	bool MarkedForDelete()
	{
		return _MarkedForDeletes;
	}
	void SetUserName(string Name)
	{
		_UserName = Name;
	}
	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put =SetUserName)) string UserName;
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	void SetPermissions(int Permission)
	{
		_Permissions = Permission;
	}
	int GetPermissons()
	{
		return _Permissions;
	}
	__declspec(property(get =GetPermissons, put = SetPermissions)) int Permission;
	static clsUser Find(string UserName)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser User = clsUser::_ConvertLineToRecordObject(line);
				if (User.UserName == UserName)
				{
					myfile.close();
					return User;
				}
			}
			myfile.close();
		}
		return _GetEmptyUserObject();
    }
	static clsUser Find(string UserName, string Password)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				clsUser User = clsUser::_ConvertLineToRecordObject(line);
				if (User.UserName == UserName && User.Password == Password)
				{
					myfile.close();
					return User;
				}

			}
			myfile.close();
		}
		return _GetEmptyUserObject();
	}
	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}
	enum enSaveResults { svFaildEmptyOpject = 0, svSucceeded = 1, svFaildUserNameExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
       {
		case enMode::EmptyMode:
		{
			if (IsEmpty())
				return  enSaveResults:: svFaildEmptyOpject();
			break;
		}

		case enMode::UpdateMode:
		{
			_Update();
			return  enSaveResults:: svSucceeded;
			break;

		}
		case enMode::AddNew:
		{
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResults::svFaildUserNameExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;

		}
	
		}
	}
	bool Delete()
	{
		vector<clsUser>vUser = _LoadUserDateFromFile();
		for (clsUser& u : vUser)
		{
			if (u.UserName == _UserName)
			{
				u._MarkedForDeletes = true;
				break;
			}
		}
		_SaveUserDateToFile(vUser);
		*this = _GetEmptyUserObject();
		return true;
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNew, "", "", "", "", UserName, "", 0);
	}
	static vector< clsUser> GetUsersList()
	{
		return _LoadUserDateFromFile();
	}
	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permission == enPermissions::eAll)
			return true;
		
		if ((Permission & this->Permission) == Permission)
			return true;
		else
			return false;
		
	}
	void RegistorLogin()
	{
		string DateLine = _PerPareLogInRecord();
		fstream myfile;
		myfile.open("LoginRegister.txt", ios::out | ios::app);
		if (myfile.is_open())
		{
			myfile << DateLine << endl;
			myfile.close();
		}
	}

	static  vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLoginRegisterRecord;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stLoginRegisterRecord LoginRegisterRecord;

			while (getline(MyFile, Line))
			{

				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

				vLoginRegisterRecord.push_back(LoginRegisterRecord);

			}

			MyFile.close();

		}

		return vLoginRegisterRecord;

	}
	
	
};

