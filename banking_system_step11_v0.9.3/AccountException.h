/*
 * �����̸�: AccountException.h 
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 06] ���Ϲ��� 0.1
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
		std::cout << "[���ܹ߻�: ���� �ݾ�]" << std::endl; 
	}
};

class InsuffBalanceException : public AccountException
{
	int balance;
public:
	InsuffBalanceException(const int balance) : balance(balance) {}
	void ShowException()
	{
		std::cout << "[���ܹ߻�: �ܾ� " << balance << ", �ܾ׺���]" << std::endl; 
	}
};

class SameIdException : public AccountException
{
public:
	void ShowException()
	{
		std::cout << "[���ܹ߻�: �̹� ������ ���¹�ȣ]" << std::endl;
	}
};

class ClosedAccountException : public AccountException
{
public:
	void ShowException()
	{
		std::cout << "[���ܹ߻�: ��ϵ��� ���� ���¹�ȣ]" << std::endl;
	}
};

class WrongCreditLevelException : public AccountException
{
	int level;
public:
	WrongCreditLevelException(const int level) : level(level) {}
	void ShowException()
	{
		std::cout << "[���ܹ߻�: " << level << " �Է�, �޴�����: level(1toA, 2toB, 3toC)]" << std::endl;
	}
};

class NoPureNumberException : public AccountException
{
public:
	void ShowException()
	{
		std::cout << "[���ܹ߻�: ���� ����]" << std::endl;
	}
};

// ���ڰ� ���Ե� ���ڿ��� true ��ȯ 
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

// String�� int�� ����  
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

// String�� long long���� ���� 
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

// int �Է¹ޱ�
// ���� ���ڸ� �Է� ������ flag <- false, �ƴϸ� flag <- true 
int InputPureInt(const char* msg, bool& outErrFlag)
{
	String s;
		
	INPUT_FUNC(msg, s);
	
	outErrFlag = !IsPureNumber(s);
	
	if (outErrFlag == true)
		return -1;
	
	return ChangeStrToInt(s);
}

// unsigned long long �Է¹ޱ�
// ���� ���ڸ� �Է� ������ flag <- false, �ƴϸ� flag <- true
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
