/*
 * �����̸�: NormalAccount.h
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 05] ���Ϲ��� 0.8 
 */

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

/*
 * Ŭ������: NormalAccount
 * ����: Entity class 
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
		std::cout << " �� �� ��(%): " << mInterestRate << std::endl;
	}	
};

#endif
