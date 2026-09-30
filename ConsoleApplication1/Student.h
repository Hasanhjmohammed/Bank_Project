#pragma once
#include <iostream>
#include<string>
using namespace std;
namespace MyStudent {

	void ReadArr(int Arr[100], int arrlenght) 
	{
		cout << "Pleas Enter your Maeker \n";
	    for (int i = 0; i < arrlenght; i++)
	    {
			cout << "The Marker----- [" << i + 1 << "]---- \n";
			cin >> Arr[i];

	    }

	}
	void PrintArr(int Arr[100], int arrlenght)
	{
		for (int i = 0; i < arrlenght; i++)
		{
			cout << "The Marker [" << i + 1 << " ] is :" << Arr[i] << endl;

		}

	}
	float Avrege(int arr[100], int arrlenght) {
		int counter = 0;
		for (int i = 0; i < arrlenght; i++) 
		{
		
			counter += arr[i];
		}
		return (float)counter / arrlenght;
	}

	void Reasault(float Avrege) {

		if (Avrege >= 60)
		{
			cout << "You Are Sccuesful \n";
		}
		else
		{
			cout << "You Are fail \n";
		}
	}
	
}
