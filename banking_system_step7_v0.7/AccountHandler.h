/*
 * �����̸�: AccountHandler.h
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 04] ���Ϲ��� 0.7 
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

/*
 * Ŭ������: AccountHandler 
 * ����: Control class 
 */

class AccountHandler
{
	Account** mAccArr;	// Account ����� ������ 
	int mAccNum;		// ����� Account ����
	int mCapacity;
public:
	AccountHandler(const int capacity=MAX_ACCOUNT);
	~AccountHandler();
	
	void ShowMenu();
	void DisplayTitle(const char* title);
	void ShowAllInfo();
	
	int ChooseMenu();
	int FindAccountIdx(int id);
	void ResizeArray(const int capa);
	
	void CreateNormalAccount();
	void CreateHighCreditAccount();
	
	void CreateAccount();
	void DepositeMoney();
	void WithdrawMoney();
};

#endif
