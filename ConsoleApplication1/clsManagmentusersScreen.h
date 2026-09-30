#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsListUserScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeletUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

class clsManagmentusersScreen:protected clsScreen
{private:
    enum enManagmentUsers {
        enListUser = 1,
        enAddnewUser = 2,
        enDeleteUser = 3,
        enUpdateUser = 4,
        enFindUser = 5,
        enMainMenue = 6
    };
  static void  _ListUsersScreen() {
      clsListUserScreen::ShowListUserScreen();
       }
  static void  _AddNewUserScreen() {
      clsAddNewUserScreen::ShowAddNewUserScreen();
  }
  static void  _DeletUserScreen() {
      clsDeletUserScreen::ShowDeletUserScreen();
  }
  static void  _UpdateUserScreen() {
      clsUpdateUserScreen::ShowUpdateUserScreen();
  }
  static void  _FindUserScreen() {
      clsFindUserScreen::ShowFindUserScreen();
  }
    static void   _GoToBackManagmetUser() {
        cout << "Pleas Enter Any press .....";
        system("pause>0");
        ShowManagmentScreen();
  }
    static short _ReadManagemt(){
        short Number = clsInputValidate::ReadIntergetNumberBetween(1, 6, "Enter Number Between 1 and 6");
        return Number;
    }
  static  void _PreformansManagmentUsers(enManagmentUsers managment) {
        switch (managment)
        {
        case enListUser:
            system("cls");
            _ListUsersScreen();
            _GoToBackManagmetUser();
            break;
        case enAddnewUser:
            system("cls");
            _AddNewUserScreen();
            _GoToBackManagmetUser();
            break;
        case enDeleteUser:
            system("cls");
            _DeletUserScreen();
            _GoToBackManagmetUser();
            break;
        case enUpdateUser:
            system("cls");
            _UpdateUserScreen();
            _GoToBackManagmetUser();
            break;
        case enFindUser:
            system("cls");
            _FindUserScreen();
            _GoToBackManagmetUser();
            break;
        case enMainMenue:
            break;
        default:
            break;
        }
    }
public :
  static void  ShowManagmentScreen() {
      system("cls");
      _DrawHederScrenns("Managment User Screen ");
      cout << "\t\t\t\t\t " << "\t[1]List User  \n";
      cout << "\t\t\t\t\t " << "\t[2]Add New User  \n";
      cout << "\t\t\t\t\t " << "\t[3]Delete User \n";
      cout << "\t\t\t\t\t " << "\t[4]Update User  \n";
      cout << "\t\t\t\t\t " << "\t[5]Find User  \n";
      cout << "\t\t\t\t\t " << "\t[6]Main Menue   \n\n";
      cout << "\t\t\t\t\t " << "================================================\n";
      _PreformansManagmentUsers((enManagmentUsers)_ReadManagemt());
    }



};

