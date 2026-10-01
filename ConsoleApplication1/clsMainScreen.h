#pragma once
#include"clsScreen.h"
#include"clsListCleintScreen.h"
#include"clsAddNewCleintScreen.h"
#include"clsDeletCleintScreen.h"
#include"clsUpdateCleintScreen.h"
#include"clsFindCleintScreen.h"
#include"clsTransactionScreen.h"
#include"clsManagmentusersScreen.h"
#include"clsNotPermissionScreen.h"
#include"Globelheader.h"
#include"clsLogInRegisterScreen.h"
#include"clsCurrencyExchangScreen.h"
class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenauOptions
    {
        enShowCleintList = 1,
        enAddNewCleint = 2,
        enDeleteCleint = 3,
        enUpdeteCleint = 4,
        enFindCleint = 5,
        enTransaction = 6,
        enManagmentUser = 7,
        enLogInRegister=8,
        enCurrencyExchang=9,
        LogOut = 10,
    };
  /*  static bool _IsHavePermission(int per) {
        if (CurrentUser.getPermission() == -1)
            return true;
        return ((CurrentUser.getPermission() & per) == per);
    }*/
    static int   _ReadMainMenueOption() {
        int number = clsInputValidate::ReadIntergetNumberBetween(1,10,"Enter Number Between 1 and 10 ");
        return number;
    }
    static void  _ShowCleintListScreen() {
        if (!CurrentUser._IsHavePermission(1))
        {
            clsNotPermissionScreen::ShowNotPermissionScreen();
            return;
        }
        clsListCleintScreen::ShowCleintsList();
       
    }
    static void  _AddNewCleintScreen() {
        if (!CurrentUser._IsHavePermission(2))
        {
            clsNotPermissionScreen::ShowNotPermissionScreen();
            return;
        }
        clsAddNewCleintScreen::AddCleintScreen();
    }
    static void  _DeletCleintScreen() {
        if (!CurrentUser._IsHavePermission(4))
        {
            clsNotPermissionScreen::ShowNotPermissionScreen();
            return;
        }
        clsDeletCleintScreen::DeletCleintScreen();
    }
    static void  _UpdateCleintScreen() {
        if (!CurrentUser._IsHavePermission(8))
        {
            clsNotPermissionScreen::ShowNotPermissionScreen();
            return;
        }
        clsUpdateCleintScreen::UpdateCleintScreen();
    }
    static void  _FindCleintScreen() {
        if (!CurrentUser._IsHavePermission(16))
        {
            clsNotPermissionScreen::ShowNotPermissionScreen();
            return;
        }
        clsFindCleintScreen::FindCleintScreen();
    }
    static void  _TransactionScreen() {
        if (!CurrentUser._IsHavePermission(32))
        {
            clsNotPermissionScreen::ShowNotPermissionScreen();
            return;
        }
        clsTransactionScreen::TransactionScreen();
    }
    static void  _ManagmentUserScreen() {
        if (!CurrentUser._IsHavePermission(64))
        {
            clsNotPermissionScreen::ShowNotPermissionScreen();
            return;
        }
        clsManagmentusersScreen::ShowManagmentScreen();
    }
    static void _LogInRegisterScreen() {
        if (!CurrentUser._IsHavePermission(128))
        {
            clsNotPermissionScreen::ShowNotPermissionScreen();
            return;
        }
        clsLogInRegisterScreen::ShowLogInRegisterScreen();
    }
    static void _CurrencyExchangScreen() {
        clsCurrencyExchangScreen::showCurrencyExchangScreen();
    }
    static void  _EndMainScreen() {
       // clsLoginScreen::ShowLoginScreen();
        CurrentUser = clsBankUser::Find("");
      //  cout << "thank you for useing my programm  -:)\n";
       // system("pause>0");
    }
    static void  _GoToBackMainScreen() {
        cout << "pleas Enter Any press ......";
        system("pause>0");
        ShowMainMenue();
    }
    static void  _performansMainScreen(enMainMenauOptions Option) {

        switch (Option)
        {
        case clsMainScreen::enShowCleintList:
            system("cls");
            _ShowCleintListScreen();
            _GoToBackMainScreen();
            break;
        case clsMainScreen::enAddNewCleint:
            system("cls");
            _AddNewCleintScreen();
            _GoToBackMainScreen();
            break;
        case clsMainScreen::enDeleteCleint:
            system("cls");
            _DeletCleintScreen();
            _GoToBackMainScreen();
            break;
        case clsMainScreen::enUpdeteCleint:
            system("cls");
            _UpdateCleintScreen();
            _GoToBackMainScreen();
            break;
        case clsMainScreen::enFindCleint:
            system("cls");
            _FindCleintScreen();
            _GoToBackMainScreen();
            break;
        case clsMainScreen::enTransaction:
            system("cls");
            _TransactionScreen();
            _GoToBackMainScreen();
            break;
        case clsMainScreen::enManagmentUser:
            system("cls");
            _ManagmentUserScreen();
            _GoToBackMainScreen();
            break;
        case clsMainScreen::enLogInRegister:
            system("cls");
            _LogInRegisterScreen();
            _GoToBackMainScreen();
            break;
        case clsMainScreen::enCurrencyExchang:
            system("cls");
            _CurrencyExchangScreen();
            _GoToBackMainScreen();
            break;
        case clsMainScreen::LogOut:
            system("cls");
            _EndMainScreen();
            break;
        default:
            break;
        }
    }

public:
	static void  ShowMainMenue() {
		system("cls");
		_DrawHederScrenns("Main Menue Screen ");

        cout <<"\t\t\t\t\t" << "================================================\n";
        cout << "\t\t\t\t\t" << "\t\t Main Menau Screen \n";
        cout << "\t\t\t\t\t" << "================================================\n";
        cout << "\t\t\t\t\t" << "\t[1] Show Cleint List\n";
        cout << "\t\t\t\t\t" << "\t[2] Add New Cleint \n";
        cout << "\t\t\t\t\t" << "\t[3] Delet Cleint \n";
        cout << "\t\t\t\t\t" << "\t[4] Update Cleint \n";
        cout << "\t\t\t\t\t" << "\t[5] Find Cleint \n";
        cout << "\t\t\t\t\t" << "\t[6] Transaction Cleint \n";
        cout << "\t\t\t\t\t" << "\t[7] Managements Users \n";
        cout << "\t\t\t\t\t" << "\t[8] Show LogIn Register \n";
        cout << "\t\t\t\t\t" << "\t[9] Currency Exchang \n";
        cout << "\t\t\t\t\t" << "\t[10] Logout \n";
        cout << "\t\t\t\t\t" << "================================================\n";
        _performansMainScreen(enMainMenauOptions(_ReadMainMenueOption()));
	}
};

