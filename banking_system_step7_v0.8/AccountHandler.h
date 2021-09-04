/*
 * 파일이름: AccountHandler.h
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 04] 파일버전 0.8
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountDArray.h"

/*
 * 클래스명: AccountHandler 
 * 유형: Control class 
 */

class AccountHandler
{
	BoundCheckPtrDArray mAccArr;
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
