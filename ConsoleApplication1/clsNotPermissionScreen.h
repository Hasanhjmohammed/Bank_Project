#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsMainScreen.h"
class clsNotPermissionScreen:protected clsScreen
{
public:
	static void ShowNotPermissionScreen() {
		_DrawHederScrenns("Acess Benied! Contact Your Admin ");
	/*	cout << "Enter Any Press To Back Main Screen..........";
		system("pause>");*/
	}
};

