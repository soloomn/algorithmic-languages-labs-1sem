#include<iostream>	
#include<math.h>
#include<conio.h>
#include<String.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<fstream> // this directive provides work with files
using namespace std;

/* if both main program and functions work with the file, it is better to declare it as a global variable*/
ifstream file("usageforlab6.txt");

int mainlab6()
{
	float sum, n;
	if (!file) // check if the file exists
	{
		cerr << "The file usagefrolab6.txt does not exist\n";
		return 0;
	}
	int k = 0; // number of numbers in the file


	while (1) // sort of an endless cycle
	{
		file >> n;
		if (file.eof()) break;
		// if the end of the file is reached, exit the loop
		if (!k) // if the first number is read (k=0)
		{
			sum = n;
		}
		else // if the number isn't the first
		{
			sum = sum + n;
		}
		cout << n << ' '; k++;
		/* display the read number on the screen and increment the counter of read numbers */
	}

	sum = sum / k;
	cout << '\n';
	cout << "Arithmetic mean of array elements = " << sum;
	_getch(); //the standard windows terminal sometimes closes automatically after code execution, with the empty command "_getch()"
	//let's put it in "standby mode" before entering any character via <Enter> (if you use the standard MS VS Code terminal, this command can be removed)
	return 0;
}