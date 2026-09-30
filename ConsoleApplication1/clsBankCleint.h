#pragma once
#include<iostream>
#include"clsPerson.h"
#include<vector>
#include<string>
#include"clsString.h"
#include<fstream>
#include "clsUtil.h"
#include"Globelheader.h"
#include"clsInputValidate.h"

using namespace std;
class clsBankCleint:public clsPerson
{
private:
	enum enMod {
		EmptyMod=0,
		UpdateMod=1,
		AddNewMod=2,
		DeletMod=3
	};
	enMod _Mod;
	string _AccountNumber;
	string _PinCod;
	double _AccountBalance;
	bool _IsMark = false;
	struct stTransferCleint;
	static stTransferCleint _ConvertFromLineToStruct(string line,string Spa="#//#") {
		vector<string>InformationTransfer = clsString::Split(line);
		stTransferCleint TrnsferCleint;
		TrnsferCleint.DateTime = InformationTransfer[0];
		TrnsferCleint.AccountNumberFrom = InformationTransfer[1];
		TrnsferCleint.AccountNumberTo = InformationTransfer[2];
		TrnsferCleint.BalanceFrom = stod(InformationTransfer[3]);
		TrnsferCleint.BanlaceTo = stod(InformationTransfer[4]);
		TrnsferCleint.Amount = stod(InformationTransfer[5]);
		TrnsferCleint.UserName = InformationTransfer[6];
		return TrnsferCleint;
	
	}
	static string _ConvertFromObjectToLine(clsBankCleint cleint,string demo) {
		string line = "";
		line += cleint.getAccountNumber() + demo;
		line += cleint.getPinCod() + demo;
		line += cleint.getFirstName() + demo;
		line += cleint.getLastName() + demo;
		line += cleint.getEmail() + demo;
		line += cleint.getPhone() + demo;
		line += to_string(cleint.getAccountBalance());
		return line;
	}
     static	vector<clsBankCleint>_LoadFromFileToObject() {
		fstream MyFile;
		string line;
		vector <clsBankCleint>Cleints;
		MyFile.open("MyCleints.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{
				
				clsBankCleint cleint = _CounverFromLineToObject(line, "#//#");

				Cleints.push_back(cleint);
			}
			MyFile.close();
		}
		return Cleints;
	}
	static void _SaveCleintDateToFile(vector<clsBankCleint>Cleints){
	fstream MyFile;
	string line;
	MyFile.open("MyCleints.txt", ios::out);
	if (MyFile.is_open())
	{
		for(clsBankCleint & c:Cleints)
		{
			if (!c._IsMark)
			{
				line = _ConvertFromObjectToLine(c, "#//#");
				MyFile << line << endl;
			}
		}
		MyFile.close();
	}
}
	 void _Update() {
		vector<clsBankCleint>Cleints;
		Cleints = _LoadFromFileToObject();
		for (clsBankCleint& c : Cleints)
		{
			if (c.getAccountNumber() == this->getAccountNumber())
			{
				c = *this;
				break;
			}
		}

		_SaveCleintDateToFile(Cleints);
	}
	 void _Adding(){

		 _AddDatelineToFile(_ConvertFromObjectToLine(*this,"#//#"));
		/* vector<clsBankCleint>Cleints = _LoadFromFileToObject();
		 Cleints.push_back(*this);
		 _SaveCleintDateToFile(Cleints);*/
	 }
	 void _AddDatelineToFile(string line) {
		 fstream MyFile;
		 MyFile.open("MyCleints.txt", ios::app);
		 if (MyFile.is_open())
		 {
			 MyFile << line << endl;
		 }
		 MyFile.close();
	 }
	 void _Deleted() {
		 vector<clsBankCleint>Cleints;
		 Cleints = _LoadFromFileToObject();
		 for (clsBankCleint& c : Cleints)
		 {
			 if (c.getAccountNumber() == this->_AccountNumber)
			 {
				 c._IsMark = true;
				 break;
			 }
		 }
		 _SaveCleintDateToFile(Cleints);
	 }

	 string  _PreperTransferToRecord(clsBankCleint CleintFrom, clsBankCleint CleintTo,double Amount) {
		 string line = "";
		 string sprate = "#//#";
		 line += clsDate::GetSysteamDateTimeString() + sprate;
		 line += CleintFrom.getAccountNumber() + sprate;
		 line += CleintTo.getAccountNumber() + sprate;
		 line += to_string(CleintFrom.getAccountBalance()) + sprate;
		 line += to_string(CleintTo.getAccountBalance()) + sprate;
		 line += to_string(Amount) + sprate;
		 line += CurrentUser.getUserName();
		 return line;
	}
static	clsBankCleint _CounverFromLineToObject(string Line, string demo) {
		vector <string>cleint = clsString::Split(Line, demo);
		return clsBankCleint(enMod::UpdateMod,
          cleint[2],cleint[3],cleint[4],cleint[5],cleint[0],cleint[1], stod(cleint[6])
		);
	}

