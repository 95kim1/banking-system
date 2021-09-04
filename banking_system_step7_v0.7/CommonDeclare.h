/*
 * �����̸�: CommonDeclare.h
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 04] ���Ϲ��� 0.7 
 */

#ifndef __COMMON_DECLARE_H__
#define __COMMON_DECLARE_H__

#include <iostream>
#include <cstring>

#define NAME_LEN 32
#define MAX_ACCOUNT 128
#define INPUT_FUNC(STR, X) do\
	{\
		std::cout << (STR);\
		std::cin >> (X);\
		fflush(stdin);\
	} while(0);


enum 		// �޴� ��ȣ.
{
	CREATE=1,
	DEPOSITE,
	WITHDRAW,
	SHOWALL,
	END
};

enum	// ���� Ÿ�� 
{
	NORMAL=1,
	HIGH_CREDIT
};


enum	// high credit account credit-level
{
	LEVEL_A=1,
	LEVEL_B,
	LEVEL_C
};

#endif
