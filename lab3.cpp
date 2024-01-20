#include <iostream>
#include <math.h>
#include <conio.h>
#include <windows.h>
using namespace std;
//11.	Write a programme that finds all numbers on a given segment that are squares of natural numbers and displays them on the screen. 
//Check "square - not square" in the form of a function.

//ATTENTION here and further Cyrillic output will be removed and replaced by English output only, to use the output in Russian please
//refer to the files of laboratory work No. 2 and paste the highlighted part of the code from there 

byte SqrtOrNot(double i)
{
	double a = i;
	byte flag = 0;
	if (sqrt(a) == (long long)sqrt(i))
	{
		flag = 1;
	}
	return flag;
} 
//check for "square - not square" is implemented by comparing integer type with floating point type - the condition 
//"square of a natural number" will be fulfilled only if they are completely equal.

int main()
{
	int a;
	double i, n, m;
	byte flag = 0; 
	//for a working variable we can use either "bool" format (values "True" or "False") or "byte" format (_EXPORT_STD enum class byte : unsigned char)
	cout << "enter first the beginning of the interval and then the end of the interval\n";
	cin >> n >> m;
	for (i = n; i <= m; i++)
	{
		if (SqrtOrNot(i))
		{
			if (!flag)
			{
				cout << "the squares have been found:\n";
			}

			flag = 1;
			cout << i << " ";
		}
	}
	if (!flag) 
		cout << "This segment doesn't have the right numbers on it\n";
	cin >> a;
	return 0;
}