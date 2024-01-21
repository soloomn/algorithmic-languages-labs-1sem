#include<iostream>	
#include<windows.h>
#include<iomanip>
#include<math.h>
#include<conio.h>
#include<String.h>
#include<ctype.h>
#include <stdlib.h>
#include <fstream> // ���� ���� ������������ ������ � �������
using namespace std;
//11.	������� ����, ��� �������� �������� � ����������. ���������� � ����� ���� ������ �� �����, ������� ������� �� ����.
int mainlab5()
{
	if (SetConsoleCP(1251) == 0)
	{
		cerr << "Fialed to set codepage!" << endl;
	}
	if (SetConsoleOutputCP(1251) == 0)
	{
		cerr << "Failed to set OUTPUT page!" << endl;
	}
	ifstream ifl; // ��������� ���� ��� ������
	ofstream out; //���� ��� ������
	out.open("results.txt");
	char ch;
	char name[20]; // ��� �����
	do /* ����, ������� ��������� ���� ����� ����� �� ��� ���, ���� ��� �� �����   ������ ��������� */
	{
		int i = 0; // ������� ��������
		cout << "������� ��� �����: ";
		while ((ch = _getche()) != '\r') /* ������������ ������ ����� �������� �������� ���� � ����� ������ ��� ������� ������� <Esc> (�������, ��� �� �����������) */
		{
			if (ch == 27) exit(0);
			else name[i++] = ch;
		}
		cout << "\n";
		name[i] = '\0';
		ifl.open(name, ios::in); // �������� ������� ����
	} while (!ifl); // ���� ���� �� ������
	if (ifl) // ���� ���� ������, ��������� �������� ��������:
	{
		char val; // ������, ����������� �� �����
		while (!ifl.eof()) // ���� �� ����� �����
		{
			val = ifl.get(); // ��������� 1 ������
			int num = val;
			if ((num >= 48) && (num <= 57)) //���������� ����������� ������� ����� ascii
			{
				if (out.is_open())
				{
					out << val;
				}
			}
			}
		}

	out.close();
	_getch();//the standard windows terminal sometimes closes automatically after code execution, with the empty command "_getch()"
	//let's put it in "standby mode" before entering any character via <Enter> (if you use the standard MS VS Code terminal, this command can be removed)
	return 0;
	}