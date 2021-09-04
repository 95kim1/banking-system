/*
 * �����̸�: AccountHandler.cpp
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 04] ���Ϲ��� 0.8
 */

#include "CommonDeclare.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

/*
 * Ŭ������: AccountHandler 
 * ����: Control class 
 */

// ������ 
AccountHandler::AccountHandler(const int capacity)
	: mAccArr(capacity)
{}

// �޴�ȭ�� ���
void AccountHandler::ShowMenu()
{ 
	std::cout << " ---------Menu--------" << std::endl;
	std::cout << "     1. ���°���" << std::endl;
	std::cout << "     2. ��    ��"	<< std::endl;
	std::cout << "     3. ��    ��" << std::endl;
	std::cout << "     4. ��ü �ܾ���ȸ" << std::endl;
	std::cout << "     5. ���α׷� ����" << std::endl;
	std::cout << " ---------------------" << std::endl;
}

// Ÿ��Ʋ ����Լ�
void AccountHandler::DisplayTitle(const char* title)
{
	std::cout << std::endl; 
	std::cout << "--------------------------" << std::endl;
	std::cout << "     " << title << std::endl;
	std::cout << "--------------------------" << std::endl << std::endl;
}

// ��� ���� ��ȸ
void AccountHandler::ShowAllInfo()
{
	int i;
	int len = mAccArr.GetSize();
	
	DisplayTitle("��ü �ܾ���ȸ ����");
	
	for (i = 0; i < len; i++)
	{
		mAccArr[i]->ShowInfo();
		std::cout << std::endl;
	}
	
	DisplayTitle("��ü �ܾ���ȸ ����");
}

// �޴� �����ϱ�
int AccountHandler::ChooseMenu()
{
	int menuNum;
	
	while(1)
	{
		INPUT_FUNC("# ����: ", menuNum); 
		
		if (1 <= menuNum && menuNum <= 5)
		{
			break;
		}
		
		std::cout << "@ �߸��� ��ȣ �Դϴ�." << std::endl; 
	}
	
	return menuNum;
}

// �ش� ���°� ����� �迭 �ε��� ã��
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

// ���� ���� ���� 
void AccountHandler::CreateNormalAccount()
{
	int id;
	unsigned long long balance;
	int rate;
	int index; 
	char name[NAME_LEN];
	
	INPUT_FUNC("# ���¹�ȣ: ", id);
	
	index = FindAccountIdx(id);
	
	if (index >= 0)
	{
		std::cout << std::endl << "@ �̹� ������ ���¹�ȣ�Դϴ�." << std::endl;
		
		DisplayTitle("���°��� ����");
		
		return; 
	}
	
	INPUT_FUNC("# ��  ��: ", name);	
	INPUT_FUNC("# ��  ��: ", balance);
	INPUT_FUNC("# ������(%): ", rate);
	
	mAccArr.PushBack(new NormalAccount(id, balance, name, rate));
}
// �ſ� ���� ���� 
void AccountHandler::CreateHighCreditAccount()
{
	int id;
	unsigned long long balance;
	int rate;
	int level;
	int index; 
	char name[NAME_LEN];
	
	INPUT_FUNC("# ���¹�ȣ: ", id);
	
	index = FindAccountIdx(id);
	
	if (index >= 0)
	{
		std::cout << std::endl << "@ �̹� ������ ���¹�ȣ�Դϴ�." << std::endl;
		
		DisplayTitle("���°��� ����");
		
		return; 
	}
	
	INPUT_FUNC("# ��  ��: ", name);	
	INPUT_FUNC("# ��  ��: ", balance);
	INPUT_FUNC("# ������(%): ", rate);
	INPUT_FUNC("# �ſ���(1toA 2toB 3toC): ", level);
	
	mAccArr.PushBack(new HighCreditAccount(id, balance, name, rate, level));
}

// ���°��� �����Լ� 
void AccountHandler::CreateAccount()
{	
	int type;

	DisplayTitle("���°��� ����");
	
	std::cout << "[������������]" << std::endl;
	std::cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << std::endl; 
	INPUT_FUNC("# ����: ", type);
	std::cout << std::endl;
	
	if (type == NORMAL)
	{
		std::cout << "[������� ����]" << std::endl; 
		CreateNormalAccount();
	}
	else
	{
		std::cout << "[�ſ�ŷڰ��� ����]" << std::endl;
		CreateHighCreditAccount();
	}
	
	DisplayTitle("���°��� ����");
}

// �Ա��ϱ� �����Լ�
void AccountHandler::DepositeMoney()
{
	int id;
	unsigned long long money;
	int index;
	
	DisplayTitle("�Ա��ϱ� ����");
	
	INPUT_FUNC("#���¹�ȣ: ", id);
	
	index = FindAccountIdx(id);
	
	if (index == -1)
	{
		std::cout << std::endl << "@ ��ϵ��� ���� ���¹�ȣ�Դϴ�." << std::endl;
		
		DisplayTitle("�Ա��ϱ� ����");
		
		return; 
	}
	
	INPUT_FUNC("# �Ա��� �ݾ�: ", money);
	
	mAccArr[index]->DepositeMoney(money);
	
	std::cout << std::endl << "@ �Ա� �Ϸ�." << std::endl;
	
	DisplayTitle("�Ա��ϱ� ����");
} 

// ����ϱ� �����Լ�
void AccountHandler::WithdrawMoney()
{
	int id;
	unsigned long long money;
	int index;
	
	DisplayTitle("����ϱ� ����");

	INPUT_FUNC("# ���¹�ȣ: ", id);	
	
	index = FindAccountIdx(id);
	
	if (index == -1)
	{
		std::cout << std::endl << "@ ��ϵ��� ���� ���¹�ȣ�Դϴ�." << std::endl;
		
		DisplayTitle("����ϱ� ����");
		
		return; 
	}
	
	INPUT_FUNC("# ����� �ݾ�: ", money);
		
	if (money > mAccArr[index]->GetBalance())
	{
		std::cout << std::endl << "@ �ܾ� ����." << std::endl;
	}
	else
	{
		mAccArr[index]->WithdrawMoney(money);
		
		std::cout << std::endl << "@ ��� �Ϸ�." << std::endl;	
	}
	
	DisplayTitle("����ϱ� ����");
}

