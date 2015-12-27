//#pragma once
#ifndef _T_POLINOM_H_
#define _T_POLINOM_H_
#include "TLink.h"
#include "THeadList.h"
#include <iostream>
using namespace std;

struct TMonom
{
	double coeff;
	int power;
};

inline bool operator<(const TMonom& m1, const TMonom& m2) { return m1.power < m2.power; };
inline bool operator>(const TMonom& m1, const TMonom& m2) { return m1.power > m2.power; };

class TPolinom : public THeadList <TMonom>
{
public:
	TPolinom();	
	TPolinom(int mas[][2], int size);
	TPolinom(TPolinom& Q);  //конструктор копирования

	void InsMonom(TMonom m);  //вставить моном
	TPolinom& operator+=(TPolinom &Q);  
	TPolinom& operator*=(const double p);
	TPolinom& operator-=(TPolinom &Q);
	bool operator==(TPolinom &Q);
	void Print();  //печать полинома
};

#endif
