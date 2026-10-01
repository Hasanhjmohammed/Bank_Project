#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"clsString.h"

using namespace std;
class clsBankCurrency
{private:
	enum ModCurrency {
		enEmpty=0,
		enUpadte=1,
	};
	string _Country;
	ModCurrency _Mod;
	string _CodeCurrency;
	string _NameCurrency;
	double _Rate;
	static clsBankCurrency _ConvertFromLinToObject(string line,string spare="#//#") {
		vector<string>CurrencyRecord = clsString::Split(line);
		return clsBankCurrency(ModCurrency::enUpadte,
			CurrencyRecord[0],
			CurrencyRecord[1],
			CurrencyRecord[2],
			stod(CurrencyRecord[3]));
		
 }
	static string _ConvertFromObjectToLin(clsBankCurrency Cureency,string sprate="#//#") {
		string Line = "";
		Line += Cureency.getCountry() + sprate;
		Line += Cureency.getCode() + sprate;
		Line += Cureency.getName() + sprate;
		Line += to_string(Cureency.getRate()) + sprate;
		return Line;
		fstream File;
	}
	static clsBankCurrency _GetEmptyObject() {
		return clsBankCurrency(ModCurrency::enEmpty,
			"",
			"",
			"",
			0.0);
	}

	static vector<clsBankCurrency>_LoadFromFileToObject() {
		vector<clsBankCurrency>Cureecnies;
		fstream File;
		string line = "";
		File.open("Cureencies.txt",ios::in);
		if (File.is_open())
		{
			while (getline(File,line))
			{
				clsBankCurrency Cureency = _ConvertFromLinToObject(line);
				Cureecnies.push_back(Cureency);

			}
			File.close();
		}
		return Cureecnies;
	}
	void _SaveInformationToFile(vector<clsBankCurrency>Cureenies) {
		fstream File;
		string line = "";
		
		File.open("Cureencies.txt", ios::out );
		if (File.is_open())
		{
			for (clsBankCurrency &cur : Cureenies)
			{
				line = _ConvertFromObjectToLin(cur);
				File << line << endl;
			}
			File.close();
		}
		
	}
	void _Update() {
		vector<clsBankCurrency>Cureencies = _LoadFromFileToObject();
		for (clsBankCurrency& cur : Cureencies)
		{
			if (cur.getCode() == getCode())
			{
				cur._Rate = this->_Rate;
				break;
			}
		}
		_SaveInformationToFile(Cureencies);
	}
public:
	string getCode() {
		return _CodeCurrency;
	}
	string getName() {
		return _NameCurrency;
	}
	double getRate() {
		return _Rate;
	}
	string getCountry() {
		return _Country;
	}
	void UpdateReta(double NewRate) {
		_Rate = NewRate;
		_Update();
	}
	bool IsEmpty() {
		return (_Mod == ModCurrency::enEmpty);
	}
	clsBankCurrency(ModCurrency Mod,string Country,string Cod,string Name,double Rate ) {
		this->_Mod = Mod;
		this->_Country = Country;
		this->_CodeCurrency = Cod;
		this->_NameCurrency = Name;
		this->_Rate = Rate;
	}
   
	static clsBankCurrency FindByCodCureency(string CodeCureency) {
		vector<clsBankCurrency>Cureencies = _LoadFromFileToObject();
		for (clsBankCurrency& Cur : Cureencies) {
			if (clsString::PrintMassegAllLetterUpper(Cur.getCode()) == clsString::PrintMassegAllLetterUpper( CodeCureency))
				return Cur;
		}
		return _GetEmptyObject();
	}
	static clsBankCurrency FindByCountryCureency(string CountryCureency) {
		vector<clsBankCurrency>Cureencies = _LoadFromFileToObject();
		for (clsBankCurrency& Cur : Cureencies) {
			if (clsString::PrintMassegAllLetterUpper(Cur.getCountry()) == clsString::PrintMassegAllLetterUpper(CountryCureency))
				return Cur;
		}
		return _GetEmptyObject();
	}
	static bool IsExistObjectByCod(string Code) {
		clsBankCurrency Cureency = clsBankCurrency::FindByCodCureency(Code);
		return (!Cureency.IsEmpty());
	}
	static bool IsExistObjectByCountry(string Country) {
		clsBankCurrency Cureency = clsBankCurrency::FindByCountryCureency(Country);
		return (!Cureency.IsEmpty());
	}

  static vector<clsBankCurrency>GetListCureency() {
		return _LoadFromFileToObject();
	}
  double FromToDoller(double Amount) {
	  return (Amount / getRate());
  }
   double FromCureencyToCureency(double Amount,clsBankCurrency Cureency){
	   double AmountUSA = FromToDoller(Amount);
	   if (Cureency.getCode() == "USD")
		   return AmountUSA;
	   
	   return (AmountUSA * Cureency.getRate());
  }
  

};

