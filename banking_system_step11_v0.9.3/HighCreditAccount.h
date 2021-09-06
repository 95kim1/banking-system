/*
 * 파일이름: HighCreditAccount.h
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 05] 파일버전 0.8 
 */

#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

/*
 * 클래스명: HighCreditAccount
 * 유형: Entity class 
 * Base: NormalAccount --> Account
 */
 
class HighCreditAccount : public NormalAccount
{
private:
	int mCreditLevel;	// 신용도 
	static int additionalRates[4];	// 신용등급별 이자율 (index1 : A등급, 2 : B, 3 : C) 
public:
	HighCreditAccount(const int id, const unsigned long long balance, const String& name, const int rate, const int level)
		: NormalAccount(id, balance, name, rate)
		, mCreditLevel(level)
	{}
	
	virtual void DepositeMoney(unsigned long long money)
	{
		NormalAccount::DepositeMoney(money);
		Account::DepositeMoney(money * (additionalRates[mCreditLevel] / 100.0));
	}
	
	virtual void ShowInfo()
	{
		NormalAccount::ShowInfo();
		std::cout << " 신용등급: " << (char)(mCreditLevel+64) << std::endl;
	}	
};

int HighCreditAccount::additionalRates[4] = {0,7,4,2};	// initialize static variable

#endif
