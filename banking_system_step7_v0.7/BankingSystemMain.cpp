/*
 * BankingSystem version 0.7
 *
 * 파일이름: BankingSystemMain.cpp
 * 작 성 자: sh.kim
 * 날 짜: 2021-09-04
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
 *		6. 편의상 이자를 시간이 아닌 입금할 때마다로 계산하자. (계좌개설에 의한 입금 제외.) 
 *		7. 이율 계산시 소수점은 무시한다. 
 *		8. 신용도에 따라 이율 A: 7%, B: 4%, C: 2% 추가. 
 * 목 적:
 *		- 파일 분할 
 */

/*
	0-1. Account 자료형
		- 계좌번호 -> int
		- 고객이름 -> char*
		- 잔액 -> int
	0-2. Account들 저장할 배열
		- 객체 포인터 배열
	0-3. NormaAccount : Account
		- 이자율 추가
	0-4. HighCreditAccount : Account
		- 이자율 추가
		- 신용도에 따라 이자율 추가 제공
		- LevelA,B,C 
	1. 메뉴 디스플레이 함수
		- 계좌개설, 입금, 출금, 잔액조회(전체), 프로그램 종료 
	2. 계좌개설 함수
	3. 입금 함수
	4. 출금 함수 
	5. 전체고객 잔액조회
*/

#include "CommonDeclare.h"
#include "AccountHandler.h"

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
		case CREATE:	// 계좌개설
			handler.CreateAccount(); 
			break;
		case DEPOSITE:	// 입금
			handler.DepositeMoney();
			break;
		case WITHDRAW:	// 출금
			handler.WithdrawMoney();
			break;
		case SHOWALL:	// 전체 조회
			handler.ShowAllInfo();
			break;
		case END:		// 종료
			return 0;
		default:		// 잘못된 메뉴 번호
			std::cout << "illegal menu number" << std::endl;
		}	
	}
		
	return 0;
}

