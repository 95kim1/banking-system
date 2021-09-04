/*
 * �����̸�: Account.cpp
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 04] ���Ϲ��� 0.8
 */

#include "CommonDeclare.h"
#include "Account.h"

/*
 * Ŭ������: Account
 * ����: Entity class
 */

// ������
Account::Account(const int id, const unsigned long long balance, const char* name)
	: mId(id)
	, mBalance(balance)
{
	mName = new char[strlen(name) + 1];
	strcpy(mName, name);
}

// ���� ������
Account::Account(const Account& account)
	: mId(account.mId)
	, mBalance(account.mBalance)
{
	mName = new char[strlen(account.mName)];
	strcpy(mName, account.mName);
}

// ���� ������
Account& Account::operator=(const Account& acc)
{
	mId = acc.mId;
	mBalance = acc.mBalance;
	
	delete [] mName;
	mName = new char[strlen(acc.mName) + 1];
	strcpy(mName, acc.mName);
	
	return *this;
}

// �� ������ 
bool Account::operator==(const Account& acc)
{
	if (acc.mId == mId)
	{
		return true;	
	}
	
	return false;
} 

// Getter �Լ�
int Account::GetId() const
{
	return mId;
}
unsigned long long Account::GetBalance() const
{
	return mBalance;
}
char* Account::GetName() const
{
	return mName;
}

// Setter �Լ�
void Account::SetId(const int id)
{
	mId = id;
}
void Account::SetBalance(const unsigned long long balance)
{
	mBalance = balance;
}
void Account::SetName(const char* name)
{
	strcpy(mName, name);
}

// �Ա��ϱ�
void Account::DepositeMoney(const unsigned long long money)
{
	mBalance += money;
}

// ����ϱ�
void Account::WithdrawMoney(const unsigned long long money)
{
	mBalance -= money;
}

// �ܾ���ȸ
void Account::ShowInfo()
{
	std::cout << " ���¹�ȣ: " << mId << std::endl; 
	std::cout << " ��    ��: " << mName << std::endl;
	std::cout << " ��    ��: " << mBalance << std::endl;	
}

// �Ҹ���
Account::~Account()
{
	delete mName;	
}
