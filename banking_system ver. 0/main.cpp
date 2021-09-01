/*
 * BankingSystem ver. 0
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
 * 		C 스타일로 코딩해보기. 
 */

#include <iostream>
#include <cstring>

/*
	0. Account 자료형 
		- 계좌번호 -> int
		- 고객이름 -> char []
		- 잔액 -> int 
	1. 메뉴 디스플레이 함수
		- 계좌개설, 입금, 출금, 잔액조회(전체), 프로그램 종료 
	2. 계좌개설 함수
	3. 입금 함수
	4. 출금 함수 
	5. 전체고객 잔액조회 
*/

#define NAME_LEN 32
#define MAX_ACCOUNT 128

typedef struct
{
	int id;					// 계좌번호 
	int balance;			// 계좌잔액
	char name[NAME_LEN]; 	// 고객이름 
} Account;

/* Account 함수*/
void InitAccount(Account* const account, const int id, const int balance, const char* name);
void DepositeAccount(Account* const account, const int money);
void WithdrawAccount(Account* const account, const int money);
void ShowAccountInfo(Account* const account);

/* Main(BankingSystem) 함수 */ 
void ShowMenu();
void DisplayTitle(const char* title);
void ShowAllInfo();

int ChooseMenu();
int FindAccountIdx(int id);

void CreateAccount();
void DepositeMoney();
void WithdrawMoney();

enum 
{
	CREATE=1,
	DEPOSITE,
	WITHDRAW,
	SHOWALL,
	END
};

Account accArr[MAX_ACCOUNT];	// Account 저장하는 배열 
int accNum = 0;						// 배열에 저장된 Account 개수 

int main(void) {
	int menuNum;
	
	DisplayTitle("은행계좌 관리");
	
	while (1)
	{
		// 메뉴 화면 출력 
		ShowMenu();
		
		// 메뉴 번호 입력
		menuNum = ChooseMenu();
		 
		switch (menuNum)
		{
		case CREATE:	// 계좌개설 
			CreateAccount(); 
			break;
		case DEPOSITE:	// 입금 
			DepositeMoney();
			break;
		case WITHDRAW:	// 출금 
			WithdrawMoney();
			break;
		case SHOWALL:	// 전체 조회 
			ShowAllInfo();
			break;
		case END:		// 종료 
			return 0;
		default:		// 잘못된 메뉴 번호 
			std::cout << "illegal menu number" << std::endl;
		}
		
	}
			
	return 0;
}

/* Account */
// 계좌 초기화 
void InitAccount(Account* const account, const int id, const int balance, const char* name)
{
	account->id = id;
	account->balance = balance;
	strcpy(account->name, name);
}

// 입금하기 
void DepositeAccount(Account* const account, const int money)
{
	account->balance += money;
}

// 출금하기 
void WithdrawAccount(Account* const account, const int money)
{
	account->balance -= money;
}

// 잔액 조회
void ShowAccountInfo(Account* const account)
{
	std::cout << "계좌번호: " << account->id << std::endl; 
	std::cout << "이    름: " << account->name << std::endl;
	std::cout << "잔    액: " << account->balance << std::endl << std::endl;
}

/* Main 함수 */
// 메뉴화면 출력
void ShowMenu()
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
void DisplayTitle(const char* title)
{
	std::cout << std::endl; 
	std::cout << "--------------------------" << std::endl;
	std::cout << "     " << title << std::endl;
	std::cout << "--------------------------" << std::endl << std::endl;
}

// 모든 계좌 조회 
void ShowAllInfo()
{
	int i;
	
	DisplayTitle("전체 잔액조회 시작");
	
	for (i = 0; i < accNum; i++)
	{
		ShowAccountInfo(&accArr[i]);
	}
	
	DisplayTitle("전체 잔액조회 종료");
}

// 메뉴 선택하기 
int ChooseMenu()
{
	int menuNum;
	
	while(1)
	{
		std::cout << "# 선택: ";
		std::cin >> menuNum;
		fflush(stdin);
		
		if (1 <= menuNum && menuNum <= 5)
		{
			break;
		}
		
		std::cout << "@ 잘못된 번호 입니다." << std::endl; 
	}
	
	return menuNum;
}

// 해당 계좌가 저장된 배열 인덱스 찾기 
int FindAccountIdx(int id)
{
	int i;
	
	for (i = 0; i < accNum; i++)
	{
		if (id == accArr[i].id)
		{
			return i;
		}
	}
	
	return -1;
}

// 계좌개설 메인함수
void CreateAccount()
{
	int id;
	int balance;
	int index; 
	char name[NAME_LEN];
	
	DisplayTitle("계좌개설 시작");
	
	std::cout << "# 계좌번호: ";
	std::cin >> id;
	fflush(stdin);
	
	index = FindAccountIdx(id);
	
	if (index >= 0)
	{
		std::cout << std::endl << "@ 이미 개설한 계좌번호입니다." << std::endl;
		
		DisplayTitle("계좌개설 종료");
		
		return; 
	}
	
	std::cout << "# 이름: ";
	std::cin >> name;
	fflush(stdin);
	
	std::cout << "# 잔액: ";
	std::cin >> balance;
	fflush(stdin);
	
	InitAccount(&accArr[accNum], id, balance, name);
	accNum++;
	
	DisplayTitle("계좌개설 종료");
}

// 입금하기 메인함수 
void DepositeMoney()
{
	int id;
	int money;
	int index;
	
	DisplayTitle("입금하기 시작");
	
	std::cout << "# 계좌번호: ";
	std::cin >> id;
	fflush(stdin);
	
	index = FindAccountIdx(id);
	
	if (index == -1)
	{
		std::cout << std::endl << "@ 등록되지 않은 계좌번호입니다." << std::endl;
		
		DisplayTitle("입금하기 종료");
		
		return; 
	}
	
	std::cout << "# 입금할 금액: ";
	std::cin >> money;
	fflush(stdin);
	
	DepositeAccount(&accArr[index], money);
	
	std::cout << std::endl << "@ 입금 완료." << std::endl;
	
	DisplayTitle("입금하기 종료");
} 

// 출금하기 메인함수 
void WithdrawMoney()
{
	int id;
	int money;
	int index;
	
	DisplayTitle("출금하기 시작");
	
	std::cout << "# 계좌번호: ";
	std::cin >> id;
	fflush(stdin);
	
	index = FindAccountIdx(id);
	
	if (index == -1)
	{
		std::cout << std::endl << "@ 등록되지 않은 계좌번호입니다." << std::endl;
		
		DisplayTitle("출금하기 종료");
		
		return; 
	}
	
	std::cout << "# 출금할 금액: ";
	std::cin >> money;
	fflush(stdin);
	
	
	if (money > accArr[index].balance)
	{
		std::cout << std::endl << "@ 잔액 부족." << std::endl;
	}
	else
	{
		WithdrawAccount(&accArr[index], money);
		
		std::cout << std::endl << "@ 출금 완료." << std::endl;	
	}
	
	DisplayTitle("출금하기 종료");
}
