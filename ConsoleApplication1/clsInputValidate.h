#pragma once
#include<iostream>
#include <string>
#include"clsDate.h"

using namespace std;
class clsInputValidate
{
public:
	static bool IsNumberBetween(int Number, int From, int To) {
		if (Number >= From && Number <= To)
			return true;
		return false;
     } 

	static bool IsNumberBetween(double Number, double From, double To) {
		if (Number >= From && Number <= To)
			return true;
		return false;
	}

	static bool  IsDateBetween(clsDate Date,clsDate FromDate,clsDate ToDate) 
	{
		if (!clsDate::IsDate1LessDate2(FromDate, ToDate))
			clsDate::SwapDate(FromDate, ToDate);
		return ((clsDate::IsDate1LessDate2(FromDate, Date) ||clsDate::IsDate1LessDate2(FromDate, Date))
			&& (clsDate::IsDate1LessDate2(Date, ToDate)|| clsDate::IsDate1LessDate2(FromDate, ToDate)));
	}

	static int ReadInterNumber(string masseg) {
		cout << masseg << endl;
		int x;
		cin >> x;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Number , Pleas Enter agein\n";
			cin >> x;
		}

		return x;
	}

	static 	int ReadIntergetNumberBetween(int From, int To, string masseg) {
		int x= ReadInterNumber(masseg);

		while (!IsNumberBetween(x, From, To)) {
			
			x = ReadInterNumber("the Number is not true " + masseg);

		}
		return x;
}
	static double ReaddoubleNumber(string masseg) 
	{
		cout << masseg << endl;
		double x;
		cin >> x;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Number , Pleas Enter agein\n";
			cin >> x;
		}
		return x;
	}
	static 	double ReaddoubleNumberBetween(double From,double To,string masseg) {
		double d = ReaddoubleNumber(masseg);
		while (! IsNumberBetween(d,From,To) )
		{
			d = ReaddoubleNumber("the Number is not true, pleas Enter agein \n");
		}
		return d;

	}

	static bool IsValideDate(clsDate Date) 
	{
		if (Date.getMonth() >= 1 && Date.getMonth() <= 12)
		{
			if (Date.getDay() <= clsDate::CountDayInMonth(Date.getYear(), Date.getMonth()))
			{
				return true;
			}
	     }
		return false;
	}

	static bool IsValidEmail(string Email) {
		return clsString::IsFindWordInMasseg(Email, "@gmail.");
	}

	static string GetEmailwhienTrue(string masseg) {
		cout << masseg << endl;
		string email;
		cin >> email;
		while (!IsValidEmail(email))
		{
			cout << "Invalid Email , Enter Agein pleas ,:";
			cin >> email;
		}
		return email;
	}

	static	string ReadString() {
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
}
};

