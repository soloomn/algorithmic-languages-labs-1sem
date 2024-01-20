#define _CRT_SECURE_NO_WARNINGS
#include <iostream>	
#include <iomanip>
#include <math.h>
#include <conio.h>
#include <string>
#include <ctype.h>
#include <windows.h>
using namespace std;

//11. Write a programme that converts a number from ternary number system to nine-digit(nonary) number system 
//without converting the integer to decimal number system

//for the program operation we will use the principle of bit-by-bit coding: we will receive a ternary number and divide it into twos 
//(it is clear that any nonary digit can be encoded using two ternary digits; [for understanding you can read the theory of coding according
// to Fano's condition]), we will create a structure that will contain the translation of any ternary two into a nonary digit, using such a structure

struct TableString
{
	char enea; //nonary digit
	char triple[5];
	//a string containing two ternary digits (the string ends with '\0')
};

int mainlab4()
{
	char ch;   //is used for character-by-character input
	int  n = 0, k = 0;  // character counters
	char enea[21]; //nonary number
	char triple[81]; // ternary number
	char zero[81];  //a line at the beginning of which '0' will be written
	char tmp[5];
	// the two ternary digits from the "triple" string will be copied here
	strcpy_s(zero, "0"); // write zero at the beginning of the line
	cout << "Enter a ternary number: \n";
	while ((ch = _getch()) != '\r') // when the <Enter> key is not pressed
	{
		if ((ch == '0' || ch == '1' || ch == '2') && k < 79) // if a ternary digit is entered
		{
			cout << ch; triple[k++] = ch;
			// display it on the screen and write it to a string
		}
	}
	triple[k] = 0; enea[n] = 0; cout << endl;
	//make the line length divisible by 2:
	while (strlen(triple) % 2)
	{
		strcpy(triple, strcat(zero, triple)); /* add the string containing '0' to "triple", then copy the sum to "triple", as a result '0' is added to the beginning of "triple".*/
		strcpy(zero, "0");  /* restore "zero", it must contain only 1 zero */
	}
	cout << triple << endl; // let's see what we got
	// Translation:
	TableString table[16] = { { '0', "00" },  /* note how the array of structures is initialized */
	{ '1', "01" },
	{ '2', "02" },
	{ '3', "10" },
	{ '4', "11" },
	{ '5', "12" },
	{ '6', "20" },
	{ '7', "21" },
	{ '8', "22" } };
	// pass through the ternary number, processing two digits at a time:	
	for (int i = 0; i<strlen(triple); i += 2)
	{
		strncpy(tmp, triple + i, 2); // copy the next two digits to "tmp"
		tmp[2] = '\0';   // strncpy() end of string sign - no writing will be done
		for (int j = 0; j<9; j++) //  search the table
			if (!strcmp(table[j].triple, tmp)) // if strcmp() returns 0, then "tmp" matches the i-th row of the table
			{
				enea[n++] = table[j].enea;/* copy the nonary digit from the table to the "hex" string */
				break;
			}
	}
	
	enea[n] = '\0';
	cout << "The corresponding nonary number =\n";
	cout << enea << endl;
	_getch(); //the standard windows terminal sometimes closes automatically after code execution, with the empty command "_getch()"
	//let's put it in "standby mode" before entering any character via <Enter> (if you use the standard MS VS Code terminal, this command can be removed)
	return 0;
}