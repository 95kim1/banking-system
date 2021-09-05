/*
 * 파일이름: AccountHandler.cpp
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 04] 파일버전 0.8
 */

#include "CommonDeclare.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

/*
 * 클래스명: AccountHandler 
 * 유형: Control class 
 */

// 생성자 
AccountHandler::AccountHandler(const int capacity)
	: mAccArr(capacity)
{}

// 메뉴화면 출력
void AccountHandler::ShowMenu()
{ 
	std::cout << " ---------Menu--------" << std::endl;
	std::cout << "     1. 계좌개설" << std::endl;
	std::cout << "     2. 입    금"	<< std::endl;
	std::cout << "     3. 출    금" << std::endl;
	std::cout << "     4. 전체 잔액조회" << std::endl;
	std::cout << "     5. 프로그램 종료" << std::endl;
	std::cout << " ---------------------" << std::endl;
}

// 타이틀 출력함수
void AccountHandler::DisplayTitle(const char* title)
{
	std::cout << std::endl; 
	std::cout << "--------------------------" << std::endl;
	std::cout << "     " << title << std::endl;
	std::cout << "--------------------------" << std::endl << std::endl;
}

// 모든 계좌 조회
void AccountHandler::ShowAllInfo()
{
	int i;
	int len = mAccArr.GetSize();
	
	DisplayTitle("전체 잔액조회 시작");
	
	for (i = 0; i < len; i++)
	{
		mAccArr[i]->ShowInfo();
		std::cout << std::endl;
	}
	
	DisplayTitle("전체 잔액조회 종료");
}

// 메뉴 선택하기
int AccountHandler::ChooseMenu()
{
	int menuNum;
	
	while(1)
	{
		INPUT_FUNC("# 선택: ", menuNum); 
		
		if (1 <= menuNum && menuNum <= 5)
		{
			break;
		}
		
		std::cout << "@ 잘못된 번호 입니다." << std::endl; 
	}
	
	return menuNum;
}

// 해당 계좌가 저장된 배열 인덱스 찾기
int AccountHandler::FindAccountIdx(int id)
{
	int i;
	int len = mAccArr.GetSize();
	
	for (i = 0; i < len; i++)
	{
		if (id == mAccArr[i]->GetId())
		{
			return i;
		}
	}
	
	return -1;
}

// 보통 계좌 개설 
void AccountHandler::CreateNormalAccount()
{
	int id;
	unsigned long long balance;
	int rate;
	int index; 
	char name[NAME_LEN];
	
	INPUT_FUNC("# 계좌번호: ", id);
	
	index = FindAccountIdx(id);
	
	if (index >= 0)
	{
		std::cout << std::endl << "@ 이미 개설한 계좌번호입니다." << std::endl;
		
		DisplayTitle("계좌개설 종료");
		
		return; 
	}
	
	INPUT_FUNC("# 이  름: ", name);	
	INPUT_FUNC("# 잔  액: ", balance);
	INPUT_FUNC("# 이자율(%): ", rate);
	
	mAccArr.PushBack(new NormalAccount(id, balance, name, rate));
}
// 신용 계좌 개설 
void AccountHandler::CreateHighCreditAccount()
{
	int id;
	unsigned long long balance;
	int rate;
	int level;
	int index; 
	char name[NAME_LEN];
	
	INPUT_FUNC("# 계좌번호: ", id);
	
	index = FindAccountIdx(id);
	
	if (index >= 0)
	{
		std::cout << std::endl << "@ 이미 개설한 계좌번호입니다." << std::endl;
		
		DisplayTitle("계좌개설 종료");
		
		return; 
	}
	
	INPUT_FUNC("# 이  름: ", name);	
	INPUT_FUNC("# 잔  액: ", balance);
	INPUT_FUNC("# 이자율(%): ", rate);
	INPUT_FUNC("# 신용등급(1toA 2toB 3toC): ", level);
	
	mAccArr.PushBack(new HighCreditAccount(id, balance, name, rate, level));
}

// 계좌개설 메인함수 
void AccountHandler::CreateAccount()
{	
	int type;

	DisplayTitle("계좌개설 시작");
	
	std::cout << "[계좌종류선택]" << std::endl;
	std::cout << "1.보통예금계좌 2.신용신뢰계좌" << std::endl; 
	INPUT_FUNC("# 선택: ", type);
	std::cout << std::endl;
	
	if (type == NORMAL)
	{
		std::cout << "[보통계좌 개설]" << std::endl; 
		CreateNormalAccount();
	}
	else
	{
		std::cout << "[신용신뢰계좌 개설]" << std::endl;
		CreateHighCreditAccount();
	}
	
	DisplayTitle("계좌개설 종료");
}

// 입금하기 메인함수
void AccountHandler::DepositeMoney()
{
	int id;
	unsigned long long money;
	int index;
	
	DisplayTitle("입금하기 시작");
	
	INPUT_FUNC("#계좌번호: ", id);
	
	index = FindAccountIdx(id);
	
	if (index == -1)
	{
		std::cout << std::endl << "@ 등록되지 않은 계좌번호입니다." << std::endl;
		
		DisplayTitle("입금하기 종료");
		
		return; 
	}
	
	INPUT_FUNC("# 입금할 금액: ", money);
	
	mAccArr[index]->DepositeMoney(money);
	
	std::cout << std::endl << "@ 입금 완료." << std::endl;
	
	DisplayTitle("입금하기 종료");
} 

// 출금하기 메인함수
void AccountHandler::WithdrawMoney()
{
	int id;
	unsigned long long money;
	int index;
	
	DisplayTitle("출금하기 시작");

	INPUT_FUNC("# 계좌번호: ", id);	
	
	index = FindAccountIdx(id);
	
	if (index == -1)
	{
		std::cout << std::endl << "@ 등록되지 않은 계좌번호입니다." << std::endl;
		
		DisplayTitle("출금하기 종료");
		
		return; 
	}
	
	INPUT_FUNC("# 출금할 금액: ", money);
		
	if (money > mAccArr[index]->GetBalance())
	{
		std::cout << std::endl << "@ 잔액 부족." << std::endl;
	}
	else
	{
		mAccArr[index]->WithdrawMoney(money);
		
		std::cout << std::endl << "@ 출금 완료." << std::endl;	
	}
	
	DisplayTitle("출금하기 종료");
}

