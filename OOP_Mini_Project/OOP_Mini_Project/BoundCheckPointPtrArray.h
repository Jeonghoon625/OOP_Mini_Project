#pragma once
#include "HighCreditAccount.h"

class BoundCheckPointPtrArray
{
private:
	ACCOUNT_PTR* accountArr;
	int arrLen;

	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr);

public:
	BoundCheckPointPtrArray(int len = 10);

	ACCOUNT_PTR& operator[] (int idx);

	ACCOUNT_PTR operator[] (int idx) const;

	int GetArrLen() const;

	~BoundCheckPointPtrArray();
};
