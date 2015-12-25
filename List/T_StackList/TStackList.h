//#pragma once
#ifndef _T_STACKLIST_H_
#define _T_STACKLIST_H_
#include "TLink.h"
#include "TList.h"

template <class T>
class TStackList
{
private:
	TLink <T> *pFirst;

public:
	TStackList() { pFirst = NULL; }
	~TStackList()
	{
		TLink <T> *curr = pFirst;
		if (curr != NULL)
		{
			while (curr->pNext != NULL)
			{
				TLink <T> *tmp = curr;
				curr = curr->pNext;
				delete tmp;
			}
			delete curr;
		}
	}

	bool IsEmpty() { return pFirst == NULL; }

	bool IsFull()
	{
		try
		{
			TLink <T> *tmp = new TLink <T>;
			if (tmp == NULL)
				return true;
			delete tmp;
			return false;
		}
		catch (...) { return true; }
	}

	T Pop()
	{
		if (IsEmpty())
			throw - 1;
		T tmp = pFirst->val;
		TLink <T> *curr = pFirst;
		pFirst = pFirst->pNext;
		delete curr;
		return tmp;
	}

	T Top()
	{
		if (IsEmpty())
			throw - 1;
		return pFirst->val;
	}

	void Push(const T elem)
	{
		TLink <T> *tmp = new TLink <T>;
		tmp->val = elem;
		tmp->pNext = pFirst;
		pFirst = tmp;
	}
};

#endif