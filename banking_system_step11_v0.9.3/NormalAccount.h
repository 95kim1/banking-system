/*
 * 파일이름: NormalAccount.h
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 05] 파일버전 0.8 
 */

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

/*
 * 클래스명: NormalAccount
 * 유형: Entity class 
 * Base: Account
 */
 
class NormalAccount : public Account
{
private:
	int mInterestRate;
public:
	NormalAccount(const int id, const unsigned long long balance, const String& name, const int rate)
		: Account(id, balance, name)
		, mInterestRate(rate)
	{}
	
	virtual void DepositeMoney(unsigned long long money)
	{
		Account::DepositeMoney(money * (1 + mInterestRate / 100.0));
	}
	
	virtual void ShowInfo()
	{
		Account::ShowInfo();
		std::cout << " 이 자 율(%): " << mInterestRate << std::endl;
	}	
};

#endif
