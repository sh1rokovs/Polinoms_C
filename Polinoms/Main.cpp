#include <iostream>
#include <stdio.h>
#include "Polinom.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	Polinom polinom;
	int s = 0, kol = 0, w = 1, q = 0, q1 = 0, r = 0;
	float p = 0;

	while (w)
	{
		system("cls");
		cout << "1. ������� ��������" << endl;
		cout << "2. ���������� ��������" << endl;
		cout << "3. ������� ����� �� ��������" << endl;
		cout << "4. �������������� �������� � ����������" << endl;
		cout << "5. �����" << endl;
		cin >> s;
		switch (s)
		{
		case 1:
			system("cls");
			cout << "������� ���������� ������� � ������ ��������:" << endl;
			cout << "-->:";
			cin >> kol;
			cout << endl;
			cout << "������� ������������ ��� ������(��)" << endl;
			for (int i = 0; i < kol; i++)
			{
				cout << "x^?y^?z^?:";
				cin >> p;
				cout << "x^:";
				cin >> q;
				if (0 <= q && q <= 9)
					q1 = q * 100;
				else
				{
					r++;
					cout << "������������ �������";
				}
				cout << endl;
				cout << "y^:";
				cin >> q;
				if (0 <= q && q <= 9)
					q1 = q1 + q * 10;
				else
				{
					r++;
					cout << "������������ �������";
				}
				cout << endl;
				cout << "z^:";
				cin >> q;
				if (0 <= q && q <= 9)
					q1 = q1 + q;
				else
				{
					r++;
					cout << "������������ �������";
				}
				cout << endl;
				if (r != 3)
					polinom.InsElem(p, q1, 1);
				else
					cout << "����� �� ������" << endl;
				q1 = 0;
				r = 0;
			}
			cout << "������� ���������� ������� � ������ ��������:" << endl;
			cout << "-->:";
			cin >> kol;
			cout << endl;
			cout << "������� ������������ ��� ������(��)" << endl;
			for (int i = 0; i < kol; i++)
			{
				cout << "x^?y^?z^?:";
				cin >> p;
				cout << "x^:";
				cin >> q;
				if (0 <= q && q <= 9)
					q1 = q * 100;
				else
				{
					r++;
					cout << "������������ �������";
				}
				cout << endl;
				cout << "y^:";
				cin >> q;
				if (0 <= q && q <= 9)
					q1 = q1 + q * 10;
				else
				{
					r++;
					cout << "������������ �������";
				}
				cout << endl;
				cout << "z^:";
				cin >> q;
				if (0 <= q && q <= 9)
					q1 = q1 + q;
				else
				{
					r++;
					cout << "������������ �������";
				}
				cout << endl;
				if (r != 3)
					polinom.InsElem(p, q1, 2);
				else
					cout << "����� �� ������";
				q1 = 0;
				r = 0;
			}
			break;
		case 2:
			polinom.PrintList(1);
			polinom.PrintList(2);
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "1. ������� ����� �� ������� ��������" << endl;
			cout << "2. ������� ����� �� ������� ��������" << endl;
			cout << "3. �����" << endl;
			cout << "-->:";
			cin >> s;
			switch (s)
			{
			case 1:
				cout << "������� ����� ���������� ��������" << endl;
				cout << "-->:";
				cin >> kol;
				polinom.DelElem(1, kol);
				break;
			case 2:
				cout << "������� ����� ���������� ��������" << endl;
				cout << "-->:";
				cin >> kol;
				polinom.DelElem(2, kol);
				break;
			case 3:
				break;
			}
			break;
		case 4:
			system("cls");
			cout << "1. �������� ��������" << endl;
			cout << "2. �������� ���������" << endl;
			cout << "3. �������� ���������" << endl;
			cout << "4. �������� �������" << endl;
			cout << "5. �����" << endl;
			cout << "-->:";
			cin >> s;
			switch (s)
			{
			case 1:
				polinom.SumPol();
				break;
			case 2:
				polinom.DifPol();
				break;
			case 3:
				polinom.MultPol();
				break;
			case 4:
				polinom.DivPol();
				break;
			case 5:
				break;
			}
			break;
		case 5:
			return w = 0;
			break;
		}
	}

}
/*if (pCurr->pow == pCurr2->pow)
			{ ////////////
				pCurr->coef += pCurr2->coef;
				if (pCurr->coef == 0)
				{
					pPrev = pPrev->pNext;
					pPrev2 = pPrev2->pNext;
					pCurr = pCurr->pNext;
					pCurr2 = pCurr2->pNext;
					DelFirst(2);
					size++;
					size2--;
				}
				else
				{
					pPrev = pPrev->pNext;
					pPrev2 = pPrev2->pNext;
					pCurr = pCurr->pNext;
					pCurr2 = pCurr2->pNext;
					DelFirst(2);
					size++;
					size2--;
				}
			} ////////
			if (pCurr->pow < pCurr2->pow)
			{
				pPrev->pNext = pPrev2->pNext;
				pPrev2->pNext = pCurr2->pNext;
				pCurr2->pNext = pCurr;

				pPrev = pPrev->pNext;
				pPrev2 = pPrev2->pNext;
				pCurr = pCurr->pNext;
				pCurr2 = pCurr2->pNext;
				size2--;
				size++;
			}
			if (pCurr->pow > pCurr2->pow)
			{
				for (int i = 0; i < GetSize(1); i++)
				{
					pPrev = pPrev->pNext;
					pCurr = pCurr->pNext;
					if (pCurr->pow < pCurr2->pow)
					{
						pPrev2->pNext = pCurr2->pNext;
						pPrev->pNext = pCurr2;
						pCurr2->pNext = pCurr;
						size++;
						size2--;
					}
				}
				pPrev2 = this->pHead2;
				pCurr2 = pPrev2->pNext;
			}*/