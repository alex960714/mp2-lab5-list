#pragma once
#include "TLink.h"
#include "TList.h"
#include <iostream>
using namespace std;

template <class T>
class THeadList 
{
protected:
	TLink <T> *pHead, *pFirst, *pLast, *pCurr, *pPred, *pStop;
	int pos, len;

public:
	THeadList()
	{
		pHead = new TLink <T>;
		pStop = pHead;
		pHead->pNext = pStop;
		pFirst = pLast = pCurr = pHead = NULL;
		pos = -1;
		len = 0;
	}
	virtual ~THeadList()
	{
		if (len)
		{
			pCurr = pFirst;
			while (pCurr != NULL)
			{
				pPred = pCurr;
				pCurr = pCurr->pNext;
				delete pPred;
			}
		}
		delete pHead;
	}

	void InsFirst(const T elem)
	{
		TLink <T> *tmp = new TLink <T>;
		tmp->val = elem;
		if (!len)
		{
			tmp->pNext = pStop;
			pFirst = pLast = tmp;
		}
		else
		{
			tmp->pNext = pFirst;
			pFirst = tmp;
		}
		pHead->pNext = tmp;
		len++;
		pos++;
	}

	void DelFirst()
	{
		if (len)
		{
			pHead->pNext = pFirst->pNext;
			delete pFirst;
			pFirst = pHead->pNext;
			pos--;
			len--;
		}
	}

	void InsCurr(const T elem)
	{
		if (pCurr == pFirst)
			InsFirst(elem);
		else
		{
			TLink <T> *tmp = new TLink <T>;
			tmp->val = elem;
			tmp->pNext = pCurr;
			pPred->pNext = tmp;
			pCurr = tmp;
			len++;
		}
	}

	void DelCurr()
	{
		if (len)
		{
			if (pCurr == pFirst)
				DelFirst();
			else
			{
				pPred->pNext = pCurr->pNext;
				delete pCurr;
				pCurr = pPred->pNext;
				len--;
			}
		}
	}

	void InsLast(const T elem)
	{
		if (!len)
			InsFirst(elem);
		else
		{
			TLink <T> *tmp = new TLink <T>;
			tmp->val = elem;
			tmp->pNext = pStop;
			pLast->pNext = tmp;
			pLast = tmp;
			len++;
		}
	}

	void DelLast()
	{
		if (len)
		{
			if (pLast == pFirst)
				DelFirst();
			else
			{
				Reset();
				while (pCurr->pNext != pLast)
					GoNext();
				pCurr->pNext = pStop;
				delete pLast;
				pLast = pCurr;
			}
		}
	}

	void Reset() { pCurr = pFirst; }

	void GoNext()
	{
		pPred = pCurr;
		pCurr = pCurr->pNext;
	}

	bool IsEnd() { return pCurr == pStop; }
};
