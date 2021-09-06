/*
 * 파일이름: AccountException.h 
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 06] 파일버전 0.1
 */

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include <iostream>
#include "String.h"
#include "CommonDeclare.h"

class AccountException
{
public:
	virtual void ShowException()=0;
};

class MinusMoneyException : public AccountException
{
public:
	void ShowException()
	{
		std::cout << "[예외발생: 음수 금액]" << std::endl; 
	}
};

class InsuffBalanceException : public AccountException
{
	int balance;
public:
	InsuffBalanceException(const int balance) : balance(balance) {}
	void ShowException()
	{
		std::cout << "[예외발생: 잔액 " << balance << ", 잔액부족]" << std::endl; 
	}
};

class SameIdException : public AccountException
{
public:
	void ShowException()
	{
		std::cout << "[예외발생: 이미 개설된 계좌번호]" << std::endl;
	}
};

class ClosedAccountException : public AccountException
{
public:
	void ShowException()
	{
		std::cout << "[예외발생: 등록되지 않은 계좌번호]" << std::endl;
	}
};

class WrongCreditLevelException : public AccountException
{
	int level;
public:
	WrongCreditLevelException(const int level) : level(level) {}
	void ShowException()
	{
		std::cout << "[예외발생: " << level << " 입력, 메뉴선택: level(1toA, 2toB, 3toC)]" << std::endl;
	}
};

class NoPureNumberException : public AccountException
{
public:
	void ShowException()
	{
		std::cout << "[예외발생: 문자 포함]" << std::endl;
	}
};

// 숫자가 포함된 문자열만 true 반환 
bool IsPureNumber(String& str)
{
	int i;
	int size = str.GetSize();
	
	for (i = 0; i < size; i++)
	{
		char ch = str[i];
		
		if (ch < '0' || '9' < ch)
		{
			return false;
		}
	}
	
	return true;
}

// String을 int로 변경  
int ChangeStrToInt(String &s)
{
	int i;
	int size = s.GetSize();
	int n = 0;
	int chNum;
	
	for (i = 0; i < size; i++)
	{
		n *= 10;
		chNum = s[i] - '0';
		n += chNum;
	}
	
	return n;
}

// String을 long long으로 변경 
unsigned long long ChangeStrToULL(String &s)
{
	int i;
	int size = s.GetSize();
	unsigned long long n = 0;
	int chNum;
	
	for (i = 0; i < size; i++)
	{
		n *= 10;
		chNum = s[i] - '0';
		n += chNum;
	}
	
	return n;
}

// int 입력받기
// 순수 숫자만 입력 받으면 flag <- false, 아니면 flag <- true 
int InputPureInt(const char* msg, bool& outErrFlag)
{
	String s;
		
	INPUT_FUNC(msg, s);
	
	outErrFlag = !IsPureNumber(s);
	
	if (outErrFlag == true)
		return -1;
	
	return ChangeStrToInt(s);
}

// unsigned long long 입력받기
// 순수 숫자만 입력 받으면 flag <- false, 아니면 flag <- true
unsigned long long InputPureULL(const char* msg, bool& outErrFlag)
{
	String s;
		
	INPUT_FUNC(msg, s);
	
	outErrFlag = !IsPureNumber(s);
	
	if (outErrFlag == true)
		return -1;
	
	return ChangeStrToULL(s);
}

#endif
