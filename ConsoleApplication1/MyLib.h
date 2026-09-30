#pragma once

#include <iostream>
#include<math.h>
using namespace std;
namespace Hasan
{

	void test() {
		cout << "Hi ,I am hier , end i am programming\n";
	}

	int Sum(int a, int b) {
		cout << "The Sum Is : ";
		return (a + b);
	}

	void PrintArr(int arr[100], int arrLenght) {
		cout << endl;
		for (int i = 0; i < arrLenght; i++) {
	
			cout <<"the [" <<i+1<< "]  :" << arr[i]<<endl;
		}
	}

}
