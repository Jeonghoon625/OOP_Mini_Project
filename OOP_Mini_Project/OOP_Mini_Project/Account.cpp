#include "Account.h"

Account::Account(const int& accountNum, const char* name, const int& ballance)
{
	this->accountNum = accountNum;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->ballance = ballance;
}

int Account::GetaccountNum() const
{
	return accountNum;
}

int Account::GetBallance() const
{
	return ballance;
}

void Account::AddBallance(const int& money)
{
	ballance += money;
}

void Account::TakeBallance(const int& money)
{
	ballance -= money;
}

void Account::ShowAccountInfo() const
{
	std::cout << "\n���¹�ȣ : " << accountNum << std::endl;
	std::cout << "�̸� : " << name << std::endl;
	std::cout << "�ܾ� : " << ballance << std::endl;
}

Account::~Account()
{
	delete[] name;
}