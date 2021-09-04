/*
 * BankingSystem version 0.7
 *
 * �����̸�: BankingSystemMain.cpp
 * �� �� ��: sh.kim
 * �� ¥: 2021-09-04
 * �� ��: ������� ���� ���α׷�.
 * �� ��:
 *		1. ���°���
 *		2. �Ա�
 *		3. ���
 *		4. ��ü�� �ܾ���ȸ
 * �� ��: 
 * 		1. ������ ���¹�ȣ�� �ߺ����� �ʴ´�. -> �ߺ��˻�� ���� �� �ϰڴٴ� �ǹ�
 * 		2. �Ա� �� ��ݾ��� ������ 0���� ũ��. -> �Ա� �� ��ݾ��� �����˻縦 �� �ϰڴٴ� �ǹ�
 *		3. ���� ���������� ���¹�ȣ, ���̸�, ���� �ܾ����� 3������ ���� �� �����Ѵ�.
 *		4. �� �̻��� �� ���� ������ ���� �迭�� ����Ѵ�.
 *		5. ���¹�ȣ�� ������ ���´�.
 *		6. ���ǻ� ���ڸ� �ð��� �ƴ� �Ա��� �����ٷ� �������. (���°����� ���� �Ա� ����.) 
 *		7. ���� ���� �Ҽ����� �����Ѵ�. 
 *		8. �ſ뵵�� ���� ���� A: 7%, B: 4%, C: 2% �߰�. 
 * �� ��:
 *		- ���� ���� 
 */

/*
	0-1. Account �ڷ���
		- ���¹�ȣ -> int
		- ���̸� -> char*
		- �ܾ� -> int
	0-2. Account�� ������ �迭
		- ��ü ������ �迭
	0-3. NormaAccount : Account
		- ������ �߰�
	0-4. HighCreditAccount : Account
		- ������ �߰�
		- �ſ뵵�� ���� ������ �߰� ����
		- LevelA,B,C 
	1. �޴� ���÷��� �Լ�
		- ���°���, �Ա�, ���, �ܾ���ȸ(��ü), ���α׷� ���� 
	2. ���°��� �Լ�
	3. �Ա� �Լ�
	4. ��� �Լ� 
	5. ��ü�� �ܾ���ȸ
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

