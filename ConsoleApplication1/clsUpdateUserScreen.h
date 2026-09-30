#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankUser.h"
class clsUpdateUserScreen:protected clsScreen
{
private:
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

	static void	setPermission(clsBankUser& user) {
		char answer;
		int Permission = 0;
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
		User.setPassword(clsInputValidate::ReadString());
		setPermission(User);
	}
public:
	static void ShowUpdateUserScreen() {
		_DrawHederScrenns("Update User Screen");
		string UserName = "";
		cout << "Pleas Enter User Name To Update : ";
		UserName = clsInputValidate::ReadString();
		while (!clsBankUser::IsUserExist(UserName))
		{
			cout << "The Cleint is Not Found , Enter Anther Account Number : ";
			UserName = clsInputValidate::ReadString();
		}
		clsBankUser User = clsBankUser::Find(UserName);
		_PrintUser(User);

		if (User.getUserName() == "Admin")
			cout << "Erro.., you can not Update this User \n";
		else
		{
			cout << "\t Update User Info \n";
			cout << "------------------------------------\n";
			_ReadUserInfo(User);
			clsBankUser::enSaveResault SaveCleint;
			SaveCleint = User.Save();
			switch (SaveCleint)
			{
			case clsBankCleint::SaveResault:
				cout << "the Cleint is Update Succsessfully :-) \n";
				_PrintUser(User);
				break;
			case clsBankCleint::NoSaveResault:
				cout << "the Cleint is Not Update Succsessfully :-( \n";
				break;
			default:
				break;
			}
		}
	}

};

