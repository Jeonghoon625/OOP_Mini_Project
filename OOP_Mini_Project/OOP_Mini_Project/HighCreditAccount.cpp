#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(const int& accountNum, const char* name, const int& ballance, const int& interest, const int& creditRating)
	: NormalAccount(accountNum, name, ballance, interest)
{
	switch (creditRating)
	{
	case Grade::A :
		creditRatingResult = 7;
		break;

	case Grade::B :
		creditRatingResult = 4;
		break;

	case Grade::C :
		creditRatingResult = 2;
		break;

	default:
		creditRatingResult = 0;
		break;
	}
}

void HighCreditAccount::AddBallance(const int& money)
{
	NormalAccount::AddBallance(money);
	Account::AddBallance(money * creditRatingResult / 100);
}

void HighCreditAccount::ShowAccountInfo() const
{
	NormalAccount::ShowAccountInfo();
	std::cout << "�߰� ������ : " << creditRatingResult << "%" << std::endl;
}

HighCreditAccount::~HighCreditAccount()
{
}
