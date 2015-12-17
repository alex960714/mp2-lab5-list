#pragma once
#include "TLink.h"

template <class T>
class TList
{
private:
	TLink <T> *pFirst;
public:
	void AddFirst(const T elem)
	{
		TLink <T> *tmp;
		tmp = new TLink <T>;
		tmp->val = elem;
		tmp->pNext = pFirst;
		pFirst = tmp;
	}

	void AddLast(T elem)
	{
		TLink <T> *tmp = new TLink <T>;
		tmp->val = elem;
		tmp->pNext = NULL;
		TLink <T> *Curr = pFirst;
		while (Curr->pNext != NULL)
			Curr = Curr->pNext;
		Curr->pNext = tmp;
	}
};
