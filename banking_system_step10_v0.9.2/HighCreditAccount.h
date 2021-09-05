/*
 * �����̸�: HighCreditAccount.h
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 05] ���Ϲ��� 0.8 
 */

#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

/*
 * Ŭ������: HighCreditAccount
 * ����: Entity class 
 * Base: NormalAccount --> Account
 */
 
class HighCreditAccount : public NormalAccount
{
private:
	int mCreditLevel;	// �ſ뵵 
	static int additionalRates[4];	// �ſ��޺� ������ (index1 : A���, 2 : B, 3 : C) 
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
		std::cout << " �ſ���: " << (char)(mCreditLevel+64) << std::endl;
	}	
};

int HighCreditAccount::additionalRates[4] = {0,7,4,2};	// initialize static variable

#endif
