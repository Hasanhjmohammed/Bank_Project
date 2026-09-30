#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankCleint.h"
#include"clsInputValidate.h"
class clsTransfetScreen:protected clsScreen
{
private:
	static void _PrintCleintCard(clsBankCleint cleint) {
		cout << "\nCleint Card\n";
		cout << "\n------------------------\n";
		cout <<"Full Name : " << cleint.FullName() << endl;
		cout <<"Acc.Nu : " << cleint.getAccountNumber() << endl;
		cout <<"Balance : " << cleint.getAccountBalance() << endl;
		cout << "------------------------\n\n";
	}
	static clsBankCleint _ReadInformationCleint() {
		string AccountNumberFrom = "";
		AccountNumberFrom = clsInputValidate::ReadString();
		while (!clsBankCleint::IsCleintExist(AccountNumberFrom))
		{
			cout << "Account Number is Not Found , Enter Another : ";
			AccountNumberFrom = clsInputValidate::ReadString();
		}
		clsBankCleint cleint1 = clsBankCleint::Find(AccountNumberFrom);
		return cleint1;
	}
	static double _ReadAmountTransfer(clsBankCleint cleintFrom) {
		double Amount=clsInputValidate::ReaddoubleNumber("Enter Amount Transfer :");
		while (Amount>cleintFrom.getAccountBalance())
		{
			cout << "Amount is Not sceed , Enter Another Amount :";
			Amount = clsInputValidate::ReaddoubleNumber("");
		}
		return Amount;

	}
public:
	static void ShowTransferScreen() {
		double Amount;
		char answer;
		bool tarnsfer=true;
		_DrawHederScrenns("Transfer Screen");
		cout << "Pleas Enter Account Number To transfer From : ";
		clsBankCleint cleint1 = _ReadInformationCleint();
		_PrintCleintCard(cleint1);
		cout << "Pleas Enter Account Number To Transfer To :";
		clsBankCleint cleint2 = _ReadInformationCleint();
		_PrintCleintCard(cleint2);
		Amount = _ReadAmountTransfer(cleint1);
		cout << "Do You Want Transfer [y/n] ";
		cin >> answer ;
			if (toupper(answer) != 'Y')
				return;
			else
			{
				if (clsBankCleint::Transfer(cleint1, cleint2, Amount))
				{
					cout << "Transfer is Sccussfully :-)\n";
					_PrintCleintCard(cleint1);
					_PrintCleintCard(cleint2);
					cleint1.WriteTransferInFile(cleint2, Amount);
				}
			}
	}
};

