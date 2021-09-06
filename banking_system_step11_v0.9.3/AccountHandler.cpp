/*
 * 파일이름: AccountHandler.cpp
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 06] 파일버전 0.92
 */

#include "CommonDeclare.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountException.h"

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
	bool errFlag;
	
	while(1)
	{
		menuNum = InputPureInt("# 선택: ", errFlag);
		
		try
		{
			if (menuNum < 1 || 5 < menuNum)
				throw -1;
			
			if (errFlag == true)
				throw NoPureNumberException();
		}
		catch (...)
		{
			std::cout << "@ 잘못된 번호 입니다." << std::endl << std::endl; 
			continue;
		}
		
		break;
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
	String name;
	bool errFlag;
	
	id = InputPureInt("# 계좌번호: ", errFlag);
		
	if (errFlag == true)			// 문자가 섞인 계좌번호 
		throw NoPureNumberException();
	
	if (FindAccountIdx(id) >= 0)	// 개설된 계좌번호 
		throw SameIdException();
	
	INPUT_FUNC("# 이  름: ", name);
			
	balance = InputPureULL("# 잔  액: ", errFlag);
	
	if (errFlag == true)			 // 금액에 문자 포함 
		throw NoPureNumberException();
	
	rate = InputPureInt("# 이자율(%): ", errFlag);
	
	if (rate == true)				// 이자율에 문자 포함 
		throw NoPureNumberException();
	
	mAccArr.PushBack(new NormalAccount(id, balance, name, rate));
}
// 신용 계좌 개설 
void AccountHandler::CreateHighCreditAccount()
{
	int id;
	unsigned long long balance;
	int rate;
	int level;
	String name;
	bool errFlag;
	
	id = InputPureInt("# 계좌번호: ", errFlag);
	
	if (errFlag == true)				// 문자가 섞인 계좌번호 
		throw NoPureNumberException();
	
	if (FindAccountIdx(id) >= 0)		// 개설된 계좌번호 
		throw SameIdException();
	
	INPUT_FUNC("# 이  름: ", name);
	
	balance = InputPureULL("# 잔  액: ", errFlag);
	
	if (errFlag == true)				// 금액에 문자 포함
		throw NoPureNumberException();
	
	rate = InputPureInt("# 이자율(%): ", errFlag);
	
	if (errFlag == true)				// 이자율에 문자 포함 
		throw NoPureNumberException();
	
	level = InputPureInt("# 신용등급(1toA 2toB 3toC): ", errFlag);
	
	if (errFlag == true)				// 신용등급 문자 포함 
		throw NoPureNumberException();
	
	if (level < 1 || 3 < level)					// 잘못된 level 번호 
		throw WrongCreditLevelException(level);
	
	mAccArr.PushBack(new HighCreditAccount(id, balance, name, rate, level));
}

// 계좌개설 메인함수 
void AccountHandler::CreateAccount()
{	
	int type;
	bool errFlag;

	DisplayTitle("계좌개설 시작");
	
	std::cout << "[계좌종류선택]" << std::endl;
	std::cout << "1.보통예금계좌 2.신용신뢰계좌" << std::endl; 
	
	try
	{
		type = InputPureInt("# 선택: ", errFlag);
		
		if (errFlag == true)
			throw NoPureNumberException();

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
	}
	catch (NoPureNumberException& expObj)
	{
		std::cout << "@ 잘못된 메뉴 번호입니다." << std::endl;
		DisplayTitle("계좌개설 종료");	
		return;
	}
	catch (AccountException& expObj)
	{
		std::cout << std::endl;
		expObj.ShowException();
		DisplayTitle("계좌개설 종료");
		return;
	}
	
	std::cout << std::endl << "@ 개설 완료." << std::endl;
	
	DisplayTitle("계좌개설 종료");
}

// 입금하기 메인함수
void AccountHandler::DepositeMoney()
{
	int index;
	int id; 
	unsigned long long money;
	bool errFlag;
	
	DisplayTitle("입금하기 시작");
	
	try
	{
		id = InputPureInt("#계좌번호: ", errFlag);
		
		if (errFlag == true)			// 계좌번호에 문자 포함 
			throw NoPureNumberException();
		
		index = FindAccountIdx(id);
		
		if (index == -1)					// 개설 안 된 계좌번호 
			throw ClosedAccountException();
		
		money = InputPureULL("# 입금할 금액: ", errFlag);
		
		if (errFlag == true)	// 계좌번호에 문자 포함 
			throw NoPureNumberException();
		
		if (money < 0)						// 음수 금액 
			throw MinusMoneyException();
	}
	catch (AccountException& expObj)
	{
		std::cout << std::endl;
		expObj.ShowException();
		DisplayTitle("입금하기 종료");
		return; 
	}
	
	mAccArr[index]->DepositeMoney(money);
	
	std::cout << std::endl << "@ 입금 완료." << std::endl;
	
	DisplayTitle("입금하기 종료");
} 

// 출금하기 메인함수
void AccountHandler::WithdrawMoney()
{
	int index;
	int id;
	unsigned long long money;
	bool errFlag;
	
	DisplayTitle("출금하기 시작");
	
	try
	{
		id = InputPureInt("#계좌번호: ", errFlag);
		
		if (errFlag == true)					// 계좌번호에 문자 포함 
			throw NoPureNumberException();
		
		index = FindAccountIdx(id);
		
		if (index == -1)						// 개설 안 된 계좌번호 
			throw ClosedAccountException();
		
		money = InputPureULL("# 출금할 금액: ", errFlag);
		
		if (errFlag == true)					// 계좌번호에 문자 포함 
			throw NoPureNumberException();
		
		if (money < 0)							// 음수 금액 
			throw MinusMoneyException();
		
		if (mAccArr[index]->GetBalance() < money)	// 잔액 부족 
			throw InsuffBalanceException(mAccArr[index]->GetBalance()); 
	}
	catch (AccountException& expObj)
	{
		std::cout << std::endl;
		expObj.ShowException();
		DisplayTitle("출금하기 종료");
		return; 
	}
	
	mAccArr[index]->WithdrawMoney(money);
	
	std::cout << std::endl << "@ 출금 완료." << std::endl;	
	
	DisplayTitle("출금하기 종료");
}

