#pragma once
#include<iostream>
#include"clsBankCleint.h"
#include"clsScreen.h"
using namespace std;
class clsAddNewCleintScreen:protected clsScreen
{
protected:
	static void _PrintCleint(clsBankCleint Cleint) {
		cout << "\nCleint Card:\n";
		cout << "____________________________________\n";
		cout << "FirstName      : " << Cleint.getFirstName() << endl;
		cout << "LastName       : " << Cleint.getLastName() << endl;
		cout << "FullName       : " << Cleint.FullName() << endl;
		cout << "Email          : " << Cleint.getEmail() << endl;
		cout << "Phone          : " << Cleint.getPhone() << endl;
		cout << "AccountNumber  : " << Cleint.getAccountNumber() << endl;
		cout << "PinCod         : " << Cleint.getPinCod() << endl;
		cout << "AccountBalance : " << Cleint.getAccountBalance() << endl;
		cout << "____________________________________\n";
	}

	static void _ReadCleintInfo(clsBankCleint& Cleint) {
		cout << "Enter First Name :";
		Cleint.setFirstName(clsInputValidate::ReadString());
		cout << "Enter Last Name :";
		Cleint.setLastName(clsInputValidate::ReadString());
		Cleint.setEmail(clsInputValidate::GetEmailwhienTrue("Enter Email   :"));
		cout << "Enter Phone Number :";
		Cleint.setPhone(clsInputValidate::ReadString());
		cout << "Enter PinCode Name :";
		Cleint.setPinCod(clsInputValidate::ReadString());
		Cleint.setAccountBalance(clsInputValidate::ReaddoubleNumber("Enter New Balance :"));
	}
public:
	static void AddCleintScreen() {
		_DrawHederScrenns("Add New Cleint Card");
		cout << "Enter Account Number:";
		string AccountNumber = clsInputValidate::ReadString();
		while (clsBankCleint::IsCleintExist(AccountNumber))
		{
			cout << "the Account Number is Found Later , Pleas Enter Anther Account Number : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankCleint cleint = clsBankCleint::getAddNewObject(AccountNumber);
		_ReadCleintInfo(cleint);
		clsBankCleint::enSaveResault SaveCleint;
		SaveCleint = cleint.Save();
		switch (SaveCleint)
		{
		case clsBankCleint::SaveResault:
			cout << "the Cleint is Adding Succsessfully :-) \n";
			_PrintCleint(cleint);
			break;
		case clsBankCleint::NoSaveResault:
			cout << "the Cleint is Not Adding Succsessfully :-( \n";
			break;
		case clsBankCleint::ObjectExist:
			cout << "the Cleint is Found yet  :-( \n";
			break;
		default:
			break;
		}
	}
};

