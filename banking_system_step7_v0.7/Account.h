/*
 * 파일이름: Account.h
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 04] 파일버전 0.7 
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

/*
 * 클래스명: Account
 * 유형: Entity class
 */

class Account
{
	int mId;						// 계좌번호
	unsigned long long mBalance;	// 계좌잔액
	char* mName;					// 고객이름
public:
	Account(const int id, const unsigned long long balance, const char* name);
	Account(const Account& accunt);
	~Account();
	
	int GetId() const;
	unsigned long long GetBalance() const;
	char* GetName() const;
	
	void SetId(const int id);
	void SetBalance(const unsigned long long balance);
	void SetName(const char* name);
	
	virtual void DepositeMoney(const unsigned long long money);
	void WithdrawMoney(const unsigned long long money);
	virtual void ShowInfo();
};

#endif
