#include "pch.h"
#include <iostream>

using namespace std;

float average_salary(float *arr, int employees)
{
	float sum = 0;
	for (int i = 0; i < employees; i++)
		sum += arr[i];
	return sum / employees;
}

int main()
{
	int employees;
	cout << "How many Employees: ";
	cin >> employees;
	float *salaries = new float[employees];
	for (int i = 0; i < employees; i++)
	{
		cin >> salaries[i];
		cout << "salaries remaining: " << employees - i - 1 << endl;
	}
	cout << "average: " << average_salary(salaries, employees);
}