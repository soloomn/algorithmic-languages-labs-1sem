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
	// ���� ����� ������������ �������� �������� ���� �� ������ bin
	strcpy_s(zero, "0"); // ���������� ���� � ������ ������
	cout << "������� 2-�� �����: \n";
	while ((ch = _getch()) != '\r') // ���� �� ������ ������� <Enter>
	{
		if ((ch == '0' || ch == '1' || ch == '2') && k < 79) // ���� ������� 2-� �����
		{
			cout << ch; triple[k++] = ch;
			// ������� �� �� ����� � ���������� � ������
		}
	}  //end while
	triple[k] = 0; enea[n] = 0; cout << endl;
	//������ ����� ������ ������� 4:
	while (strlen(triple) % 2)
	{
		strcpy(triple, strcat(zero, triple)); /* ���������� ������, ���������� �0�, � bin, ����� ���������� ����� �������� � bin, � ���������� � ������ bin ����������� �0� */
		strcpy(zero, "0");  /* ��������������� zero, ��� ������ ��������� ������ 1 ����*/
	}
	cout << triple << endl; // ��������, ��� ����������
	// �������:
	TableString table[16] = { { '0', "0" },  /* �������� �������� �� ��, ��� ������// ���������� ������ �������� */
	{ '1', "01" },
	{ '2', "02" },
	{ '3', "10" },
	{ '4', "11" },
	{ '5', "12" },
	{ '6', "20" },
	{ '7', "21" },
	{ '8', "22" } };
	// �������� �� 2-�� �����, ����������� �� 4 �����:	
	for (int i = 0; i<strlen(triple); i += 2)
	{
		strncpy(tmp, triple + i, 2); // �������� ��������� 4 ����� � tmp
		tmp[2] = '\0';   // strncpy() ������� ����� ������ �� ����������
		for (int j = 0; j<9; j++) //  ��������� ����� � �������
			if (!strcmp(table[j].triple, tmp)) // ���� strcmp() ������� 0, ������ tmp ������� � i-�� ������� �������
			{
				enea[n++] = table[j].enea;/* �������� 16-� ����� �� ������� � ������ hex */
				break;
			}
	}
	
	enea[n] = '\0';
	cout << "��������������� 16-�� ����� = \n";
	cout << enea << endl;
	_getch(); //the standard windows terminal sometimes closes automatically after code execution, with the empty command "_getch()"
	//let's put it in "standby mode" before entering any character via "enter"
	return 0;
}