#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsListTransferTransactionScreen:protected clsScreen
{
	static void _PrintTransferTransaction(clsBankCleint::stTransferCleint tarnsaction) {
		cout << "|" << tarnsaction.DateTime
			<< "\t|\t" << tarnsaction.AccountNumberFrom
			<< "\t|\t" << tarnsaction.AccountNumberTo
			<< "\t|\t" << tarnsaction.BalanceFrom
			<< "\t|\t" << tarnsaction.BanlaceTo
			<< "\t|\t" << tarnsaction.Amount
			<< "\t|\t" << tarnsaction.UserName << endl;
	}
public:
	static void ShowListTransferTranactionScreen() {
		vector<clsBankCleint::stTransferCleint>ListTransfer = clsBankCleint::GetListTransferTranaction();
		string title = "List Transfer Transation Screen";
		string subtitle = "Tarnsfer Transaction (" + to_string(ListTransfer.size()) + ") s";
		_DrawHederScrenns(title,subtitle);
		cout << "| Date/Time | AccountNumer From |AccountNumber To|Balance From|Balance To|Amount | UserName\n";
		cout << "\n----------------------------------------------------------------------------------\n\n";
		if (ListTransfer.size() == 0)
			cout << "\n\n\t\t\t\t\t No Transaction Avalebil In Systeam \n\n\n";
		else
		{
			for (clsBankCleint::stTransferCleint Transaction: ListTransfer)
			{
				_PrintTransferTransaction(Transaction);
			}
		}
		cout << "\n--------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------\n";



	}
};

