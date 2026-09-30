#pragma once

#include<iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
class clsFindCleintScreen: protected clsScreen
{
private:

protected:
	static void _PrintCleint(clsBankCleint Cleint) {
		cout << "\nCleint Card:\n";
		cout << "____________________________________\n";

		cout << "FirstName      : " << Cleint.getFirstName() << endl;
		cout << "LastName       : " << Cleint.getLastName() << endl;
		cout << "FullName       : " << Cleint.FullName() << endl;
		cout << "Email          : " << Cleint.getEmail() << endl;
		cout << "Phone          : " << Cleint.getPhone() << endl;
		cout << "AccountNumber  : " << Cleint.getAccountNumber() << endl;
		cout << "PinCod         : " << Cleint.getPinCod() << endl;
		cout << "AccountBalance : " << Cleint.getAccountBalance() << endl;
		cout << "____________________________________\n";
	}
public:
	static void FindCleintScreen() {
		_DrawHederScrenns("Find Cleint Screen");
		cout << "Pleas Enter Account Number :";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankCleint::IsCleintExist(AccountNumber))
		{
			cout << "the Account Number is Not Found ,Pleas Enter Anther ";
			AccountNumber = clsInputValidate::ReadString();

		}
		clsBankCleint cleint= clsBankCleint::Find(AccountNumber);

		if (!cleint.IsEmpty())
		{ 
			cout << "\n Find Cleint :-) \n";
		}
		else
		{
			cout << " \n Find is Not Cleint :-( \n";
		}

		_PrintCleint(cleint);
	}

};



