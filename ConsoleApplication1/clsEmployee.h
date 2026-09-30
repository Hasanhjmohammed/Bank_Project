#pragma once
#include<iostream>
#include"clsPerson.h"

class clsEmployee :public clsPerson {


protected:
	string _Titel;
	string _Department;
	double _Salary;
public:
	clsEmployee( string FirstName, string LastName, string Email, string Phone,string Titel,string Department,float Salary)
		:clsPerson( FirstName, LastName, Email, Phone) {
		_Salary = Salary;
		_Titel = Titel;
		_Department = Department;
	}
	string getTitel() {
		return _Titel;
	}
	string getDepartment() {
		return _Department;
	}
	double getSalary() {
		return _Salary;
	}
	void setTitle(string title) {
		_Titel = title;
	}
	void setDepartment(string department) {
		_Department = department;
	}
	void setSalary(double salary) {
		_Salary = salary;
	}

	void Print() {
		cout << "\nInfo :\n";
		cout << "____________________________________\n";
	
		cout << "FirstName     : " << getFirstName() << endl;
		cout << "LastName      : " << getLastName() << endl;
		cout << "FullName      : " << FullName() << endl;
		cout << "Email         : " << getEmail() << endl;
		cout << "Phone         : " << getPhone() << endl;
		cout << "Tile          : " << _Titel << endl;
		cout << "Department    : " << _Department << endl;
		cout << "Salary        : " << _Salary << endl;
		cout << "____________________________________\n";
	}
};


