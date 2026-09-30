#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankCleint.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
class clsWithDrwaScreen:protected clsScreen
{
private:
	enum AmountWithDraw
	{
		Twenty=1,
		Thirty=2,
		Fourty=3,
		Fivty=4,
		OneHunderd=5,
		TwoHundert=6,
		Ather=7

	};
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
	static double _SpialWithDarw() {
		double Amount = clsInputValidate::ReaddoubleNumber("Enter Amount Withdraw : ");
		return Amount;

	}
	static double _ValueWithDraw(AmountWithDraw Option) {

		switch (Option)
		{
		case clsWithDrwaScreen::Twenty:
			return 20;

			break;
		case clsWithDrwaScreen::Thirty:
			return 30;
			break;
		case clsWithDrwaScreen::Fourty:
			return 40;
			break;
		case clsWithDrwaScreen::Fivty:
			return 50;
			break;
		case clsWithDrwaScreen::OneHunderd:
			return 100;
			break;
		case clsWithDrwaScreen::TwoHundert:
			return 200;
			break;
		case clsWithDrwaScreen::Ather:
			return _SpialWithDarw();
			break;
		default:
			return 0;
			break;
		}
	}

	static double _DrawThemaWithDraw(clsBankCleint & Cleint) {
		cout << "[1]  with draw 20                 [2] With Draw 30  \n";
		cout << "[3]  with draw 40                 [4] Wiht Draw 50  \n";
		cout << "[5]  with draw 100                [6] Whith Draw 200 \n";
		cout << "[7] Other \n";
		int Number = clsInputValidate::ReadIntergetNumberBetween(1, 7, "Enter Number Between 1 and 7");
		double Amount = _ValueWithDraw((AmountWithDraw)Number);
		return Amount;
	}
public:
	static	void WithDrawCleintScreen() {
		_DrawHederScrenns("With Draw Cleint Screen");
		cout << "Pleas Enter Acount Number :";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankCleint::IsCleintExist(AccountNumber))
		{
			cout << "The Account Number is Not Found , Pleas Enter Again : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankCleint Cleint = clsBankCleint::Find(AccountNumber);
		_PrintCleint(Cleint);
		double Amount=_DrawThemaWithDraw(Cleint);
		cout << "Do you want sure withdraw [y/n] ";
		char answer;
		cin >> answer;
		if (toupper(answer) == 'Y') {

			if (Cleint.Withdraw(Amount))
			{
				cout << "With Draw Cleint is Succfully :-) \n";
				cout << "The New Your Blances is : " << Cleint.getAccountBalance() << endl;
			}
			else
			{
				cout << "\n the Amount is Bigger than Your Balnce \n";
				cout << "You Can not run transaction . \n";
				cout << "Amount With Darw is : " << Amount << endl;
				cout << "Your Balance is  : " << Cleint.getAccountBalance() << endl;
			}
		}
		else
		{
			cout << "\n Opration is Cancelled ,Thanks \n ";
		}
}

};

