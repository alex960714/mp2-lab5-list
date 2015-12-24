// List.cpp: определяет точку входа для консольного приложения.
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
		cout << "1. Ввести полином;" << endl;
		cout << "2. Завершение работы." << endl;
		cin >> op;
		if ((op != '1') && (op != '2'))
			cout << "Некорректный ввод. Введите значение ещё раз:" << endl;
		if (op == '1')
		{
			int n;
			cout << "Введите количество мономов в полиноме:" << endl;
			cin >> n;
			cout << "Введите полином в формате коэффициент + степень:" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> mas[i][0];
				cin >> mas[i][1];
			}
			TPolinom P(mas,n);
			char op1;
			cout << "1. Сложить 2 полинома;" << endl;
			cout << "2. Умножить полином на константу;" << endl;
			cout << "3. Вычитание полиномов." << endl;
			do
			{
				cin >> op1;
				int n1;
				int mas1[100][2];
				if (op != '2')
				{
					cout << "Введите размер второго полинома:" << endl;
					cin >> n1;
					cout << "Введите второй полином в формате коэффициент + степени:" << endl;
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
				case 2: cout << "Введите константу:" << endl;
					int c;
					cin >> c;
					P *= c;
					P.Print();
					break;
				case 3: P -= Q;
					P.Print();
					break;
				default: cout << "Некорректный ввод. Введите значение ещё раз:" << endl;
				}
			} while ((op<'1') || (op>'3'));
		}
	} while (op != '2');
    return 0;
}

