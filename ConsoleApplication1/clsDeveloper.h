#pragma once
#include<iostream>
#include"clsEmployee.h"
#include"clsPerson.h"

class clsDeveloper :public clsEmployee {
private:
	string _MainProgrammingLanguage;

public:
	clsDeveloper(string FirstName,string LastName,string Email,string Phone,string Titel,string Depratment,float Salary,string MainLangauge):
		clsEmployee(FirstName,LastName,Email,Phone,Titel,Depratment,Salary) {
		_MainProgrammingLanguage = MainLangauge;
	}
	void setMainProgrammingLanguage(string MainLangauge) {
		_MainProgrammingLanguage = MainLangauge;
	}
	string getMainProgrammingLangauge() {
		return _MainProgrammingLanguage;
	}
	void Print() {
		cout << "\nInfo :\n";
		cout << "____________________________________\n";
		cout << "FirstName     : " << getFirstName() << endl;
		cout << "LastName      : " << getLastName() << endl;
		cout << "FullName      : " << FullName() << endl;
		cout << "Email         : " << getEmail() << endl;
		cout << "Phone         : " << getPhone() << endl;
		cout << "Tile          : " << getTitel() << endl;
		cout << "Department    : " << getDepartment() << endl;
		cout << "Salary        : " << getSalary() << endl;
		cout << "pLangauge     : " << _MainProgrammingLanguage << endl;
		cout << "____________________________________\n";
	}
	void ModifiySalary() {
		clsEmployee::_Salary *= 1.2;
	}
};

