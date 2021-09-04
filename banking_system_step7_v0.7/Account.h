/*
 * �����̸�: Account.h
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 04] ���Ϲ��� 0.7 
 */

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

/*
 * Ŭ������: Account
 * ����: Entity class
 */

class Account
{
	int mId;						// ���¹�ȣ
	unsigned long long mBalance;	// �����ܾ�
	char* mName;					// ���̸�
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
