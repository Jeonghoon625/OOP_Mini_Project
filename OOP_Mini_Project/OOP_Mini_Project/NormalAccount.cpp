#include "NormalAccount.h"

NormalAccount::NormalAccount(const int& accountNum, string name, const int& ballance, const int& interest)
	: Account(accountNum, name, ballance)
{
	this->interest = interest;
}

NormalAccount::NormalAccount(const NormalAccount& copy) : Account(copy.accountNum, copy.name, copy.ballance), interest(copy.interest)
{
}

NormalAccount& NormalAccount::operator= (const NormalAccount& ref)
{
	accountNum = ref.accountNum;
	ballance = ref.ballance;
	name = ref.name;
	interest = ref.interest;

	return *this;
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
