#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankCurrency.h"
class clsFindCurrencyScreen:protected clsScreen
{
private:
	enum enFindCureency
	{
		enCode = 1,
		enCountry = 2
		
	};
	static short _ReadNumberOption() {
		short Number;
		Number = clsInputValidate::ReadIntergetNumberBetween(1, 2, "Find By :[1] Code or [2] Country ? :");
		return Number;
	}
	static void _FindByCode() {
		string CureencyCod;
		cout << "Pleas Enter Cureency Code :";
		CureencyCod = clsInputValidate::ReadString();
		while (!clsBankCurrency::IsExistObjectByCod(CureencyCod))
		{
			cout << "The Cureency Code is Not Found , Pleas Enter Again :";
			CureencyCod = clsInputValidate::ReadString();
		}
		clsBankCurrency Cureency = clsBankCurrency::FindByCodCureency(CureencyCod);
		_printCureencyCard(Cureency);
	}
	static void _FindByCountry() {
		string CureencyCountry;
		cout << "Pleas Enter Cureency Country :";
		CureencyCountry = clsInputValidate::ReadString();
		while (!clsBankCurrency::IsExistObjectByCountry(CureencyCountry))
		{
			cout << "The Cureency CureencyCountry is Not Found , Pleas Enter Again :";
			CureencyCountry = clsInputValidate::ReadString();
		}
		clsBankCurrency Cureency = clsBankCurrency::FindByCountryCureency(CureencyCountry);
		_printCureencyCard(Cureency);
	}
	static void _printCureencyCard(clsBankCurrency Cureency) {
		cout << "\n\nCureency Card \n";
		cout << "\n___________________________\n";
		cout << "Cureency Country : " << Cureency.getCountry()<<endl;
		cout << "Cureency Code    : " << Cureency.getCode() << endl;
		cout << "Cureency Name    : " << Cureency.getName() << endl;
		cout << "Cureency Rate    : " << Cureency.getRate() << endl;
		cout << "\n___________________________\n";
	}
	static void _PerformansCurrencyScreen(enFindCureency Option) {
		switch (Option)
		{
		case clsFindCurrencyScreen::enCode:
			_FindByCode();
			break;
		case clsFindCurrencyScreen::enCountry:
			_FindByCountry();
			break;
		default:
			break;
		}
	}
public:
	static void ShowFindCurrencyScreen() {
		_DrawHederScrenns("Find Currency Exchang Screen");

		_PerformansCurrencyScreen((enFindCureency)_ReadNumberOption());

	}
};

