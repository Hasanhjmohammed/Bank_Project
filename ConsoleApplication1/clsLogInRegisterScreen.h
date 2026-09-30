#pragma once
#include<iostream>
#include"clsScreen.h"
class clsLogInRegisterScreen:protected clsScreen
{
private:

	static	void _PrintLogInUser(clsBankUser::stLogInRegisterUser user) {

		cout << "|" << user.DateTime
			<< "\t\t|\t" << user.UserName
			<< "\t|\t" <<user.Password
			<< "\t|\t" << user.Permission<<"\n";
	}
public:
	static void ShowLogInRegisterScreen() {
		vector<clsBankUser::stLogInRegisterUser>LogInRegisterList = clsBankUser::GetLogInRegisterList();
		string title = "LogIn Register Screen";
		string subtitle = "User LogIn (" +to_string(LogInRegisterList.size()) + ")";
		_DrawHederScrenns(title,subtitle);
		cout << "| Date/Time\t\t|\tUserName\t|\tPassword|\tPermission\n";
		cout << "\n----------------------------------------------------------------------------------\n\n";
		if (LogInRegisterList.size() == 0)
			cout << "\n\n\t\t\t\t\t No User Avalebil I Systeam \n\n\n";
		else
		{
			for (clsBankUser::stLogInRegisterUser& user : LogInRegisterList)
			{
				_PrintLogInUser(user);
			}
		}
		cout << "\n--------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------\n";


	}
};

