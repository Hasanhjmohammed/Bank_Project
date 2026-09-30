#pragma once
#include<iostream>
#include<vector>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsString.h"
#include"clsBankUser.h"
class clsListUserScreen:protected clsScreen
{
private:
	static void _PrintUserModel(clsBankUser User)
	{

		cout << "|" << User.getFirstName()
			<< "\t\t|\t" << User.getLastName()
			<< "\t\t|\t" << User.getUserName()
			<< "\t\t|\t" << User.getEmail()
			<< "\t|\t" << User.getPhone()
			<< "\t|\t" << User.getPassword()
			<< "\t|\t" << User.getPermission() << "\n";
	}
protected:
public:
	static	void ShowListUserScreen() {
		vector<clsBankUser>Users = clsBankUser::GetUsersList();
		string title = "List User Screen";
		string subtitle = "Users List(" + to_string(Users.size()) + ")";
		_DrawHederScrenns(title, subtitle);
		cout << "| First Name\t|\t Last Name\t|\tUser Name\t|\tEmail\t\t|\tphone\t\t|\tpassword\t|Permeission \n";
		cout << "-------------------------------------------------------------------------------\n\n";
		if (Users.size() == 0)
		{
			cout << "\t\t\t\t\t No Avalabel Users \n";
		}
		
		
		for (clsBankUser & user : Users)
		{
			_PrintUserModel(user);

		}
		cout << "------------------------------------------------------------------------------\n";

	}
};

