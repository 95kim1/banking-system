
/*
 * BankingSystem version 0.5
 *
 * 파일이름: main.cpp
 * 작 성 자: sh.kim
 * 날 짜: 2021-09-01
 * 내 용: 은행계좌 관리 프로그램.
 * 기 능:
 *		1. 계좌개설
 *		2. 입금
 *		3. 출금
 *		4. 전체고객 잔액조회
 * 전 제: 
 * 		1. 통장의 계좌번호는 중복되지 않는다. -> 중복검사는 아직 안 하겠다는 의미
 * 		2. 입금 및 출금액은 무조건 0보다 크다. -> 입금 및 출금액의 오류검사를 안 하겠다는 의미
 *		3. 고객의 계좌정보는 계좌번호, 고객이름, 고객의 잔액으로 3가지만 저장 및 관리한다.
 *		4. 둘 이상의 고객 정보 저장을 위해 배열을 사용한다.
 *		5. 계좌번호는 정수의 형태다.
 * 목 적:
 * 		- Control Class (AccountHandler)
 */

#include <iostream>
#include <cstring>

/*
	0-1. Account 자료형
		- 계좌번호 -> int
		- 고객이름 -> char*
		- 잔액 -> int
	0-2. Account들 저장할 배열
		- 객체 포인터 배열 
	1. 메뉴 디스플레이 함수
		- 계좌개설, 입금, 출금, 잔액조회(전체), 프로그램 종료 
	2. 계좌개설 함수
	3. 입금 함수
	4. 출금 함수 
	5. 전체고객 잔액조회
*/

#define NAME_LEN 32
#define MAX_ACCOUNT 128
#define INPUT_FUNC(STR, X) do\
	{\
		std::cout << (STR);\
		std::cin >> (X);\
		fflush(stdin);\
	} while(0);

namespace MENU_NUM
{
	enum 		// 메뉴 번호.
	{
		CREATE=1,
		DEPOSITE,
		WITHDRAW,
		SHOWALL,
		END
	};
}

/*
 *	클래스명: Account
 *  유형: Entity class
 */

class Account
{
	int mId;						// 계좌번호
	unsigned long long mBalance;	// 계좌잔액
	char* mName;					// 고객이름
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
	
	void DepositeMoney(const unsigned long long money);
	void WithdrawMoney(const unsigned long long money);
	void ShowInfo();
};

/* Account 멤버함수 정의*/
// 생성자
Account::Account(const int id, const unsigned long long balance, const char* name)
	: mId(id)
	, mBalance(balance)
{
	mName = new char[NAME_LEN];
	strcpy(mName, name);
}

// 복사 생성자
Account::Account(const Account& account)
	: mId(account.GetId())
	, mBalance(account.GetBalance())
{
	mName = new char[NAME_LEN];
	strcpy(mName, account.GetName());
}

