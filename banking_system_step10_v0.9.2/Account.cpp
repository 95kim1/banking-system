/*
 * 파일이름: Account.cpp
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 05] 파일버전 0.9
 */

#include "CommonDeclare.h"
#include "Account.h"

/*
 * 클래스명: Account
 * 유형: Entity class
 */

// 생성자
Account::Account(const int id, const unsigned long long balance, const String& name)
	: mId(id)
	, mBalance(balance)
	, mName(name)
{}

// 복사 생성자
Account::Account(const Account& account)
	: mId(account.mId)
	, mBalance(account.mBalance)
	, mName(account.mName)
{}

// 대입 연산자
Account& Account::operator=(const Account& acc)
{
	mId = acc.mId;
	mBalance = acc.mBalance;
	mName = acc.mName;
	
	return *this;
}

// 비교 연산자 
bool Account::operator==(const Account& acc)
{
	if (acc.mId == mId)
	{
		return true;	
	}
	
	return false;
} 

// Getter 함수
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

// Setter 함수
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

// 입급하기
void Account::DepositeMoney(const unsigned long long money)
{
	mBalance += money;
}

// 출금하기
void Account::WithdrawMoney(const unsigned long long money)
{
	mBalance -= money;
}

// 잔액조회
void Account::ShowInfo()
{
	std::cout << " 계좌번호: " << mId << std::endl; 
	std::cout << " 이    름: " << mName << std::endl;
	std::cout << " 잔    액: " << mBalance << std::endl;	
}

