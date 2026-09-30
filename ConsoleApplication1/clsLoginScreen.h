#pragma once
#include<iostream>
#include<fstream>
#include"clsBankUser.h"
#include"clsScreen.h"
#include"Globelheader.h"
#include"clsMainScreen.h"
using namespace std;
class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login() {
		
		string UserName, Password;
		bool FailLogin = false;
		do {
			if (FailLogin)
			{
				CounterValidtion++;
				cout << "Invalid UserNmae /Password \n";
				cout << "You Have Only [" << 3-CounterValidtion << "] Trieing\n";
			
			}
			if (CounterValidtion == 3)
			{
				cout << "\n\nLock Systeam , Try After two houers \n\n";
				return false;
			}
				cout << "Enter User Name \n";
				UserName = clsInputValidate::ReadString();
				cout << "Enter Password \n";
				Password = clsInputValidate::ReadString();
				CurrentUser = clsBankUser::Find(UserName, Password);
				FailLogin = CurrentUser.IsEmpty();
		} while (FailLogin );
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		
		return true;
	}
public:
	static bool ShowLoginScreen() {
	
	_DrawHederScrenns("Login Screen");
	return _Login();
	 
	}

};