// 소멸자
Account::~Account()
{
	delete mName;	
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
char* Account::GetName() const
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
void Account::SetName(const char* name)
{
	strcpy(mName, name);
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
	std::cout << " 잔    액: " << mBalance << std::endl << std::endl;	
}

/*
 * 클래스명: AccountHandler 
 * 유형: Control class 
 */

class AccountHandler
{
	Account** mAccArr;	// Account 저장소 포인터 
	int mAccNum;		// 저장된 Account 개수
	int mCapacity;
public:
	AccountHandler(const int capacity=MAX_ACCOUNT)
		: mAccNum(0)
		, mCapacity(capacity)
	{
		mAccArr = new Account*[capacity];
	}
	~AccountHandler()
	{
		int i;
		
		for (i = 0; i < mAccNum; i++)
		{
			delete mAccArr[i];
		}
		
		delete []mAccArr;
	}
	
	void ShowMenu();
	void DisplayTitle(const char* title);
	void ShowAllInfo();
	
	int ChooseMenu();
	int FindAccountIdx(int id);
	
	void ResizeArray(const int capa);
	void CreateAccount();
	void DepositeMoney();
	void WithdrawMoney();
};

/* AccountHandler 함수 정의 */

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
	
	DisplayTitle("전체 잔액조회 시작");
	
	for (i = 0; i < mAccNum; i++)
	{
		mAccArr[i]->ShowInfo();
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
//		std::cout << "# 선택: ";
//		std::cin >> menuNum;
//		fflush(stdin);
		
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
	
	for (i = 0; i < mAccNum; i++)
	{
		if (id == mAccArr[i]->GetId())
		{
			return i;
		}
	}
	
	return -1;
}

// Account 저장소 공간 확장 
void AccountHandler::ResizeArray(const int capa)
{	
	int i;

	if (capa < mAccNum)
	{
		return;
	}

	mCapacity = capa;

	Account ** tmp = new Account*[mCapacity];
	
	for (i = 0; i < mAccNum; i++)
	{
		tmp[i] = mAccArr[i];
	}

	delete []mAccArr;
	
	mAccArr = tmp;
}

// 계좌개설 메인함수
void AccountHandler::CreateAccount()
{
	int id;
	unsigned long long balance;
	int index; 
	char name[NAME_LEN];
	
	DisplayTitle("계좌개설 시작");
	
	if (mAccNum == mCapacity)
	{
		ResizeArray(mCapacity + mCapacity);
	}
	
	INPUT_FUNC("# 계좌번호: ", id);
//	std::cout << "# 계좌번호: ";
//	std::cin >> id;
//	fflush(stdin);
	
	index = FindAccountIdx(id);
	
	if (index >= 0)
	{
		std::cout << std::endl << "@ 이미 개설한 계좌번호입니다." << std::endl;
		
		DisplayTitle("계좌개설 종료");
		
		return; 
	}
	
	INPUT_FUNC("# 이름: ", name);
//	std::cout << "# 이름: ";
//	std::cin >> name;
//	fflush(stdin);
	
	INPUT_FUNC("# 잔액: ", balance);
//	std::cout << "# 잔액: ";
//	std::cin >> balance;
//	fflush(stdin);
	
	mAccArr[mAccNum] = new Account(id, balance, name);
	mAccNum++;
	
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
//	std::cout << "# 계좌번호: ";
//	std::cin >> id;
//	fflush(stdin);
	
	index = FindAccountIdx(id);
	
	if (index == -1)
	{
		std::cout << std::endl << "@ 등록되지 않은 계좌번호입니다." << std::endl;
		
		DisplayTitle("입금하기 종료");
		
		return; 
	}
	
	INPUT_FUNC("# 입금할 금액: ", money);
//	std::cout << "# 입금할 금액: ";
//	std::cin >> money;
//	fflush(stdin);
	
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
//	std::cout << "# 계좌번호: ";
//	std::cin >> id;
//	fflush(stdin);
	
	index = FindAccountIdx(id);
	
	if (index == -1)
	{
		std::cout << std::endl << "@ 등록되지 않은 계좌번호입니다." << std::endl;
		
		DisplayTitle("출금하기 종료");
		
		return; 
	}
	
	INPUT_FUNC("# 출금할 금액: ", money);
//	std::cout << "# 출금할 금액: ";
//	std::cin >> money;
//	fflush(stdin);
	
	
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


int main(void) {
	int menuNum;
	
	AccountHandler handler;
	
	handler.DisplayTitle("은행계좌 관리");
	
	while (1)
	{
		// 메뉴 화면 출력
		handler.ShowMenu();
		
		// 메뉴 번호 입력
		menuNum = handler.ChooseMenu();
		 
		switch (menuNum)
		{
		case MENU_NUM::CREATE:	// 계좌개설
			handler.CreateAccount(); 
			break;
		case MENU_NUM::DEPOSITE:	// 입금
			handler.DepositeMoney();
			break;
		case MENU_NUM::WITHDRAW:	// 출금
			handler.WithdrawMoney();
			break;
		case MENU_NUM::SHOWALL:	// 전체 조회
			handler.ShowAllInfo();
			break;
		case MENU_NUM::END:		// 종료
			return 0;
		default:		// 잘못된 메뉴 번호
			std::cout << "illegal menu number" << std::endl;
		}	
	}
		
	return 0;
}
