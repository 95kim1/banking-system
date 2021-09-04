/*
 * 파일이름: CommonDeclare.h
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 04] 파일버전 0.7 
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


enum 		// 메뉴 번호.
{
	CREATE=1,
	DEPOSITE,
	WITHDRAW,
	SHOWALL,
	END
};

enum	// 계좌 타입 
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
