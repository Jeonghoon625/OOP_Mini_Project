#pragma once
#include "HighCreditAccount.h"

template <typename T>
class BoundCheckArray
{
private:
	T* accountArr;
	int arrLen;

	BoundCheckArray(const T& arr);

public:
	BoundCheckArray(int len = 10);

	T& operator[] (int idx);

	T operator[] (int idx) const;

	int GetArrLen() const;

	~BoundCheckArray();
};
