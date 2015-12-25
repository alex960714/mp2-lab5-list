// List.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "TLink.h"
#include <TPolinom.h>
#include <locale.h>
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_CTYPE, "Russian");
	char op;
	int mas[100][2];
	do
	{
		int n;
		cout << "������� ���������� ������� � �������� P:" << endl;
		cin >> n;
		cout << "������� ������� P � ������� ����������� + �������:" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> mas[i][0];
			cin >> mas[i][1];
		}
		char op1;
		do
		{
			TPolinom P(mas, n);
			cout << "P = ";
			P.Print();
			cout << "1. ������� 2 �������� (P + Q);" << endl;
			cout << "2. �������� ������� �� ��������� (P * c);" << endl;
			cout << "3. ��������� ��������� (P - Q)." << endl;
			cin >> op1;
			int n1 = 1;
			int mas1[100][2] = { 0,0 };
			if (op1 != '2')
			{
				cout << "������� ���������� ������� � �������� Q:" << endl;
				cin >> n1;
				cout << "������� ������� Q � ������� ����������� + �������:" << endl;
				for (int i = 0; i < n1; i++)
				{
					cin >> mas1[i][0];
					cin >> mas1[i][1];
				}
			}
			TPolinom Q(mas1, n1);
			if (op1 != '2')
			{
				cout << "Q = ";
				Q.Print();
			}
			switch (op1)
			{
			case '1': P += Q;
				cout << "P + Q = ";
				P.Print();
				break;
			case '2': cout << "������� ���������:" << endl;
				int c;
				cin >> c;
				P *= c;
				cout << "P * " << c << " = ";
				P.Print();
				break;
			case '3': P -= Q;
				cout << "P - Q = ";
				P.Print();
				break;
			default: cout << "������������ ����. ������� �������� ��� ���:" << endl;
			}
			if ((op1 >= '1') && (op1 <= '3'))
			{
				do
				{
					cout << "1. �������� ����� �������� � ��������� P;" << endl;
					cout << "2. ������ ������� P ������;" << endl;
					cout << "3. ���������� ������." << endl;
					cin >> op;
					switch (op)
					{
					case '1': op1 = '0';
					case '2':
					case '3': break;
					default: cout << "������������ ����. ������� ����� �������� ������:" << endl;
					}
				} while ((op<'1') || (op>'3'));
			}
		} while ((op1<'1') || (op1>'3'));
	} while (op != '3');
    return 0;
}

