#include "AccountHandler.h"
#include "BoundCheckArray.h"
#include "BoundCheckArray.cpp"

AccountHandler::AccountHandler() : memberNum(0)
{
	for (int i = 0; i < ACCOUNT_MAX; i++)
	{
		accountList[i] = nullptr;
	}
}

AccountHandler::AccountHandler(const AccountHandler& copy) // prevent copy generate
{
}

void AccountHandler::NewAccount(Account* account)
{
	accountList[memberNum++] = account;
}

int AccountHandler::GetMemberNum() const
{
	return memberNum;
}

int AccountHandler::FindAccount(const int& accountNum) const
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
		DepositException expn(money);
		throw expn;
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
		WithDrawException expn(money);
		throw expn;
	}
	else if (accountList[find_idx]->GetBallance() < money)
	{
		WithDrawException expn(money);
		throw expn;
	}
	else
	{
		accountList[find_idx]->TakeBallance(money);
		std::cout << "��� �Ϸ�" << std::endl;
	}
}

void AccountHandler::ShowAllAccountInfo() const
{
	if (GetMemberNum() == 0)
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

void AccountHandler::DeleteAccount(const int find_idx)
{
	delete accountList[find_idx];
	accountList[find_idx] = nullptr;

	if (find_idx != memberNum - 1)
	{
		for (int i = find_idx; i < memberNum; i++)
		{
			if (find_idx < memberNum - 1)
			{
				accountList[i] = accountList[i + 1];
			}
			else
			{
				accountList[i] = nullptr;
			}
		}
	}

	memberNum--;
	std::cout << "�����Ǿ����ϴ�." << std::endl;
}

AccountHandler::~AccountHandler() 
{
	for (int i = 0; i < memberNum; i++)
	{
		delete accountList[i];
	}
}
