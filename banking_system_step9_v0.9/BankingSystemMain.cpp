/*
 * BankingSystem version 0.9
 *
 * 파일이름: BankingSystemMain.cpp
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 04] 파일버전 0.7
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

