#include "AccountHandler.h"

AccountHandler::AccountHandler() : memberNum(0)
{
	for (int i = 0; i < ACCOUNT_MAX; i++)
	{
		accountList[i] = NULL;
	}
}

void AccountHandler::NewAccount(Account* account)
{
	if (FindAccount(account->GetaccountNum()) < 0)
	{
		accountList[memberNum++] = account;
	}
	else
	{
		std::cout << "�̹� ������ ���¹�ȣ�� ������ ���°� �ֽ��ϴ�." << std::endl;
		delete account;
	}
}

int AccountHandler::GetMemberNum() const
{
	return memberNum;
}

int AccountHandler::FindAccount(const int& accountNum)
{
	for (int i = 0; i < memberNum; i++)
	{
		if (accountList[i]->GetaccountNum() == accountNum)
		{
			return i;
		}
	}

	return -1;
}

void AccountHandler::Deposit(const int& accountNum, const int& money)
{
	int find_idx = FindAccount(accountNum);

	if (find_idx < 0)
	{
		std::cout << "������ ���°� �����ϴ�." << std::endl;
	}
	else if (money < 0)
	{
		std::cout << "�Աݾ��� 0���� ���� ���� �����ϴ�." << std::endl;
	}
	else
	{
		accountList[find_idx]->AddBallance(money);
		std::cout << "�Ա� �Ϸ�" << std::endl;
	}
}

void AccountHandler::WithDraw(const int& accountNum, const int& money)
{
	int find_idx = FindAccount(accountNum);

	if (find_idx < 0)
	{
		std::cout << "������ ���°� �����ϴ�." << std::endl;
	}
	else if (money < 0)
	{
		std::cout << "��ݾ��� 0���� ���� ���� �����ϴ�." << std::endl;
	}
	else if (accountList[find_idx]->GetBallance() < money)
	{
		std::cout << "�ܾ��� �����մϴ�." << std::endl;
	}
	else
	{
		accountList[find_idx]->TakeBallance(money);
		std::cout << "��� �Ϸ�" << std::endl;
	}
}

void AccountHandler::ShowAllAccountInfo() const
{
	if (accountList[0] == NULL)
	{
		std::cout << "������ ���°� �����ϴ�." << std::endl;
	}
	else
	{
		for (int i = 0; i < memberNum; i++)
		{
			accountList[i]->ShowAccountInfo();
		}
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < memberNum; i++)
	{
		delete accountList[i];
	}
}

