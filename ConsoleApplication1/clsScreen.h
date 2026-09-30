#pragma once
#include <iostream>
#include<string>
#include<iomanip>
#include"clsBankCleint.h"
#include"clsDeveloper.h"
#include "clsString.h"
#include"clsDate.h"
#include"clsPeriod.h"
#include"clsUtil.h"
#include"clsInputValidate.h"
#include"Globelheader.h"
using namespace std;
class clsScreen
{
private:
protected:
	
static void _DrawHederScrenns(string Title,string subtitle="") {
	cout << "\n\t\t\t\t\t -----------------------------------------\n";
	cout << "\n\t\t\t\t\t\t\t " << Title << endl;
	if (subtitle!="")
		cout << "\n\t\t\t\t\t\t\t " << subtitle << endl;
	cout << "\n\t\t\t\t\t -----------------------------------------\n";
	cout <<"\t\t\t\t\tUser : " << CurrentUser.getUserName() << endl;
	cout << "\t\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << endl;
	cout << endl;
}

};

