#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"clsPerson.h"
#include"clsString.h"
#include"clsDate.h"
using namespace std;
class clsBankUser:public clsPerson
{
private:
	enum enModUser {
	
		EmptyMod = 0,
		UpdateMod = 1,
		AddNewMod = 2,
		DeletMod = 3
	};
	enModUser _Mod;
	string _UserName;
	string _Password;
	int _permission;
	short _Key = 5;
	bool _IsMarkDelet = false;

	string _PreperLogInToRecord() {
		string dem = "#//#";
		string line = "";
		line += clsDate::GetSysteamDateTimeString() + dem;
		line += getUserName() + dem;
		line += clsUtil::Encryption(getPassword(),5) + dem;
		line += to_string(getPermission());
		return line;
	}
	struct stLogInRegisterUser ;
	static string _ConvertFromObjectToLine(clsBankUser User, string demo) {
		string line = "";
		line += User.getFirstName() + demo;
		line += User.getLastName() + demo;
		line += User.getEmail() + demo;
		line += User.getPhone() + demo;
		line += User.getUserName() + demo;
		line +=clsUtil::Encryption(User.getPassword(),5) + demo;
		line += to_string(User.getPermission());
		return line;
	}
	static	clsBankUser _CounverFromLineToObject(string Line, string demo) {
		vector <string>cleint = clsString::Split(Line, demo);
		return clsBankUser(enModUser::UpdateMod,
			cleint[0], cleint[1], cleint[2], cleint[3], cleint[4], clsUtil::Decryption(cleint[5],5), stoi(cleint[6])
		);
	}
	static	stLogInRegisterUser _CounverFromLineToStruct(string Line, string demo="#//#") {
		vector <string>user = clsString::Split(Line, demo);
		stLogInRegisterUser LogInRegisterUser;
		LogInRegisterUser.DateTime = user[0];
		LogInRegisterUser.UserName = user[1];
		LogInRegisterUser.Password = clsUtil::Decryption(user[2],5);
		LogInRegisterUser.Permission = stoi(user[3]);
		return LogInRegisterUser;
	}
	static	vector<clsBankUser>_LoadFromFileToObject() {
		fstream MyFile;
		string line;
		vector <clsBankUser>Users;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{

				clsBankUser user = _CounverFromLineToObject(line, "#//#");

				Users.push_back(user);
			}
			MyFile.close();
		}
		return Users;
	}

	static void _SaveUserDateToFile(vector<clsBankUser>Users) {
		fstream MyFile;
		string line;
		MyFile.open("Users.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsBankUser& c : Users)
			{
				if (!c._IsMarkDelet)
				{
					line = _ConvertFromObjectToLine(c, "#//#");
					MyFile << line << endl;
				}
			}
			MyFile.close();
		}
	}
	void _AddDatelineToFile(string line) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::app);
		if (MyFile.is_open())
		{
			MyFile << line << endl;
		}
		MyFile.close();
	}
	void _Update() {
		vector<clsBankUser>Users;
		Users = _LoadFromFileToObject();
		for (clsBankUser& u : Users)
		{
			if (u.getUserName() == this->getUserName())
			{
				u = *this;
				break;
			}
		}

		_SaveUserDateToFile(Users);
	}
	void _Adding() {

		_AddDatelineToFile(_ConvertFromObjectToLine(*this, "#//#"));
		/* vector<clsBankCleint>Cleints = _LoadFromFileToObject();
		 Cleints.push_back(*this);
		 _SaveCleintDateToFile(Cleints);*/
	}
	void _Deleted() {
		vector<clsBankUser>Users;
		Users = _LoadFromFileToObject();
		for (clsBankUser& c : Users)
		{
			if (c.getUserName() == this->_UserName)
			{
				c._IsMarkDelet = true;
				break;
			}
		}
		_SaveUserDateToFile(Users);
	}
	static clsBankUser _EmptyUser() {
		return clsBankUser(enModUser::EmptyMod,
			"", "", "", "", "", "", 0.0
		);
	}
