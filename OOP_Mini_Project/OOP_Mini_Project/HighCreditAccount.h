#pragma once
#include "NormalAccount.h"

namespace Grade
{
	enum
	{
		A = 1,
		B,
		C 
	};
}

class HighCreditAccount : public NormalAccount
{
protected :
	int creditRatingResult;

public :
	HighCreditAccount(const int& accountNum, const char* name, const int& ballance, const int& interest, const int& creditRating);
	
	HighCreditAccount(const HighCreditAccount& copy);

	HighCreditAccount& operator= (const HighCreditAccount& ref);

	virtual void AddBallance(const int& money);

	virtual void ShowAccountInfo() const;

	virtual ~HighCreditAccount();
};

