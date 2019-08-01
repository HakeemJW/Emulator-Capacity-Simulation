// C++ Program			Project 4.cpp
// Course				CSE1311/W01
// Name:				Hakeem Wilson
// Assignment #:		Project 4
// Due Date:			4/27/2019

/*
	The purpose of this program isto simulate an elevator with a limit of 1100 lbs,
	the program has a string of names and an array of values,
	the program must add people to the elvator and stop before the maximum limit is passed,
	it must do this once, the sort the weights in descending order and repeat,
	then again in ascending order instead, then it must determine which run was the most efficient.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Ascending Sort Function
void ascsort(string names[], int w[], int n)
{
	int f;
	string s;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (names[i] > names[j])
			{
				s = names[i];
				names[i] = names[j];
				names[j] = s;
				f = w[i];
				w[i] = w[j];
				w[j] = f;
			}
		}
	}
}

//Descending Sort Function
void descsort(string names[], int w[], int n)
{
	int f, max = 0;
	string s;
	for (int i = 0; i < n; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (w[j] > w[max])
			{
				max = j;
			}
		}
		f = w[i];
		w[i] = w[max];
		w[max] = f;
		s = names[i];
		names[i] = names[max];
		names[max] = s;
	}
}

//Array Printing Function
void print(string names[], int w[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << names[i] << "\t" << w[i] << endl;
	}
}

//Function to calculate how many people will be on the elevator.
int goe(string names[], int w[], int n)
{
	int sum = 0, x = 0, max = 1100;
	cout << "\n\nPeople who can get on the elevator \n\n";
	for (int i = 0; i < n; i++)
	{
		sum + w[i];
		if (sum + w[i] <= max)
		{
			sum += w[i];
			cout << names[i] << "\t" << w[i] << endl;
			x++;
		}
	}
	cout << "Number of People: " << x << "\nTotal Weight: " << sum << endl;
	return x;
}

int main()
{
	//Local Declarations
	int n = 12;
	int p = 0, i = 1, x = 0;
	string names[] = { "Anne","Bob","Ralph","Tim","Barbara","Jane","Steve","Tom","Mike","Shirley","Pam","Frank" };
	int weights[] = { 30,150,305,225,135,160,80,200,165,90,100,120 };

	//Pre-Sort Run
	cout << "No Order \n\n";
	print(names, weights, n);
	p = goe(names, weights, n);
	cout << "==================================================" << endl;

	//Descending Order Run
	cout << "\nDescending order \n";
	descsort(names, weights, n);
	print(names, weights, n);
	x = goe(names, weights, n);
	if (x > p)
	{
		p = x;
		i = 2;
	}
	cout << "==================================================" << endl;

	//Ascending Order Run
	cout << "\nAscending order \n";
	ascsort(names, weights, n);
	print(names, weights, n);
	x = goe(names, weights, n);
	if (x > p)
	{
		p = x;
		i = 3;
	}
	cout << "\nMax number of people rode the elevator on trip " << i << " with " << p << " people on elevator.\n\n";
	cout << "This program was coded by Hakeem Wilson\n";
	system("PAUSE");
	return 0;
}
