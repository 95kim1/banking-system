/*
 * 파일이름: AccountHandler.h
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 04] 파일버전 0.7 
 */

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

/*
 * 클래스명: AccountHandler 
 * 유형: Control class 
 */

class AccountHandler
{
	Account** mAccArr;	// Account 저장소 포인터 
	int mAccNum;		// 저장된 Account 개수
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
