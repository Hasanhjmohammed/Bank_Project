#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrencyExchangScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCalcolateCurrencyScreen.h"
#include"clsListCurrencyScreen.h"
using namespace std;
class clsCurrencyExchangScreen:protected clsScreen
{
private:
    enum enCurrencyOptions {
        enListCurrency = 1,
        enFindCurrency=2,
        enUpdateCurrency=3,
        enCurrencyCalcolater=4,
        enMainScreen=5
   };

  static short _ReadCurrencyOption() {
      short Number = clsInputValidate::ReadIntergetNumberBetween(1, 5, "Enter Number Between 1 and 5");
      return Number;
  }
  static void _ListCurrencyScreen() {
      clsListCurrencyScreen::ShowListCurrenncyScreen();
  }
  static void _FidCurrencyScreen() {
      clsFindCurrencyScreen::ShowFindCurrencyScreen();
  }
  static void _UpdateCurrencyScreen() {
      clsUpdateCurrencyScreen::ShowUpadteCurrencyScreen();
  }
  static void _CalcolateCurrencyScreen() {
      clsCalcolateCurrencyScreen::ShowCalcolateCurrencyScreen();
  }
  static void GoToCurrncyScreen() {
      cout << "Pleas Enter Any Press.....";
      system("pause>0");
      showCurrencyExchangScreen();
  }
  static void _performansCurrencyScreen(enCurrencyOptions Option) {
      switch (Option)
      {
      case clsCurrencyExchangScreen::enListCurrency:
          system("cls");
          _ListCurrencyScreen();
          GoToCurrncyScreen();
          break;
      case clsCurrencyExchangScreen::enFindCurrency:
          system("cls");
          _FidCurrencyScreen();
          GoToCurrncyScreen();
          break;
      case clsCurrencyExchangScreen::enUpdateCurrency:
          system("cls");
          _UpdateCurrencyScreen();
          GoToCurrncyScreen();
          break;
      case clsCurrencyExchangScreen::enCurrencyCalcolater:
          system("cls");
          _CalcolateCurrencyScreen();
          GoToCurrncyScreen();
          break;
      case clsCurrencyExchangScreen::enMainScreen:
          break;
      default:
          break;
      }
  }
public:
	static	void showCurrencyExchangScreen() {
        system("cls");
		_DrawHederScrenns("Currency Exchang Screen");
        cout << "\t\t\t\t\t" << "================================================\n";
        cout << "\t\t\t\t\t" << "\t\t Currency Exchang Screen \n";
        cout << "\t\t\t\t\t" << "================================================\n";
        cout << "\t\t\t\t\t" << "\t[1] Currency List\n";
        cout << "\t\t\t\t\t" << "\t[2] Find Currency  \n";
        cout << "\t\t\t\t\t" << "\t[3] Update Rate \n";
        cout << "\t\t\t\t\t" << "\t[4] Currency Calcolater \n";
        cout << "\t\t\t\t\t" << "\t[5] Main Screen \n";
        cout << "\t\t\t\t\t" << "================================================\n";
        _performansCurrencyScreen(enCurrencyOptions(_ReadCurrencyOption()));
}
};

