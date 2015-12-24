// List.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "TLink.h"
#include <TPolinom.h>
#include "THeadList.h"
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
		cout << "1. ������ �������;" << endl;
		cout << "2. ���������� ������." << endl;
		cin >> op;
		if ((op != '1') && (op != '2'))
			cout << "������������ ����. ������� �������� ��� ���:" << endl;
		if (op == '1')
		{
			int n;
			cout << "������� ���������� ������� � ��������:" << endl;
			cin >> n;
			cout << "������� ������� � ������� ����������� + �������:" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> mas[i][0];
				cin >> mas[i][1];
			}
			TPolinom P(mas,n);
			char op1;
			cout << "1. ������� 2 ��������;" << endl;
			cout << "2. �������� ������� �� ���������;" << endl;
			cout << "3. ��������� ���������." << endl;
			do
			{
				cin >> op1;
				int n1;
				int mas1[100][2];
				if (op != '2')
				{
					cout << "������� ������ ������� ��������:" << endl;
					cin >> n1;
					cout << "������� ������ ������� � ������� ����������� + �������:" << endl;
					for (int i = 0; i < n1; i++)
					{
						cin >> mas[i][0];
						cin >> mas[i][1];
					}
				}
				TPolinom Q(mas1, n1);
				switch (op1)
				{
				case '1': P += Q;
					P.Print();
					break;
				case 2: cout << "������� ���������:" << endl;
					int c;
					cin >> c;
					P *= c;
					P.Print();
					break;
				case 3: P -= Q;
					P.Print();
					break;
				default: cout << "������������ ����. ������� �������� ��� ���:" << endl;
				}
			} while ((op<'1') || (op>'3'));
		}
	} while (op != '2');
    return 0;
}

