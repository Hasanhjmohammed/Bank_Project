#pragma once

#include<iostream>
using namespace std;
class clsPerson {
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
	
public:
	clsPerson(
		 string FirstName, string LastName, string Email, string Phone)
	{
		this->_FirstName = FirstName;
		this->_LastName = LastName;
		this->_Email = Email;
		this->_Phone = Phone;
	};

	string FullName() {
		return this->_FirstName + " " + this->_LastName;
	}
	void Print() {
		cout << "\nInfo :\n";
		cout << "____________________________________\n";
	
		cout << "FirstName     :" << _FirstName << endl;
		cout << "LastName      :" << _LastName << endl;
		cout << "FullName      :" << FullName() << endl;
		cout << "Email         :" << _Email << endl;
		cout << "Phone         :" << _Phone << endl;
		cout << "____________________________________\n";
	}

	void setFirstName(string Name) {
		this->_FirstName = Name;
	}
	void setLastName(string Name) {
		this->_LastName = Name;
	}
	void setEmail(string Email) {
		_Email = Email;
	}
	void setPhone(string Phone) {
		_Phone = Phone;
	}

	
	string  getFirstName() {
		return _FirstName;
	}
	string getLastName() {
		return _LastName;
	}

	string getEmail() {
		return _Email;
	}
	string  getPhone() {
		return _Phone;
	}

	void SendEmail(string Head, string Body) {
		cout << "\n the follwing message sent successfully to email :";
		cout << _Email << endl;
		cout << "Subject : " << Head << endl;
		cout << "Body : " << Body << endl;
	}
	void SendSMS(string Body) {
		cout << "\n the follwing SMS sent successfully to Phone :";
		cout << _Phone << endl;
		cout << "Body : " << Body << endl;
	}

};

