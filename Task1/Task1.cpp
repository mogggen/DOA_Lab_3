#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	char arr[] = "this is a string";
	char *ptr = arr;
	int i = 0;
	for (; *(ptr + i) != '\0'; i++);
	cout << i;
}