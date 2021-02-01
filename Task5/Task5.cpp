#include "pch.h"
#include <iostream>

using namespace std;

void replace_chars(char *str, char search, char replace)
{
	for (int i = 0; *(str + i) != '\000'; i++)
	{
		if (*(str + i) == search) *(str + i) = replace;
	}
}

int main()
{
	char search = 'a';
	char replace = '*';
	char str[] = "hast al la vista baby!";
	cout << str << endl;
	replace_chars(str, search, replace);
	cout << str << endl;
}