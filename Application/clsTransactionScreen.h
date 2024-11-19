#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include<iomanip>
#include"clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTrnasferScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;

class clsTransactionScreen : protected clsScreen
{
private :
    enum enTransactionMenue{
        DepositScreen=1,WithdrawScreen=2,
        TotalBalances=3,TransferScreen=4,TransferLogScreen=5,MainMenue=6};
    static short _ReadTransactionOption()
    {
        short number = 0;
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        number = clsInputValidate::ReadNumberBetween<short>(1,6);
        return number;

    }
    static void _ShowDepsoitScreen()
    {
       // cout << "\nDeposit Screen will be here ...";
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithdrawScreen()
    {
        
        //cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::ShowWithdrawScreen();

    }
    static void _ShowTotalBalancesScreen()
    {
       // cout << "\nTotal Balances will be here ...";
        clsTotalBalancesScreen::ShowTotalBlanacesScreen();
    }
    static void _ShowTransferScreen()
    {
        clsTrnasferScreen::ShowTransferScreen();
    }
    static void _ShowTrnsferLogScreen() 
    {
        clsTransferLogScreen::ShowTransferLogScreen();
    }
    static void _GetBackToTransactionScreen()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n";
        system("pause>0");
        ShowTransactionScreen();
    }
    static void _PerfromTransactionOption(enTransactionMenue Option)
    {
        switch (Option)
        {
        case enTransactionMenue::DepositScreen:
        {
            system("cls");
            _ShowDepsoitScreen();
            _GetBackToTransactionScreen();
            break;
        }
        case enTransactionMenue::WithdrawScreen:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GetBackToTransactionScreen();
            break;
        }
        case enTransactionMenue::TotalBalances:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GetBackToTransactionScreen();
            break;
        }
        case enTransactionMenue::TransferScreen:
            system("cls");
            _ShowTransferScreen();
            _GetBackToTransactionScreen();
            break; 
        case enTransactionMenue::TransferLogScreen:
            system("cls");
            _ShowTrnsferLogScreen();
            break;
        case enTransactionMenue::MainMenue:
        {

        }
        }
    }
public:
	static void ShowTransactionScreen()
	{

        if (!CheckAccessRights(clsUser::enPermissions::pTransaction))
        {
            return;
        }
		system("cls");
		_DrawScreenHeader("\t  Transaction Screen ");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromTransactionOption((enTransactionMenue)_ReadTransactionOption());
	}
};

