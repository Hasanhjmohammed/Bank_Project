#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankCleint.h"
#include"clsInputValidate.h"
class clsTotalBalanceScreen:protected clsScreen
{
private:
static	void _PrintCleintBalance(clsBankCleint cleint) {

	 cout << "|" << cleint.getAccountNumber()<<"\t"
	     << "\t|\t" << cleint.FullName()
	     << "\t|\t" << cleint.getAccountBalance() << "\n";
 }
protected:
public:

 static void ShowToatalBalanceScreen() {
	 vector<clsBankCleint>Cleints = clsBankCleint::GetCleintsList();
	 cout << "\n----------------------------------------------------------------------------------\n\n";
	 cout << "\t\t\t\t\t Cleint List (" << Cleints.size() << ")" << "\n";
	 cout << "\n----------------------------------------------------------------------------------\n\n";
	 cout << "| Account Number | \tCleint Name\t|\tBlance  \n";
	 cout << "\n----------------------------------------------------------------------------------\n\n";
	 if (Cleints.size() == 0)
	     cout << "\n\n\t\t\t\t\t No Cleints Avalebil I Systeam \n\n\n";
	 else
	 {
	     for (clsBankCleint& cleint : Cleints)
	     {
	   	  _PrintCleintBalance(cleint);
	     }
	 }
	 double totalbalance = clsBankCleint::GetTotalBalance();
	 cout << "\n--------------------------------------------------------------------\n";
	 cout << "-----------------------------------------------------------------------\n";
	 cout << "\n\t\t\t\t\t TotalBalnces is : " << totalbalance <<endl;
	 cout << "\n\t\t\t\t\t (" << clsUtil::NumberTotext(totalbalance) <<")" << endl;
 }
};

