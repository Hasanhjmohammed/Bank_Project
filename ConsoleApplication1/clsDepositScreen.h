#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsBankCleint.h"
class clsDepositScreen:protected clsScreen
{
private:
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
	static void DepositCleintScreen() {
		_DrawHederScrenns("Deposit Cleint Screen");
		cout << "Pleas Enter Account Number : ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankCleint::IsCleintExist(AccountNumber))
		{
			cout << "The Account Number is Not Found , Enter Anther agein :";
			AccountNumber = clsInputValidate::ReadString();

		}
		clsBankCleint Cleint = clsBankCleint::Find(AccountNumber);
		_PrintCleint(Cleint);
		double Amount = clsInputValidate::ReaddoubleNumber("Pleas Enter deposit  Amount : ");
		char answer = 'n';
		cout << "Do you want sure deposit this Amount [y/n] ";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			Cleint.Deposit(Amount);
			cout << "Deposit is Succfully :-)\n";
			cout << "You New Balance is " << Cleint.getAccountBalance();
		}
		else
		{
			cout << "\n Opration is Cancelled ,Thanks \n";
		}


	}

};

