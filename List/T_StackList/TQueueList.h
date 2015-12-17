#pragma once
#include "TLink.h"
#include "TList.h"

template <class T>
class TQueueList
{
private:
	TLink <T> *pFirst, *pLast;

public:
	TQueueList()
	{
		pFirst = NULL;
		pLast = NULL;
	}
	~TQueueList()
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
			return false;
		}
		catch () return false;
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

	T Front()
	{
		if (IsEmpty())
			throw - 1;
		return pFirst->val;
	}

	T Back()
	{
		if (IsEmpty())
			throw - 1;
		return pLast->val;
	}

	void Push(const T elem)
	{
		TLink <T> *tmp = new TLink <T>;
		tmp->val = elem;
		tmp->pNext = NULL;
		if (IsEmpty())
			pFirst = tmp;
		else pLast->pNext = tmp;
		pLast = tmp;
	}
};