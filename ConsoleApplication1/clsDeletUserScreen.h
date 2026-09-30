#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsString.h"
#include"clsBankUser.h"
using namespace std;
class clsDeletUserScreen:protected clsScreen
{
private:
	static void _PrintUser(clsBankUser User) {
		cout << "\ User Card : \n";
		cout << "____________________________________\n";
		cout << "FirstName   : " << User.getFirstName() << endl;
		cout << "LastName    : " << User.getLastName() << endl;
		cout << "FullName    : " << User.FullName() << endl;
		cout << "Email       : " << User.getEmail() << endl;
		cout << "Phone       : " << User.getPhone() << endl;
		cout << "UserName    : " << User.getUserName() << endl;
		cout << "Password    : " << User.getPassword() << endl;
		cout << "Permission  : " << User.getPermission() << endl;
		cout << "____________________________________\n";
	}

protected:
public:

	static void ShowDeletUserScreen() {
		char answer;
		_DrawHederScrenns("Delet User Screen");
		cout << "Pleas Enter User Name To Deleted : ";
		string UserName = clsInputValidate::ReadString();
		while (!clsBankUser::IsUserExist(UserName))
		{
			cout << "The UserName is Not Found , Enter agin : ";
			UserName = clsInputValidate::ReadString();
		}
		clsBankUser user = clsBankUser::Find(UserName);
	
		_PrintUser(user);
		if (user.getUserName() == "Admin")
		{
			cout << "Sorry , you can not this user \n";
		}
		else
		{
			cout << "Do You Want Sure Delet this User [y/n] : ";
			cin >> answer;
			
			if (answer == 'Y' || answer == 'y')
			{
				user = clsBankUser::getDeletObject(UserName);
				clsBankUser::enSaveResault SaveResault;
				SaveResault = user.Save();
				switch (SaveResault)
				{
				case clsBankCleint::SaveResault:
					cout << "the User is Delet Succsessfully :-) \n";
					_PrintUser(user);
					break;
				case clsBankCleint::NoSaveResault:
					cout << "the User is Not Delted :-( \n";
					break;
				case clsBankCleint::ObjectExist:
					cout << "the User is Found Already  :-( \n";
					break;
				default:
					break;
				}
			}
		}
	}
};

