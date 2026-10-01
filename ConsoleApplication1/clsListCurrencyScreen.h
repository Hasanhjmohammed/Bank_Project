#pragma once
#include"clsScreen.h"
#include"clsBankCurrency.h"
class clsListCurrencyScreen:protected clsScreen
{
private:
	static void _PrintCurrency(clsBankCurrency Currency) {
		cout << "|" << setw(30) << left << Currency.getCountry();
		cout << "|" << setw(8) << left << Currency.getCode();
		cout << "|" << setw(45) << left << Currency.getName();
		cout << "|" << setw(10) << left << Currency.getRate();
			cout << "\n";

	}
public:
	static void ShowListCurrenncyScreen() {
		vector<clsBankCurrency>Cureencies = clsBankCurrency::GetListCureency();
		string title = "List Currency Exchange Screen";
		string subtitle = "Currency Exchange (" +to_string(Cureencies.size()) + ")s";
		_DrawHederScrenns(title,subtitle);
		cout << "\n_______________________________________________________________________________________________________\n";
		cout << "| Country \t\t\t|  Code  | Name\t\t\t\t\t    | Rate(s) 1$ ";
		cout << "\n_______________________________________________________________________________________________________\n\n";

		if (Cureencies.size() == 0)
			cout << "\n\n\t\t\t\t\t No Cleints Avalebil I Systeam \n\n\n";
		else
		{
			for (clsBankCurrency& Cur : Cureencies)
			{
				_PrintCurrency(Cur);
			}
		}
		cout << "\n--------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------\n";

	
	}
};

