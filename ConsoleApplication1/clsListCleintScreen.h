#pragma once
#include<string>
#include"clsBankCleint.h"
#include "clsString.h"
#include"clsDate.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
using namespace std;
class clsListCleintScreen:protected clsScreen
{
private:
static	void _PrintCleintModel(clsBankCleint cleint) {

		cout << "|" << cleint.getAccountNumber()
			<< "\t\t|\t" << cleint.getPinCod()
			<< "\t|\t" << cleint.FullName()
			<< "\t|\t" << cleint.getPhone()
			<< "\t|\t" << cleint.getEmail()
			<< "\t|\t" << cleint.getAccountBalance() << "\n";
	}
public:
	static void ShowCleintsList() {
		vector<clsBankCleint>Cleints = clsBankCleint::GetCleintsList();
		string title = "Cleint List Screen ";
		string subtitle = "Cleint List(" +to_string( Cleints.size()) + " )";
		_DrawHederScrenns(title, subtitle);

		cout << "| Account Number | Pin Code\t|\tCleint Name\t|\tphone\t\t|\tEmail\t\t|\tBlance  \n";
		cout << "\n----------------------------------------------------------------------------------\n\n";
		if (Cleints.size() == 0)
			cout << "\n\n\t\t\t\t\t No Cleints Avalebil I Systeam \n\n\n";
		else
		{
			for (clsBankCleint& cleint : Cleints)
			{
				_PrintCleintModel(cleint);
			}
		}
		cout << "\n--------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------\n";



	}

};

