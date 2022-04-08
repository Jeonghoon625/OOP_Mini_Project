#include "NormalAccount.h"

NormalAccount::NormalAccount(const int& accountNum, const char* name, const int& ballance, const int& interest)
	: Account(accountNum, name, ballance)
{
	this->interest = interest;
}

NormalAccount::NormalAccount(const NormalAccount& copy) : Account(copy.accountNum, copy.name, copy.ballance), interest(copy.interest)
{
}

void NormalAccount::AddBallance(const int& money)
{
	Account::AddBallance(money);
	Account::AddBallance(money * interest / 100);
}

void NormalAccount::ShowAccountInfo() const
{
	Account::ShowAccountInfo();
	std::cout << "ÀÌÀÚÀ² : " << interest << "%" << std::endl;
}

NormalAccount::~NormalAccount()
{
}
