#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(const int& accountNum, const char* name, const int& ballance, const int& interest, const int& creditRating)
	: NormalAccount(accountNum, name, ballance, interest)
{
	switch (creditRating)
	{
	case 1:
		creditRatingResult = 7;
		break;

	case 2:
		creditRatingResult = 4;
		break;

	case 3:
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
