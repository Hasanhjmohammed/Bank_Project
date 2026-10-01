#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsCalcolateCurrencyScreen:protected clsScreen
{
private:
	static void _printCureencyCard(clsBankCurrency Cureency) {
		cout << "\n\nCounvert From  \n";
		cout << "\n_____________________________________\n";
		cout << "Cureency Country      : " << Cureency.getCountry() << endl;
		cout << "Cureency Code         : " << Cureency.getCode() << endl;
		cout << "Cureency Name         : " << Cureency.getName() << endl;
		cout << "Cureency Rate(1$) =   : " << Cureency.getRate() << endl;
		cout << "\n______________________________________\n";
	}
	static clsBankCurrency _FindCurrency() {
		string CureencyCod = clsInputValidate::ReadString();
		while (!clsBankCurrency::IsExistObjectByCod(CureencyCod))
		{
			cout << "the Cureency Code is Not Found , Pleas Enter Another Code :";
				CureencyCod = clsInputValidate::ReadString();
		}
		clsBankCurrency Cureency = clsBankCurrency::FindByCodCureency(CureencyCod);
		return Cureency;
	}
public:
	static void ShowCalcolateCurrencyScreen() {
		double Amount,AmountByDoller;
		char answer = 'n';
		
		do {
			system("cls");
			_DrawHederScrenns("Calcolate Exchang Screen");
			cout << "Pleas Enter Cureency From Cod : ";
			clsBankCurrency CureencyFrom = _FindCurrency();
			cout << "Pleas Enter Cureency To Cod : ";
			clsBankCurrency CureencyTo = _FindCurrency();
			Amount = clsInputValidate::ReaddoubleNumber("Enter Amount Want You Exchang : ");

			_printCureencyCard(CureencyFrom);
			AmountByDoller = CureencyFrom.FromToDoller(Amount);
			cout << Amount << CureencyFrom.getCode() << " = " << AmountByDoller << " USD";

			if (CureencyTo.getCode() != "USD")
			{
				_printCureencyCard(CureencyTo);
				cout << Amount << CureencyFrom.getCode() << " = " << CureencyFrom.FromCureencyToCureency(Amount,CureencyTo) << " " << CureencyTo.getCode() << endl;
			}
			cout << "Do You Want Exchane Anter Time [y/n] :";;
			cin >> answer;
		} while (toupper(answer)=='Y');

	
	}
};

