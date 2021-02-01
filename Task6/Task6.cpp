#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void Initialise_database(vector<string> *vect) 
{
	bool certain;
	cout << "are you sure?\n1: yes\n0: no\n";
	cin >> certain;
	if (certain)
		(*vect).clear();
}

void Insert(vector<string> *vect)
{
	string name;
	cout << "enter a name (q/Q to stop): ";
	while (true)
	{

		cin >> name;
		if (name != "Q" && name != "q")
			(*vect).push_back(name);
		else
			break;
	}
}

void Search(const vector<string> *vect)
{
	cout << "Search for a name (or parts of it): ";
	string search;
	cin >> search;
	for (unsigned j = 0; j < (*vect).size(); j++)
	{
		for (unsigned i = 0; i < (*vect)[j].length() - search.length() + 1; i++)
		{
			if ((*vect)[j].substr(i, search.length()) == search)
			{
				cout << (*vect)[j] << endl;
				break;
			}
		}
	}
}

void Delete(vector<string> *vect)
{
	string del;
	cin >> del;
	int first = (*vect).size();
	for (unsigned i = 0; i < (*vect).size(); i++)
		if ((*vect)[i] == del) (*vect).erase((*vect).begin() + i);
	if ((*vect).size() == first)
		cout << "Name not found!" << endl;
}

void Print(const vector<string> *vect)
{
	for (unsigned i = 0; i < (*vect).size(); i++)
		cout << (*vect)[i] << endl;
}

void Save(const vector<string> *vect)
{
	string fileName;
	ofstream myfile;
	cout << "name your savefile: ";
	cin >> fileName;
	myfile.open(fileName);
	for (unsigned i = 0; i < (*vect).size(); i++)
	{
		myfile << (*vect)[i] << endl;
	}
	myfile.close();
}

void Load(vector<string> *vect)
{
	(*vect).clear();
	string fileName;
	ifstream myFile;
	cout << "fileName: ";
	cin >> fileName;
	myFile.open(fileName);
	if (myFile.fail())
	{
		cout << "File \"" << fileName << "\" not Found!" << endl;
		return;
	}

	string contents;
	while (myFile >> contents)
	{
		(*vect).push_back(contents);
	}
	myFile.close();
}

int main()
{
	char choise;
	vector<string> vect;
	vector<string> *ptr = &vect;

	while (true)
	{
		cout << "Menu:\n1. initialise database\n2. insert\n3. search\n4. delete\n5. print\n6. save\n7. load\n8. quit\n";
		cout << "Make your choice: ";
		cin >> choise;

		switch (choise)
		{
		case '1':
			Initialise_database(ptr);
			break;

		case '2':
			Insert(ptr);
			break;

		case '3':
		{
			Search(ptr);
			break;
		}

		case '4':
		{
			Delete(ptr);
			break;
		}

		case '5':
			Print(ptr);
			break;

		case '6':
			Save(ptr);
			break;

		case '7':
			Load(ptr);
			break;

		case '8':
			cout << "Exiting Program...";
			return 0;

		default:
			cout << "please enter a number between 1-8 as a choise.";
		}
	}
}