#include "pch.h"
#include <iostream>

using namespace std;

void swap_sort(int **a, int **b, int **c, bool order)
{
	int temp;
	for (int i = 0; i < 2; i++)
		if (order)
		{
			if (b < a)
			{
				temp = **a;
				**a = **b;
				**b = temp;
			}
			if (**c < **b)
			{
				temp = **b;
				**b = **c;
				**c = temp;
			}
		}
		else
		{
			if (**c > **b)
			{
				temp = **b;
				**b = **c;
				**c = temp;
			}
			if (**b > **a)
			{
				temp = **a;
				**a = **b;
				**b = temp;
			}
		}
}

int main()
{
	while (true)
	{
		int a, b, c;
		int *ptrA = &a, *ptrB = &b, *ptrC = &c;
		bool order;

		cout << "give a (or 0 to quit): ";
		cin >> a;
		if (a == 0) break;
		cout << "give b: ";
		cin >> b;
		cout << "give c: ";
		cin >> c;
		cout << "sort in order (1)ascending / (0)descending: ";
		cin >> order;

		swap_sort(&ptrA, &ptrB, &ptrC, order);
		cout << *ptrA << "," << *ptrB << "," << *ptrC << endl;
	}
	cout << "Bye bye!" << endl;
}