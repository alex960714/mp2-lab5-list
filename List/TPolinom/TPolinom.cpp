#include "TPolinom.h"

TPolinom::TPolinom()
{
	TMonom m;
	m.coeff = 0;
	m.power = -1;
	pHead->val = m;
}

TPolinom::TPolinom(int mas[][2], int size)
{
	pHead->val.coeff = 0;
	pHead->val.power = -1;
	for (int i = 0; i < size; i++)
	{
		TMonom m;
		m.coeff = mas[i][0];
		m.power = mas[i][1];
		InsLast(m);
	}
}

TPolinom::TPolinom(TPolinom& Q)
{
	pHead->val.coeff = 0;
	pHead->val.power = -1;
	for (Q.Reset(); !Q.IsEnd(); Q.GoNext())
		InsLast(Q.pCurr->val);
}

void TPolinom::InsMonom(TMonom m)
{
	Reset();
	while (pCurr->val.power > m.power)
		GoNext();
	if (pCurr->val.power < m.power)
		InsCurr(m);
	else
	{
		pCurr->val.coeff += m.coeff;
		if (pCurr->val.coeff == 0)
			DelCurr();
	}
}

TPolinom& TPolinom::operator+=(TPolinom& Q)
{
	Reset();
	Q.Reset();
	while (Q.pCurr->val.power != -1)
	{
		if (pCurr->val.power > Q.pCurr->val.power)
			GoNext();
		else if (pCurr->val.power < Q.pCurr->val.power)
		{
			InsCurr(Q.pCurr->val);
			Q.GoNext();
		}
		else
		{
			pCurr->val.coeff += Q.pCurr->val.coeff;
			if (pCurr->val.coeff == 0)
				DelCurr();
			else GoNext();
			Q.GoNext();
		}
	}
	return *this;
}

TPolinom& TPolinom::operator*=(const double p)
{
	if (p == 0)
	{
		Reset();
		while (!IsEnd())
			DelCurr();
	}
	else
	    for (Reset(); !IsEnd(); GoNext())
		    pCurr->val.coeff *= p;
	return *this;
}

void TPolinom::Print()
{
	for (Reset(); !IsEnd(); GoNext())
	{
		if (pCurr->val.coeff != 1)
			cout << pCurr->val.coeff << " ";
		if (pCurr->val.power / 100 > 0)
			cout << "x^" << pCurr->val.power / 100 << " ";
		if (pCurr->val.power % 100 / 10 > 0)
			cout << "y^" << pCurr->val.power % 100 / 10 << " ";
		if (pCurr->val.power % 10 > 0)
			cout << "z^" << pCurr->val.power % 10 << " ";
		if (pCurr->pNext->val.coeff > 0)
			cout << "+ ";
	}
	cout << endl;
}