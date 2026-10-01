#include <iostream>
#include<vector>
#include<math.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<bitset>
#include"clsBankCleint.h"
#include"clsDeveloper.h"
#include "clsString.h"
#include"clsDate.h"
#include"clsPeriod.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsBankUser.h"
#include"clsLoginScreen.h"
#include"clsBankCurrency.h"
#include"Globelheader.h"
enum enChoosUpdate
{
	All=1,
	eFirstName=2,
	eLastName=3,
	eEmail=4,
	ePhone=5,
	ePinCode=6,
	eBalance=7

};
using namespace std;


  //void PrintCleintBalance(clsBankCleint cleint) {

	 // cout << "|" << cleint.getAccountNumber()<<"\t"
		//  << "\t|\t" << cleint.FullName()
		//  << "\t|\t" << cleint.getAccountBalance() << "\n";
  //}
  //void ShowToatalBalance() {
	 // vector<clsBankCleint>Cleints = clsBankCleint::GetCleintsList();
	 // cout << "\n----------------------------------------------------------------------------------\n\n";
	 // cout << "\t\t\t\t\t Cleint List (" << Cleints.size() << ")" << "\n";
	 // cout << "\n----------------------------------------------------------------------------------\n\n";
	 // cout << "| Account Number | \tCleint Name\t|\tBlance  \n";
	 // cout << "\n----------------------------------------------------------------------------------\n\n";
	 // if (Cleints.size() == 0)
		//  cout << "\n\n\t\t\t\t\t No Cleints Avalebil I Systeam \n\n\n";
	 // else
	 // {
		//  for (clsBankCleint& cleint : Cleints)
		//  {
		//	  PrintCleintBalance(cleint);
		//  }
	 // }
	 // double totalbalance = clsBankCleint::GetTotalBalance();
	 // cout << "\n--------------------------------------------------------------------\n";
	 // cout << "-----------------------------------------------------------------------\n";
	 // cout << "\n\t\t\t\t\t TotalBalnces is : " << totalbalance <<endl;
	 // cout << "\n\t\t\t\t\t (" << clsUtil::NumberTotext(totalbalance) <<")" << endl;
     //}
template <typename T>T MySum(T n1,T n2) {
	return n1 + n2;
}
template<class T>
class clsCalcolater {
	int n1, n2;

};
int main()
{
	clsCalcolater mm;
	//clsBankUser User = clsBankUser::Find("hasan");
	//cout << clsBankUser::IsUserExist("User1");
	//clsMainScreen::ShowMainMenue();
	cout << MySum(0.2, 0.14)<<endl;
	cout << MySum(14, 10)<<endl;
	cout << MySum('c', 'd')<<endl;

	/*while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
			break;
	}*/



	//clsListCurrencyScreen::ShowListCurrenncyScreen();
	//clsBankCurrency cur = clsBankCurrency::FindByCodCureency("USA");
	////cout << cur.getRate();
	//if (clsBankCurrency::IsExistObject("US0D"))
	//	cout << "the Object is true ";
	//else
	//	cout << "the Object is false ";
	//system("pause>0");
}
