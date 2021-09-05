/*
 * 파일이름: Account.h
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 05] 파일버전 0.9
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

/*
 * 클래스명: Account
 * 유형: Entity class
 */

class Account
{
	int mId;						// 계좌번호
	unsigned long long mBalance;	// 계좌잔액
	String mName;					// 고객이름
public:
	Account(const int id, const unsigned long long balance, const String& name);
	Account(const Account& accunt);
	
	Account& operator=(const Account& acc);
	bool operator==(const Account& acc);
	
	int GetId() const;
	unsigned long long GetBalance() const;
	String GetName() const;
	String& GetName();
	
	void SetId(const int id);
	void SetBalance(const unsigned long long balance);
	void SetName(const String& name);
	
	virtual void DepositeMoney(const unsigned long long money);
	void WithdrawMoney(const unsigned long long money);
	virtual void ShowInfo();
};

#endif
