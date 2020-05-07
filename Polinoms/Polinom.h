#pragma once
#include <iostream>
#include<stdio.h>

using namespace std;
class Polinom																	//Класс списка мономов
{
public:																			//Методы
	Polinom();
	inline ~Polinom() { clear(1); clear(2); }
	void InsElem(float coef, int pow, int num);
	int GetCoef(float coef) { return coef; };
	void SumPol();
	void DifPol();
	void DivPol();
	void MultPol();
	void DelFirst(int num);
	void DelLast(int num);
	void DelElem(int num, int index);
	void clear(int num);
	int GetSize(int num);
	void PrintList(int num);
	int GetX(int pow) { return pow / 100; }
	int GetY(int pow) { return (pow / 10) % 10; }
	int GetZ(int pow) { return pow % 10; }
private:
	class Monom {																//Класс звена
	public:
		int coef;
		float pow;
		Monom* pNext;
	public:
		Monom(float coef, int pow, Monom* pNext)
		{
			this->coef = coef;
			this->pow = pow;
			this->pNext = pNext;
		}
	};
	int size;
	int size2;
	Monom* pHead;
	Monom* pCurr;
	Monom* pHead2;
	Monom* pCurr2;
	Monom* pNew;
	Monom* pNew2;
	Monom* pPrev;
	Monom* pPrev2;
	Monom* tmp;
	Monom* tmp2;
};
Polinom::Polinom()
{
	pHead = new Monom(0, -1, NULL);
	pHead->pNext = pHead;
	size = 1;
	pHead2 = new Monom(0, -1, NULL);
	pHead2->pNext = pHead2;
	size2 = 1;
}
void Polinom::PrintList(int num)
{
	if (num == 1)
	{
		if (GetSize(num) > 1)
		{
			pCurr = pHead->pNext;
			for (int i = 0; i < 100; i++) { cout << "-"; }
			cout << endl;
			while (pCurr != pHead)
			{
				if (pCurr->coef > 0)
				{
					cout << "+ ";
				}
				cout << pCurr->coef;
				if (GetX(pCurr->pow) > 0)
				{
					cout << "x^" << GetX(pCurr->pow) << " ";
				}
				if (GetY(pCurr->pow) > 0)
				{
					cout << "y^" << GetY(pCurr->pow) << " ";
				}
				if (GetZ(pCurr->pow) > 0)
				{
					cout << "z^" << GetZ(pCurr->pow);
				}
				cout << " ";
				pCurr = pCurr->pNext;
			}
			cout << endl;
		}
		else
			cout << "Пустой полином" << endl;
	}
	if (num == 2)
	{
		if (GetSize(num) > 1)
		{
			pCurr2 = pHead2->pNext;
			for (int i = 0; i < 100; i++) { cout << "-"; }
			cout << endl;
			while (pCurr2 != pHead2)
			{
				if (pCurr2->coef > 0)
				{
					cout << "+ ";
				}
				cout << pCurr2->coef;
				if (GetX(pCurr2->pow) > 0)
				{
					cout << "x^" << GetX(pCurr2->pow) << " ";
				}
				if (GetY(pCurr2->pow) > 0)
				{
					cout << "y^" << GetY(pCurr2->pow) << " ";
				}
				if (GetZ(pCurr2->pow) > 0)
				{
					cout << "z^" << GetZ(pCurr2->pow);
				}
				cout << " ";
				pCurr2 = pCurr2->pNext;
			}
			cout << endl;
		}
		else
			cout << "Пустой полином" << endl;
	}
}
int Polinom::GetSize(int num)
{
	if (num == 1)
	{
		return size;
	}
	if (num == 2)
	{
		return size2;
	}
}
void Polinom::InsElem(float coef, int pow, int num)
{
	int sch = 0, sch1 = 0;
	if (num == 1)
	{
		if (coef != 0)
		{
			pPrev = this->pHead;
			pCurr = pHead->pNext;
			for (int i = 0; i < GetSize(num); i++)
			{
				if (pCurr->pow > pow)
				{
					pCurr = pCurr->pNext;
					pPrev = pPrev->pNext;
					sch1 = 1;
				}
				if (pCurr->pow == pow)
				{
					sch = 1;
					break;
				}
			}
			if (sch != 1)
			{
				if (sch1 == 1)
				{
					pNew = new Monom(coef, pow, pCurr);
					pPrev->pNext = pNew;
					size++;
				}
				else
				{
					pNew = new Monom(coef, pow, pCurr);
					pHead->pNext = pNew;
					size++;
				}
			}
			else
			{
				if ((pCurr->coef += coef) != 0)
				{
					pCurr->coef += coef;
				}
				else
				{
					DelElem(1, size);
				}
			}
		}
		else
			cout << "Нулевой коэффициент" << endl;
	}
	if (num == 2)
	{
		if (coef != 0)
		{
			pPrev2 = this->pHead2;
			pCurr2 = pHead2->pNext;
			for (int i = 0; i < GetSize(num); i++)
			{
				if (pCurr2->pow > pow)
				{
					pCurr2 = pCurr2->pNext;
					pPrev2 = pPrev2->pNext;
					sch1 = 1;
				}
				if (pCurr2->pow == pow)
				{
					sch = 1;
					break;
				}
			}
			if (sch != 1)
			{
				if (sch1 == 1)
				{
					pNew2 = new Monom(coef, pow, pCurr2);
					pPrev2->pNext = pNew2;
					size2++;
				}
				else
				{
					pNew2 = new Monom(coef, pow, pCurr2);
					pHead2->pNext = pNew2;
					size2++;
				}
			}
			else
			{
				if ((pCurr2->coef += coef) != 0)
				{
					pCurr2->coef += coef;
				}
				else
				{
					DelElem(2, size2);
				}
			}
		}
		else
			cout << "Нулевой коэффициент" << endl;
	}
}
void Polinom::DelFirst(int num)
{
	if (num == 1)
	{
		tmp = pHead->pNext;
		pHead->pNext = tmp->pNext;
		tmp2 = tmp;

		delete tmp2;
		size--;
	}
	if (num == 2)
	{
		tmp2 = pHead2->pNext;
		pHead2->pNext = tmp2->pNext;
		tmp = tmp2;

		delete tmp;
		size2--;
	}
}
void Polinom::DelLast(int num)
{
	if (num == 1)
	{
		pCurr = pHead->pNext;
		while (pCurr != pHead)
		{
			pCurr = pCurr->pNext;
		}
		tmp = pCurr;

		delete tmp;
		size--;
	}
	if (num == 2)
	{
		pCurr2 = pHead2->pNext;
		while (pCurr2 != pHead2)
		{
			pCurr2 = pCurr2->pNext;
		}
		tmp = pCurr2;

		delete tmp;
		size2--;
	}
}
void Polinom::DelElem(int num, int index)
{
	if (num == 1)
	{
			pCurr = this->pHead;
			for (int i = 0; i < index - 1; i++)
			{
				pCurr = pCurr->pNext;
			}
			tmp = pCurr->pNext;
			pCurr->pNext = tmp->pNext;

			delete tmp;
			size--;
	}
	if (num == 2)
	{
			pCurr2 = this->pHead2;
			for (int i = 0; i < index - 1; i++)
			{
				pCurr2 = pCurr2->pNext;
			}
			tmp2 = pCurr2->pNext;
			pCurr2->pNext = tmp2->pNext;

			delete tmp2;
			size2--;
	}
}
void Polinom::clear(int num)
{
	if (num == 1)
	{
		while (size)
		{
			DelFirst(num);
		}
	}
	if (num == 2)
	{
		while (size2)
		{
			DelFirst(num);
		}
	}
}
void Polinom::SumPol()
{
	int sz = GetSize(1);
	int sz2 = GetSize(2);

	pPrev = this->pHead;
	pCurr = pPrev->pNext;
	pPrev2 = this->pHead2;
	pCurr2 = pPrev2->pNext;

	while(pPrev2->pNext != pHead2)
	{
		if (pCurr->pow == pCurr2->pow)
		{
			pCurr->coef += pCurr2->coef;

			DelElem(2, 1);
			size2--;

			if (pCurr->coef != 0)
			{
				pCurr = pCurr->pNext;
				pPrev2 = this->pHead2;
				pCurr2 = pPrev2->pNext;

				size++;
			}
			else
			{
				tmp = pCurr;
				pPrev->pNext = tmp->pNext;
				pCurr = tmp->pNext;
				delete tmp;
				size--;
			}
		}
		if (pCurr->pow < pCurr2->pow)
		{
			pPrev2->pNext = pCurr2->pNext;
			pPrev->pNext = pCurr2;
			pCurr2->pNext = pCurr;

			pPrev = pPrev->pNext;
			pCurr2 = pPrev2->pNext;

			size2--;
			size++;
		}
		if (pCurr->pow > pCurr2->pow)
		{
			pCurr = pCurr->pNext;
			pPrev = pPrev->pNext;
			if (pCurr->pow < pCurr2->pow)
			{
				pPrev2->pNext = pCurr2->pNext;
				pPrev->pNext = pCurr2;
				pCurr2->pNext = pCurr;

				pPrev = pPrev->pNext;
				pCurr2 = pPrev2->pNext;

				size2--;
				size++;
			}
		}
	}
}
void Polinom::DifPol()
{
	int sz = GetSize(1);
	int sz2 = GetSize(2);

	pPrev = this->pHead;
	pCurr = pPrev->pNext;
	pPrev2 = this->pHead2;
	pCurr2 = pPrev2->pNext;

	while (pPrev2->pNext != pHead2)
	{
		if (pCurr->pow == pCurr2->pow)
		{
			pCurr->coef -= pCurr2->coef;

			DelElem(2, 1);
			size2--;

			if (pCurr->coef != 0)
			{
				pCurr = pCurr->pNext;
				pPrev2 = this->pHead2;
				pCurr2 = pPrev2->pNext;

				size++;
			}
			else
			{
				tmp = pCurr;
				pPrev->pNext = tmp->pNext;
				pCurr = tmp->pNext;
				delete tmp;
				size--;
			}
		}
		if (pCurr->pow < pCurr2->pow)
		{
			pPrev2->pNext = pCurr2->pNext;
			pPrev->pNext = pCurr2;
			pCurr2->pNext = pCurr;

			pPrev = pPrev->pNext;
			pCurr2 = pPrev2->pNext;

			size2--;
			size++;
		}
		if (pCurr->pow > pCurr2->pow)
		{
			pCurr = pCurr->pNext;
			pPrev = pPrev->pNext;
			if (pCurr->pow < pCurr2->pow)
			{
				pPrev2->pNext = pCurr2->pNext;
				pPrev->pNext = pCurr2;
				pCurr2->pNext = pCurr;

				pPrev = pPrev->pNext;
				pCurr2 = pPrev2->pNext;

				size2--;
				size++;
			}
		}
	}
}
void Polinom::MultPol()
{
	int sz = GetSize(1);
	int sz2 = GetSize(2);

	pPrev = this->pHead;
	pCurr = pPrev->pNext;
	pPrev2 = this->pHead2;
	pCurr2 = pPrev2->pNext;

	while (pPrev2->pNext != pHead2)
	{
		if (pCurr->pow == pCurr2->pow)
		{
			pCurr->coef *= pCurr2->coef;

			DelElem(2, 1);

			pCurr = pCurr->pNext;
			pPrev2 = this->pHead2;
			pCurr2 = pPrev2->pNext;

			size++;
			size2--;
		}
		if (pCurr->pow < pCurr2->pow)
		{
			pPrev2->pNext = pCurr2->pNext;
			pPrev->pNext = pCurr2;
			pCurr2->pNext = pCurr;

			pPrev = pPrev->pNext;
			pCurr2 = pPrev2->pNext;

			size2--;
			size++;
		}
		if (pCurr->pow > pCurr2->pow)
		{
			pCurr = pCurr->pNext;
			pPrev = pPrev->pNext;
			if (pCurr->pow < pCurr2->pow)
			{
				pPrev2->pNext = pCurr2->pNext;
				pPrev->pNext = pCurr2;
				pCurr2->pNext = pCurr;

				pPrev = pPrev->pNext;
				pCurr2 = pPrev2->pNext;

				size2--;
				size++;
			}
		}
	}
}
void Polinom::DivPol()
{
	int sz = GetSize(1);
	int sz2 = GetSize(2);

	pPrev = this->pHead;
	pCurr = pPrev->pNext;
	pPrev2 = this->pHead2;
	pCurr2 = pPrev2->pNext;

	while (pPrev2->pNext != pHead2)
	{
		if (pCurr->pow == pCurr2->pow)
		{
			pCurr->coef /= pCurr2->coef;

			DelElem(2, 1);

			pCurr = pCurr->pNext;
			pPrev2 = this->pHead2;
			pCurr2 = pPrev2->pNext;

			size++;
			size2--;
		}
		if (pCurr->pow < pCurr2->pow)
		{
			pPrev2->pNext = pCurr2->pNext;
			pPrev->pNext = pCurr2;
			pCurr2->pNext = pCurr;

			pPrev = pPrev->pNext;
			pCurr2 = pPrev2->pNext;

			size2--;
			size++;
		}
		if (pCurr->pow > pCurr2->pow)
		{
			pCurr = pCurr->pNext;
			pPrev = pPrev->pNext;
			if (pCurr->pow < pCurr2->pow)
			{
				pPrev2->pNext = pCurr2->pNext;
				pPrev->pNext = pCurr2;
				pCurr2->pNext = pCurr;

				pPrev = pPrev->pNext;
				pCurr2 = pPrev2->pNext;

				size2--;
				size++;
			}
		}
	}
}