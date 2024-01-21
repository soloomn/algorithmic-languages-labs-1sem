#include<iostream>	
#include<windows.h>
#include<iomanip>
#include<conio.h>
#include<ctype.h>
#include <stdlib.h>
#include <fstream> // this directive provides work with files
using namespace std;

int main()
{
	ifstream ifl; // declare a file for reading
	ofstream out; // file for writing
	out.open("resultslab5.txt"); //default file name for output (the file will be created by itself if there is no such file in the project folder; the name can be changed to any convenient one)
	byte flag = 0;
	char ch;
	char name[20]{}; // file name (the folder already contains the required working file named "usageforlab5.txt", edit it or create your own with any name you want)
	do /*a loop that repeats typing the filename until it is correctly specified */
	{
		int i = 0; // character counter
		cout << "Set the file name: ";
		while ((ch = _getche()) != '\r') /* The character-by-character reading of the name will allow you to break the loop at any time by pressing the <Esc> key (of course, this is not necessary) */
		{
			if (ch == 27) exit(0);
			else name[i++] = ch;
		}
		cout << "\n";
		name[i] = '\0';
		ifl.open(name, ios::in); // trying to open the file
	} while (!ifl); // while the file is open
	if (ifl) // if the file is open, perform basic actions:
	{
		char val; // character to be read from the file
		while (!ifl.eof()) // until the file ends
		{
			val = ifl.get(); // read 1 character
			int num = val;
			if ((num >= 48) && (num <= 57)) // use a standard translation through ascii
			{
				if (out.is_open())
				{
					out << val;
				}
			}
		}
		flag = 1;
		cout << "writing completed";
	}
	out.close();
	if (flag == 0)
		cout << "writing errors occurred, please try again";
	_getch(); //the standard windows terminal sometimes closes automatically after code execution, with the empty command "_getch()"
	//let's put it in "standby mode" before entering any character via <Enter> (if you use the standard MS VS Code terminal, this command can be removed)
	return 0;
}