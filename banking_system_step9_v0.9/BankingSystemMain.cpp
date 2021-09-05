/*
 * BankingSystem version 0.9
 *
 * �����̸�: BankingSystemMain.cpp
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 04] ���Ϲ��� 0.7
 */

#include "CommonDeclare.h"
#include "AccountHandler.h"

int main(void) {
	int menuNum;
	
	AccountHandler handler;
	
	handler.DisplayTitle("������� ����");
	
	while (1)
	{
		// �޴� ȭ�� ���
		handler.ShowMenu();
		
		// �޴� ��ȣ �Է�
		menuNum = handler.ChooseMenu();
		 
		switch (menuNum)
		{
		case CREATE:	// ���°���
			handler.CreateAccount(); 
			break;
		case DEPOSITE:	// �Ա�
			handler.DepositeMoney();
			break;
		case WITHDRAW:	// ���
			handler.WithdrawMoney();
			break;
		case SHOWALL:	// ��ü ��ȸ
			handler.ShowAllInfo();
			break;
		case END:		// ����
			return 0;
		default:		// �߸��� �޴� ��ȣ
			std::cout << "illegal menu number" << std::endl;
		}	
	}
		
	return 0;
}

