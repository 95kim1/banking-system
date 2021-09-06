/*
 * �����̸�: AccountHandler.cpp
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 06] ���Ϲ��� 0.92
 */

#include "CommonDeclare.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountException.h"

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
	bool errFlag;
	
	while(1)
	{
		menuNum = InputPureInt("# ����: ", errFlag);
		
		try
		{
			if (menuNum < 1 || 5 < menuNum)
				throw -1;
			
			if (errFlag == true)
				throw NoPureNumberException();
		}
		catch (...)
		{
			std::cout << "@ �߸��� ��ȣ �Դϴ�." << std::endl << std::endl; 
			continue;
		}
		
		break;
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
	String name;
	bool errFlag;
	
	id = InputPureInt("# ���¹�ȣ: ", errFlag);
		
	if (errFlag == true)			// ���ڰ� ���� ���¹�ȣ 
		throw NoPureNumberException();
	
	if (FindAccountIdx(id) >= 0)	// ������ ���¹�ȣ 
		throw SameIdException();
	
	INPUT_FUNC("# ��  ��: ", name);
			
	balance = InputPureULL("# ��  ��: ", errFlag);
	
	if (errFlag == true)			 // �ݾ׿� ���� ���� 
		throw NoPureNumberException();
	
	rate = InputPureInt("# ������(%): ", errFlag);
	
	if (rate == true)				// �������� ���� ���� 
		throw NoPureNumberException();
	
	mAccArr.PushBack(new NormalAccount(id, balance, name, rate));
}
// �ſ� ���� ���� 
void AccountHandler::CreateHighCreditAccount()
{
	int id;
	unsigned long long balance;
	int rate;
	int level;
	String name;
	bool errFlag;
	
	id = InputPureInt("# ���¹�ȣ: ", errFlag);
	
	if (errFlag == true)				// ���ڰ� ���� ���¹�ȣ 
		throw NoPureNumberException();
	
	if (FindAccountIdx(id) >= 0)		// ������ ���¹�ȣ 
		throw SameIdException();
	
	INPUT_FUNC("# ��  ��: ", name);
	
	balance = InputPureULL("# ��  ��: ", errFlag);
	
	if (errFlag == true)				// �ݾ׿� ���� ����
		throw NoPureNumberException();
	
	rate = InputPureInt("# ������(%): ", errFlag);
	
	if (errFlag == true)				// �������� ���� ���� 
		throw NoPureNumberException();
	
	level = InputPureInt("# �ſ���(1toA 2toB 3toC): ", errFlag);
	
	if (errFlag == true)				// �ſ��� ���� ���� 
		throw NoPureNumberException();
	
	if (level < 1 || 3 < level)					// �߸��� level ��ȣ 
		throw WrongCreditLevelException(level);
	
	mAccArr.PushBack(new HighCreditAccount(id, balance, name, rate, level));
}

// ���°��� �����Լ� 
void AccountHandler::CreateAccount()
{	
	int type;
	bool errFlag;

	DisplayTitle("���°��� ����");
	
	std::cout << "[������������]" << std::endl;
	std::cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << std::endl; 
	
	try
	{
		type = InputPureInt("# ����: ", errFlag);
		
		if (errFlag == true)
			throw NoPureNumberException();

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
	}
	catch (NoPureNumberException& expObj)
	{
		std::cout << "@ �߸��� �޴� ��ȣ�Դϴ�." << std::endl;
		DisplayTitle("���°��� ����");	
		return;
	}
	catch (AccountException& expObj)
	{
		std::cout << std::endl;
		expObj.ShowException();
		DisplayTitle("���°��� ����");
		return;
	}
	
	std::cout << std::endl << "@ ���� �Ϸ�." << std::endl;
	
	DisplayTitle("���°��� ����");
}

// �Ա��ϱ� �����Լ�
void AccountHandler::DepositeMoney()
{
	int index;
	int id; 
	unsigned long long money;
	bool errFlag;
	
	DisplayTitle("�Ա��ϱ� ����");
	
	try
	{
		id = InputPureInt("#���¹�ȣ: ", errFlag);
		
		if (errFlag == true)			// ���¹�ȣ�� ���� ���� 
			throw NoPureNumberException();
		
		index = FindAccountIdx(id);
		
		if (index == -1)					// ���� �� �� ���¹�ȣ 
			throw ClosedAccountException();
		
		money = InputPureULL("# �Ա��� �ݾ�: ", errFlag);
		
		if (errFlag == true)	// ���¹�ȣ�� ���� ���� 
			throw NoPureNumberException();
		
		if (money < 0)						// ���� �ݾ� 
			throw MinusMoneyException();
	}
	catch (AccountException& expObj)
	{
		std::cout << std::endl;
		expObj.ShowException();
		DisplayTitle("�Ա��ϱ� ����");
		return; 
	}
	
	mAccArr[index]->DepositeMoney(money);
	
	std::cout << std::endl << "@ �Ա� �Ϸ�." << std::endl;
	
	DisplayTitle("�Ա��ϱ� ����");
} 

// ����ϱ� �����Լ�
void AccountHandler::WithdrawMoney()
{
	int index;
	int id;
	unsigned long long money;
	bool errFlag;
	
	DisplayTitle("����ϱ� ����");
	
	try
	{
		id = InputPureInt("#���¹�ȣ: ", errFlag);
		
		if (errFlag == true)					// ���¹�ȣ�� ���� ���� 
			throw NoPureNumberException();
		
		index = FindAccountIdx(id);
		
		if (index == -1)						// ���� �� �� ���¹�ȣ 
			throw ClosedAccountException();
		
		money = InputPureULL("# ����� �ݾ�: ", errFlag);
		
		if (errFlag == true)					// ���¹�ȣ�� ���� ���� 
			throw NoPureNumberException();
		
		if (money < 0)							// ���� �ݾ� 
			throw MinusMoneyException();
		
		if (mAccArr[index]->GetBalance() < money)	// �ܾ� ���� 
			throw InsuffBalanceException(mAccArr[index]->GetBalance()); 
	}
	catch (AccountException& expObj)
	{
		std::cout << std::endl;
		expObj.ShowException();
		DisplayTitle("����ϱ� ����");
		return; 
	}
	
	mAccArr[index]->WithdrawMoney(money);
	
	std::cout << std::endl << "@ ��� �Ϸ�." << std::endl;	
	
	DisplayTitle("����ϱ� ����");
}

