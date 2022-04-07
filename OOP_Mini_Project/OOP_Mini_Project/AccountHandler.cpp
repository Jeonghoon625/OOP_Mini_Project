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
		std::cout << "이미 동일한 계좌번호로 개설된 계좌가 있습니다." << std::endl;
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
	if (accountList[0] == NULL)
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

