/*
 * �����̸�: Account.h
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 05] ���Ϲ��� 0.9
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

/*
 * Ŭ������: Account
 * ����: Entity class
 */

class Account
{
	int mId;						// ���¹�ȣ
	unsigned long long mBalance;	// �����ܾ�
	String mName;					// ���̸�
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
