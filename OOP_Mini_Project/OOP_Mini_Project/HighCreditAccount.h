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
private :
	int creditRatingResult;

public :
	HighCreditAccount(const int& accountNum, const char* name, const int& ballance, const int& interest, const int& creditRating);
	
	virtual void AddBallance(const int& money);

	virtual void ShowAccountInfo() const;

	virtual ~HighCreditAccount();
};

