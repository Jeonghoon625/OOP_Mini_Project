#pragma once
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
private :
	int creditRatingResult;

public :
	HighCreditAccount(const int& accountNum, const char* name, const int& ballance, const int& interest, const int& creditRating);
	
	virtual void AddBallance(const int& money);
};

