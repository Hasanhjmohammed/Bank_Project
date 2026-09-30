#pragma once
#include<iostream>
#include"clsScreen.h";
#include"clsMainScreen.h"
#include"clsBankCleint.h"
#include"clsInputValidate.h"
#include"clsTotalBalanceScreen.h"
#include"clsDepositScreen.h"
#include"clsWithDrwaScreen.h"
#include"clsTransfetScreen.h"
#include"clsListTransferTransactionScreen.h"
using namespace std;

class clsTransactionScreen:protected clsScreen	
{
private:
    enum enTransactionMenauOptions {
        enDesposit = 1,
        enwithdraw = 2,
        enTotalBalance = 3,
        enTransfer=4,
        enListTransferTransaction=5,
        enMainScreen = 6
    };
  static int _ReadTransactionMenueOption() {
        int number = clsInputValidate::ReadIntergetNumberBetween(1,6,"Pleas Enter Number Between 1 and 6 ");
        return number;
    }
  static void  _DespositScreen() {
      clsDepositScreen::DepositCleintScreen();
    }
  static void  _WithDrawScreen() {
      clsWithDrwaScreen::WithDrawCleintScreen();
  }
  static void  _TotalBalanceScreen() {
      clsTotalBalanceScreen::ShowToatalBalanceScreen();
  }
  static void  _TransferScreen() {
      clsTransfetScreen::ShowTransferScreen();
  }
  static void _ShowListTransferScreen() {
      clsListTransferTransactionScreen::ShowListTransferTranactionScreen();
  }
  static void _GoToTransactionScreen() {
      cout << "Pleas Enter Any press.....";
      system("pause>0");
      TransactionScreen();
  }
  static void _GoToMain() {
    
     // clsMainScreen::ShowMainMenue();
  }
  static void _performansTransactionScreen(enTransactionMenauOptions Option) {
      switch (Option)
      {
      case clsTransactionScreen::enDesposit:
          system("cls");
          _DespositScreen();
          _GoToTransactionScreen();
          break;
      case clsTransactionScreen::enwithdraw:
          system("cls");
          _WithDrawScreen();
          _GoToTransactionScreen();
          break;
      case clsTransactionScreen::enTotalBalance:
          system("cls");
          _TotalBalanceScreen();
          _GoToTransactionScreen();
          break;
      case clsTransactionScreen::enTransfer:
          system("cls");
          _TransferScreen();
          _GoToTransactionScreen();
          break;
      case clsTransactionScreen::enListTransferTransaction:
          system("cls");
          _ShowListTransferScreen();
          _GoToTransactionScreen();
          break;
      case clsTransactionScreen::enMainScreen:
          break;
      default:
          break;
      }
    }
protected:
public:
	static void TransactionScreen() {
		system("cls");
		_DrawHederScrenns("Transaction Screen ");
        cout << "\t\t\t\t\t" << "================================================\n";
        cout << "\t\t\t\t\t" << "\t\t Transaction Menau Screen \n";
        cout << "\t\t\t\t\t" << "================================================\n";
        cout << "\t\t\t\t\t" << "\t[1] Deposit Screen\n";
        cout << "\t\t\t\t\t" << "\t[2] With Draw Screen \n";
        cout << "\t\t\t\t\t" << "\t[3] Total Balances Screen \n";
        cout << "\t\t\t\t\t" << "\t[4] Transfer Screen \n";
        cout << "\t\t\t\t\t" << "\t[5] Shwow List Transfer Transaction  Screen \n";
        cout << "\t\t\t\t\t" << "\t[6] Back To Main Menue \n";
        cout << "\t\t\t\t\t" << "================================================\n";
       _performansTransactionScreen(enTransactionMenauOptions(_ReadTransactionMenueOption()));
	}

};

