#pragma once
#include <iostream>
#include<string>
using namespace std;
namespace Inaput 
{

	int ReadNumber(string masseg) {
		int n;
		cout << masseg << endl;
		cin >> n;
		return n;
	}

	string ReadText(string masseg) {
		string s;
		cout << "\n" << masseg << endl;
		getline(cin, s);
		//cin >> s;
		return s;
	}

	int ReadNumberInRang(int From, int To) {
		int n;
		do {
			cout << "\nPleas Enter Number btween " << From << "and " << To << endl;
			cin >> n;

		} while (n<From ||n>To);
		
		return n;
	}

	int ReadPositiveNumber(string masseg) {
		int n;
		

		do {
			cout << masseg << endl;
			cin >> n;
		} while (n<0);
		return n;
	}
	void PrintText(string masseg) {

		cout << masseg<<endl ;
	}

}
