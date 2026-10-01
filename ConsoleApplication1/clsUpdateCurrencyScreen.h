#pragma once
#include<iostream>
#include "clsScreen.h"
class clsUpdateCurrencyScreen:protected clsScreen
{
	static void _printCureencyCard(clsBankCurrency Cureency) {
		cout << "\n\nCureency Card \n";
		cout << "\n___________________________\n";
		cout << "Cureency Country : " << Cureency.getCountry() << endl;
		cout << "Cureency Code    : " << Cureency.getCode() << endl;
		cout << "Cureency Name    : " << Cureency.getName() << endl;
		cout << "Cureency Rate    : " << Cureency.getRate() << endl;
	}
	static void _UpdateRateCureency(clsBankCurrency& Cureency) {
		double NewRate;
		
		cout << "\nUpdate Cureency Rate \n";
		cout << "__________________________\n";
		NewRate = clsInputValidate::ReaddoubleNumber("Enter New Rate : ");
		Cureency.UpdateReta(NewRate);
		if (NewRate==Cureency.getRate())
		{
			cout << "Cureency Rate Upadte Sccufully :-) \n";
			_printCureencyCard(Cureency);
		}
		else
		{
			cout << "Cureen Rate Erro.......-:(\n";
		}
	}
public:
	static void ShowUpadteCurrencyScreen() {
		string CureencyCod;
		char answer;
		_DrawHederScrenns("Upadate Currency Exchang Screen");
		cout << "Pleas Enter Cureency Cod : ";
		CureencyCod = clsInputValidate::ReadString();
		while (!clsBankCurrency::IsExistObjectByCod(CureencyCod))
		{
			cout << "Validate Code , Enter Again : ";
			CureencyCod = clsInputValidate::ReadString();
		}
		clsBankCurrency Cureency = clsBankCurrency::FindByCodCureency(CureencyCod);
		_printCureencyCard(Cureency);
		cout << "Are You Sure Upadet Rate " << Cureency.getCountry() << "[y/n] : ";
		cin >> answer;
		if (toupper(answer) != 'Y')
		{
			return;
		}
		else
		{
			_UpdateRateCureency(Cureency);
		}
	
	}
};

