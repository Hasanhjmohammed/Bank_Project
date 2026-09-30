#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankUser.h"
class clsFindUserScreen:protected clsScreen
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

public:
	static void ShowFindUserScreen() {
		_DrawHederScrenns("Find User Screen");
		cout << "ENter user Name To Find User : ";
		string UserName = clsInputValidate::ReadString();
		while (!clsBankUser::IsUserExist(UserName))
		{
			cout << "the User Is Not Found , Enter Another UserName : ";
			UserName = clsInputValidate::ReadString();
		}
		clsBankUser user = clsBankUser::Find(UserName);
		if (!user.IsEmpty())
		{
			cout << "\n Find User :-) \n";
		}
		else
		{
			cout << " \n Find is Not User :-( \n";
		}
		_PrintUser(user);

	}
};

