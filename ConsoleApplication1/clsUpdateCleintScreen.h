#pragma once
#include<iostream>
#include"clsScreen.h"
using namespace std;
class clsUpdateCleintScreen:public clsScreen
{
private:
	enum enChoosUpdate
	{
		All = 1,
		eFirstName = 2,
		eLastName = 3,
		eEmail = 4,
		ePhone = 5,
		ePinCode = 6,
		eBalance = 7

	};
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

static	void _ReadCleintInfo(clsBankCleint& Cleint) {
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
static	void _ReadFirstName(clsBankCleint& Cleint) {
		cout << "Enter First Name :";
		Cleint.setFirstName(clsInputValidate::ReadString());
	}
static	void _ReadLastName(clsBankCleint& Cleint) {
		cout << "Enter Last Name :";
		Cleint.setLastName(clsInputValidate::ReadString());
	}
static  void _ReadEmail(clsBankCleint& Cleint) {
		Cleint.setEmail(clsInputValidate::GetEmailwhienTrue("Enter Email   :"));
	}
static	void _ReadPhone(clsBankCleint& Cleint) {
		cout << "Enter Your Phone Number ";
		Cleint.setPhone(clsInputValidate::ReadString());
	}
static	void _ReadPinCode(clsBankCleint& Cleint) {
		cout << "Enter PinCode ";
		Cleint.setPinCod(clsInputValidate::ReadString());
	}
static	void _ReadBalance(clsBankCleint& Cleint) {
		Cleint.setAccountBalance(clsInputValidate::ReaddoubleNumber("Enter Your Balance "));
	}
static  void  _UpdateStart(enChoosUpdate chooesupadte, clsBankCleint& Cleint) {
	switch (chooesupadte)
	{
	case All:
		_ReadCleintInfo(Cleint);
		break;
	case eFirstName:
		_ReadFirstName(Cleint);
		break;
	case eLastName:
		_ReadLastName(Cleint);
		break;
	case eEmail:
		_ReadEmail(Cleint);
		break;
	case ePhone:
		_ReadPhone(Cleint);
		break;
	case ePinCode:
		_ReadPinCode(Cleint);
		break;
	case eBalance:
		_ReadBalance(Cleint);
		break;
	default:
		break;
	}
}
static  void _ChooesUpdate(clsBankCleint& Cleint) {
	short Number;
	cout << "______________________________\n";
	cout << "if Want Update All Data Enter    [1]\n";
	cout << "if Want Update Only FirstName    [2]\n";
	cout << "if Want Update Only Last Name    [3]\n";
	cout << "if Want Update Only Email        [4]\n";
	cout << "if Want Update Only Phone Number [5]\n";
	cout << "if Want Update Only PinCode      [6]\n";
	cout << "if Want Update Only Your Balance [7]\n";
	cout << "___________________________________\n";
	
	Number = clsInputValidate::ReadInterNumber("");
	system("cls");
	_UpdateStart((enChoosUpdate)Number, Cleint);
}
public:
static	void UpdateCleintScreen() {
	  _DrawHederScrenns("Upadte Cleint Screen ");
		string AccountNumber = "";
		cout << "Pleas Enter Account Number To Update : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankCleint::IsCleintExist(AccountNumber))
		{
			cout << "The Cleint is Not Found , Enter Anther Account Number : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankCleint Cleint = clsBankCleint::Find(AccountNumber);
		_PrintCleint(Cleint);

		cout << "\t Update Cleint Info \n";
		cout << "------------------------------------\n";
		_ChooesUpdate(Cleint);
		clsBankCleint::enSaveResault SaveCleint;
		SaveCleint = Cleint.Save();
		switch (SaveCleint)
		{
		case clsBankCleint::SaveResault:
			cout << "the Cleint is Update Succsessfully :-) \n";
			_PrintCleint(Cleint);
			break;
		case clsBankCleint::NoSaveResault:
			cout << "the Cleint is Not Update Succsessfully :-( \n";
			break;
		default:
			break;
		}
	}


};