protected:
public:
	struct stLogInRegisterUser
	{
		string DateTime;
		string UserName;
		string Password;
		int Permission;

	};
	clsBankUser(enModUser Mod, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int permission) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		this->_Mod = Mod;
		this->_UserName = UserName;
		this->_Password = Password;
		this->_permission = permission;
	}
	
	string getUserName() {
		return this->_UserName;
	}
	string getPassword() {
		return this->_Password;
	}
	bool IsEmpty() {
		return (this->_Mod == enModUser::EmptyMod);
	}
	int getPermission() {
		return this->_permission;
	}
	void setPermission(int permission) {
		 this->_permission=permission;
	}
	void setUserName(string UserName) {
		this->_UserName = UserName;
	}
	void setPassword(string Password) {
		this->_Password = Password;
	}
	static 	clsBankUser Find(string UserName) {
		fstream MyFile;
		string line;
		//vector <clsBankCleint>Cleints;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{
				clsBankUser user = _CounverFromLineToObject(line, "#//#");
				if (user.getUserName() == UserName)
				{
					MyFile.close();
					return user;
				}
				//Cleints.push_back(cleint);
			}
			MyFile.close();
		}
		return _EmptyUser();
	}
	static 	clsBankUser Find(string UserName, string Password) {
		fstream MyFile;
		string line;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{
				clsBankUser User = _CounverFromLineToObject(line, "#//#");
				if (User._UserName == UserName && User._Password == Password)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _EmptyUser();
	}

	static bool IsUserExist(string UserName) {
		clsBankUser User = clsBankUser::Find(UserName);
		return (!User.IsEmpty());


	}

	enum enSaveResault {
		SaveResault = 0,
		NoSaveResault = 1,
		ObjectExist = 2
	};

	enSaveResault Save() {

		switch (_Mod)
		{
		case clsBankUser::EmptyMod:
			if (IsEmpty())
				return enSaveResault::NoSaveResault;
			break;
		case clsBankUser::UpdateMod:
			_Update();
			return enSaveResault::SaveResault;
			break;
		case clsBankUser::AddNewMod:
		{
			if (clsBankUser::IsUserExist(_UserName))
			{
				return enSaveResault::ObjectExist;
			}
			else
			{
				_Adding();
				_Mod = enModUser::UpdateMod;
				return enSaveResault::SaveResault;
			}

		}
		break;
		case clsBankUser::DeletMod:
			_Deleted();
			return enSaveResault::SaveResault;
		default:
			break;
		}

	}

	static	clsBankUser getAddNewObject(string UserName) {
		return clsBankUser(enModUser::AddNewMod, "", "", "", "", UserName, "", 0);
	}
	static	clsBankUser getDeletObject(string UserName) {
		return clsBankUser(enModUser::DeletMod, "", "", "", "", UserName, "", 0.0);
	}

	static vector<clsBankUser>GetUsersList() {
		return _LoadFromFileToObject();
	}
	static vector<stLogInRegisterUser>GetLogInRegisterList() {
		fstream File;
		string line = "";
		vector<stLogInRegisterUser>LogInRegisterUsers;
		stLogInRegisterUser LogInRegister;
		File.open("LoginUser.txt", ios::in);
		if (File.is_open())
		{
			while (getline(File,line))
			{
				LogInRegister = _CounverFromLineToStruct(line);
				LogInRegisterUsers.push_back(LogInRegister);
			}	
		}
		File.close();
		return LogInRegisterUsers;
	}
	

	 bool _IsHavePermission(int per) {
		if (this->_permission == -1)
			return true;
		return ((this->_permission & per) == per);
	}

	 void RegisterLogIn() {
	
		 fstream File;
		 string line="";
		 File.open("LoginUser.txt", ios::app | ios::out);
		 if (File.is_open())
		 {
			 line = _PreperLogInToRecord();
			 File << line << endl;
		 }
		 File.close();
	 }

};

