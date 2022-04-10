#include "BoundCheckPointPtrArray.h"

BoundCheckPointPtrArray::BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) 
{ 
}

BoundCheckPointPtrArray::BoundCheckPointPtrArray(int len) :arrLen(len)
{
	accountArr = new ACCOUNT_PTR[len];
}

ACCOUNT_PTR& BoundCheckPointPtrArray::operator[] (int idx)
{
	if (idx < 0 || idx >= arrLen)
	{
		std::cout << "Array index out of bound exception" << std::endl;
		exit(1);
	}

	return accountArr[idx];
}
ACCOUNT_PTR BoundCheckPointPtrArray::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrLen)
	{
		std::cout << "Array index out of bound exception" << std::endl;
		exit(1);
	}

	return accountArr[idx];
}

int BoundCheckPointPtrArray::GetArrLen() const
{
	return arrLen;
}

BoundCheckPointPtrArray::~BoundCheckPointPtrArray()
{
	delete[] accountArr;
}