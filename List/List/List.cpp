// List.cpp: определяет точку входа для консольного приложения.
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
		cout << "Введите количество мономов в полиноме P:" << endl;
		cin >> n;
		cout << "Введите полином P в формате коэффициент + степень:" << endl;
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
			cout << "1. Сложить 2 полинома (P + Q);" << endl;
			cout << "2. Умножить полином на константу (P * c);" << endl;
			cout << "3. Вычитание полиномов (P - Q)." << endl;
			cin >> op1;
			int n1 = 1;
			int mas1[100][2] = { 0,0 };
			if (op1 != '2')
			{
				cout << "Введите количество мономов в полиноме Q:" << endl;
				cin >> n1;
				cout << "Введите полином Q в формате коэффициент + степени:" << endl;
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
			case '2': cout << "Введите константу:" << endl;
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
			default: cout << "Некорректный ввод. Введите значение ещё раз:" << endl;
			}
			if ((op1 >= '1') && (op1 <= '3'))
			{
				do
				{
					cout << "1. Провести новую операцию с полиномом P;" << endl;
					cout << "2. Ввести полином P заново;" << endl;
					cout << "3. Завершение работы." << endl;
					cin >> op;
					switch (op)
					{
					case '1': op1 = '0';
					case '2':
					case '3': break;
					default: cout << "Некорректный ввод. Введите номер операции заново:" << endl;
					}
				} while ((op<'1') || (op>'3'));
			}
		} while ((op1<'1') || (op1>'3'));
	} while (op != '3');
    return 0;
}

