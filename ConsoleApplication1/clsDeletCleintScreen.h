#pragma once
#include"clsScreen.h"
#include"clsAddNewCleintScreen.h"
using namespace std;

class clsDeletCleintScreen:protected clsScreen
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
public:

	static void DeletCleintScreen() {
		_DrawHederScrenns("Delet Cleint Card");
		cout << "Enter Account Number To Delete :";
		string AccountNumber = clsInputValidate::ReadString();
		char answer = 'n';
		while (!clsBankCleint::IsCleintExist(AccountNumber))
		{
			cout << "the Account Number is Not Exist ,Enter Anter Number \n ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankCleint cleint = clsBankCleint::Find(AccountNumber);
		_PrintCleint(cleint);
		cleint = clsBankCleint::getDeletObject(AccountNumber);
		cout << "Do You Want Delet Cleint y/n ";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			clsBankCleint::enSaveResault SaveCleint;
			SaveCleint = cleint.Save();
			switch (SaveCleint)
			{
			case clsBankCleint::SaveResault:
				cout << "the Cleint is Delet Succsessfully :-) \n";
				_PrintCleint(cleint);
				break;
			case clsBankCleint::NoSaveResault:
				cout << "the Cleint is Not Delted :-( \n";
				break;
			case clsBankCleint::ObjectExist:
				cout << "the Cleint is Found yet  :-( \n";
				break;
			default:
				break;
			}
		}

	}

};