static clsBankCleint _EmptyCleint() {
	return clsBankCleint(enMod::EmptyMod,
		"", "", "", "", "", "",0.0
	);
  }
public:
	struct stTransferCleint
	{
		string DateTime;
		string AccountNumberFrom;
		string AccountNumberTo;
		double BalanceFrom;
		double BanlaceTo;
		double Amount;
		string UserName;

	};
	string getAccountNumber() {
		return _AccountNumber;
	}
	double getAccountBalance() {
		return _AccountBalance;
	}
	string getPinCod() {
		return _PinCod;
	}
	void  setAccountBalance(double AccountBalance) {
		 _AccountBalance=AccountBalance;
	}
	void setPinCod(string PinCod) {
		 _PinCod=PinCod;
	}

	clsBankCleint(enMod Mod,string FirstName,string LastName,string Email,string Phone,string AccountNumber,string PinCod,double AccountBalance)
		:
		clsPerson(FirstName,LastName,Email,Phone) {
		_Mod = Mod;
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
		_PinCod = PinCod;
	}

	void Deposit(double Amount){
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount) {
		if (Amount <= _AccountBalance)
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
		return false;
		
	}
static	bool Transfer(clsBankCleint & CleintFrom,clsBankCleint & CleintTo,int Amount){
		if (CleintFrom.Withdraw(Amount))
		{
			CleintTo.Deposit(Amount);
			return true;
		}
		return false;
	}
	bool IsEmpty() {
		return (_Mod == enMod::EmptyMod);
	}
	static 	clsBankCleint Find(string AccountNumber) {
		fstream MyFile;
		string line;
		//vector <clsBankCleint>Cleints;
		MyFile.open("MyCleints.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{
				clsBankCleint cleint=_CounverFromLineToObject(line, "#//#");
				if (cleint.getAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return cleint;
				}
				//Cleints.push_back(cleint);
			}
			MyFile.close();
		}
		return _EmptyCleint();
	}

	static 	clsBankCleint Find(string AccountNumber,string PinCod) {
		fstream MyFile;
		string line;
		MyFile.open("MyCleints.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, line))
			{
				clsBankCleint cleint = _CounverFromLineToObject(line, "#//#");
				if (cleint._AccountNumber == AccountNumber && cleint._PinCod==PinCod)
				{
					MyFile.close();
					return cleint;
				}
			}
			MyFile.close();
		}
		return _EmptyCleint();
	}

	static bool IsCleintExist(string AccountNumber) {
		clsBankCleint Cleint = clsBankCleint::Find(AccountNumber);
		return (!Cleint.IsEmpty());


	}

	enum enSaveResault {
		SaveResault = 0,
	   NoSaveResault=1,
	   ObjectExist=2
	};

	enSaveResault Save() {

		switch (_Mod)
		{
		case clsBankCleint::EmptyMod:
			if (IsEmpty())
			return enSaveResault::NoSaveResault;
			break;
		case clsBankCleint::UpdateMod:
			_Update();
			return enSaveResault::SaveResault;
			break;
		case clsBankCleint::AddNewMod:
		{
			if (clsBankCleint::IsCleintExist(_AccountNumber))
			{
				return enSaveResault::ObjectExist;
			}
			else
			{
				_Adding();
				_Mod = enMod::UpdateMod;
				return enSaveResault::SaveResault;
			}
			
		}
			break;
		case clsBankCleint::DeletMod:
			_Deleted();
			return enSaveResault::SaveResault;
		default:
			break;
		}

	}

static	clsBankCleint getAddNewObject(string AccountNumber) {
		return clsBankCleint(enMod::AddNewMod,"","","","",AccountNumber,"",0.0);
	}
static	clsBankCleint getDeletObject(string AccountNumber) {
	return clsBankCleint(enMod::DeletMod, "", "", "", "", AccountNumber, "", 0.0);
}

static vector<clsBankCleint>GetCleintsList() {
	return _LoadFromFileToObject();
}

static double GetTotalBalance() {
	vector<clsBankCleint>Cleints = GetCleintsList();
	double totalBalances = 0;
	for (clsBankCleint C : Cleints)
	{
		totalBalances += C.getAccountBalance();
	}
	return totalBalances;
}

void WriteTransferInFile(clsBankCleint CleintTo,double Amount) {

	fstream File;
	string line = "";
	File.open("TransferCleint.txt", ios::app | ios::out);
	if (File.is_open())
	{
		line = _PreperTransferToRecord(*this, CleintTo,Amount);
		File << line << endl;
	}
	File.close();
}
static vector<stTransferCleint>GetListTransferTranaction() {
	fstream File;
	string Line="";
	vector<stTransferCleint>TransferCleints;
	stTransferCleint TransferCleint;
	File.open("TransferCleint.txt",ios::in);
	if (File.is_open())
	{
		while (getline(File,Line))
		{
			TransferCleint = _ConvertFromLineToStruct(Line);
			TransferCleints.push_back(TransferCleint);
		}
	}
	File.close();
	return TransferCleints;

}

};

