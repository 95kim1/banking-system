/*
 * �����̸�: Account.cpp
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 05] ���Ϲ��� 0.9
 */

#include "CommonDeclare.h"
#include "Account.h"

/*
 * Ŭ������: Account
 * ����: Entity class
 */

// ������
Account::Account(const int id, const unsigned long long balance, const String& name)
	: mId(id)
	, mBalance(balance)
	, mName(name)
{}

// ���� ������
Account::Account(const Account& account)
	: mId(account.mId)
	, mBalance(account.mBalance)
	, mName(account.mName)
{}

// ���� ������
Account& Account::operator=(const Account& acc)
{
	mId = acc.mId;
	mBalance = acc.mBalance;
	mName = acc.mName;
	
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
String Account::GetName() const
{
	return mName;
}
String& Account::GetName()
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
void Account::SetName(const String& name)
{
	mName = name;
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

