/*
 * �����̸�: AccountHandler.h
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 05] ���Ϲ��� 0.9
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BoundCheckDArray.h"

/*
 * Ŭ������: AccountHandler 
 * ����: Control class 
 */

class AccountHandler
{
	BoundCheckDArray<Account*> mAccArr;
public:
	AccountHandler(const int capacity=MAX_ACCOUNT);
	
	void ShowMenu();
	void DisplayTitle(const char* title);
	void ShowAllInfo();
	
	int ChooseMenu();
	int FindAccountIdx(int id);
	
	void CreateNormalAccount();
	void CreateHighCreditAccount();
	
	void CreateAccount();
	void DepositeMoney();
	void WithdrawMoney();
};

#endif
