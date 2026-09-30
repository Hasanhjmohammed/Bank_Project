#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankUser.h"
using namespace std;
class clsAddNewUserScreen:protected clsScreen
{
private:

static void	setPermission(clsBankUser & user) {
	char answer;
	int Permission =0;
        cout << "Do you want to give full access y/n ? : ";
        cin >> answer;
		//user.setPermission(0);
        if (tolower(answer) == 'y')
        {
			Permission = -1;
			//user.setPermission(-1) ;
        }
        else
        {
            cout << "Do You want give access to : \n";
            cout << "Show Cleints List y/n : ";
            cin >> answer;
			if (tolower(answer) == 'y')
				Permission += 1;
				//user.setPermission(user.getPermission()+1);
            cout << "Add New Cleint  y/n : ";
            cin >> answer;
			if (tolower(answer) == 'y')
				Permission += 2;
				//user.setPermission(user.getPermission() + 2);
            cout << "Delete Cleint  y/n : ";
            cin >> answer;
			if (tolower(answer) == 'y')
				Permission += 4;
			//	user.setPermission(user.getPermission() + 4);
            cout << "Update Cleint  y/n : ";
            cin >> answer;
			if (tolower(answer) == 'y')
				Permission += 8;
				//user.setPermission(user.getPermission() + 8);
            cout << "Find Cleint  y/n : ";
            cin >> answer;
			if (tolower(answer) == 'y')
				Permission += 16;
				//user.setPermission(user.getPermission() + 16);
            cout << "Transaction  y/n : ";
            cin >> answer;
			if (tolower(answer) == 'y')
				Permission += 32;
			//	user.setPermission(user.getPermission() + 32);
            cout << "Managment User  y/n : ";
            cin >> answer;
			if (tolower(answer) == 'y')
				Permission += 64;
			cout << "Show LogIn Register User  y/n : ";
			cin >> answer;
			if (tolower(answer) == 'y')
				Permission += 128;
				//user.setPermission(user.getPermission() + 64);
        }
		user.setPermission(Permission);
	}

	static void _ReadUserInfo(clsBankUser& User) {
		cout << "Enter First Name :";
		User.setFirstName(clsInputValidate::ReadString());
		cout << "Enter Last Name :";
		User.setLastName(clsInputValidate::ReadString());
		User.setEmail(clsInputValidate::GetEmailwhienTrue("Enter Email   :"));
		cout << "Enter Phone Number :";
		User.setPhone(clsInputValidate::ReadString());
		cout << "Enter Password Name :";
		//string password = clsInputValidate::ReadString();
		User.setPassword(clsInputValidate::ReadString());
		setPermission(User);
	}
	static void _PrintUser(clsBankUser User) {
		cout << "\ User Card : \n";
		cout << "____________________________________\n";
		cout << "FirstName   : " << User.getFirstName() << endl;
		cout << "LastName    : " << User.getLastName() << endl;
		cout << "FullName    : " << User.FullName() << endl;
		cout << "Email       : " << User.getEmail() << endl;
		cout << "Phone       : " << User.getPhone() << endl;
		cout << "UserName    : " << User.getUserName() << endl;
		cout << "Password    : " << User.getPassword() << endl;
		cout << "Permission  : " << User.getPermission() << endl;
		cout << "____________________________________\n";
	}
public:
	static void ShowAddNewUserScreen() {

		_DrawHederScrenns("Add New User Screen");
		string UserName;
		cout << "Pleas Enter Usere Name :";
		UserName = clsInputValidate::ReadString();
		while (clsBankUser::IsUserExist(UserName) )
		{
			cout << "The User Name is Found , Enter Anther User Name :";
			UserName = clsInputValidate::ReadString();
		}
		clsBankUser User = clsBankUser::getAddNewObject(UserName);
		_ReadUserInfo(User);
		clsBankUser::enSaveResault SaveUserResault;
		SaveUserResault = User.Save();
		switch (SaveUserResault)
		{
		case clsBankCleint::SaveResault:
			cout << "the User is Adding Succsessfully :-) \n";
			_PrintUser(User);
			break;
		case clsBankCleint::NoSaveResault:
			cout << "the Usre is Not Adding Succsessfully :-( \n";
			break;
		case clsBankCleint::ObjectExist:
			cout << "the User is Found yet  :-( \n";
			break;
		default:
			break;
		}

	}
};

