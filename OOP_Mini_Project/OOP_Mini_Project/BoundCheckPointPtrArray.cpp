#include "BoundCheckPointPtrArray.h"

template <typename T>
BoundCheckArray<T>::BoundCheckArray(const T& arr)
{ 
}

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrLen(len)
{
	accountArr = new ACCOUNT_PTR[len];
}

template <typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
	if (idx < 0 || idx >= arrLen)
	{
		std::cout << "Array index out of bound exception" << std::endl;
		exit(1);
	}

	return accountArr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrLen)
	{
		std::cout << "Array index out of bound exception" << std::endl;
		exit(1);
	}

	return accountArr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrLen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[] accountArr;
}
