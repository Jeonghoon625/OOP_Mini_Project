#include "AccountHandler.h"
#include "BoundCheckArray.h"
#include "BoundCheckArray.cpp"

AccountHandler::AccountHandler() : memberNum(0)
{
	for (int i = 0; i < ACCOUNT_MAX; i++)
	{
		accountList[i] = NULL;
	}
}

AccountHandler::AccountHandler(const AccountHandler& copy)
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
		std::cout << "개설된 계좌가 없습니다." << std::endl;
	}
	else if (money < 0)
	{
		std::cout << "입금액이 0보다 작을 수는 없습니다." << std::endl;
	}
	else
	{
		accountList[find_idx]->AddBallance(money);
		std::cout << "입금 완료" << std::endl;
	}
}

void AccountHandler::WithDraw(const int& accountNum, const int& money)
{
	int find_idx = FindAccount(accountNum);

	if (find_idx < 0)
	{
		std::cout << "개설된 계좌가 없습니다." << std::endl;
	}
	else if (money < 0)
	{
		std::cout << "출금액이 0보다 작을 수는 없습니다." << std::endl;
	}
	else if (accountList[find_idx]->GetBallance() < money)
	{
		std::cout << "잔액이 부족합니다." << std::endl;
	}
	else
	{
		accountList[find_idx]->TakeBallance(money);
		std::cout << "출금 완료" << std::endl;
	}
}

void AccountHandler::ShowAllAccountInfo() const
{
	if (GetMemberNum() == 0)
	{
		std::cout << "개설된 계좌가 없습니다." << std::endl;
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
