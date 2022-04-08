#pragma once
#include "HighCreditAccount.h"

class BoundCheckPointPtrArray
{
private:
	ACCOUNT_PTR* accountArr;
	int arrLen;

	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }

public:
	BoundCheckPointPtrArray(int len) :arrLen(len)
	{
		accountArr = new ACCOUNT_PTR[len];
	}

	ACCOUNT_PTR& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrLen)
		{
			std::cout << "Array index out of bound exception" << std::endl;
			exit(1);
		}

		return accountArr[idx];
	}
	ACCOUNT_PTR operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrLen)
		{
			std::cout << "Array index out of bound exception" << std::endl;
			exit(1);
		}

		return accountArr[idx];
	}

	int GetArrLen() const
	{
		return arrLen;
	}

	~BoundCheckPointPtrArray()
	{
		delete[] accountArr;
	}
};
