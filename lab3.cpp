#include <iostream>
#include <math.h>
#include <conio.h>
#include <windows.h>
using namespace std;
//11.	�������� ���������, ������� �� �������� ������� ������� ��� �����, ������������ ���������� ����������� �����, � ������� �� �� �����. 
//�������� "������� � �� �������" �������� � ���� �������.

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
int mainlab3()
{
	if (SetConsoleCP(1251) == 0)
	{
		cerr << "Fialed to set codepage!" << endl;
	}
	if (SetConsoleOutputCP(1251) == 0)//���� ����� ��� ������
	{
		cerr << "Failed to set OUTPUT page!" << endl;
	}
	int a;
	double i, n, m;
	byte flag = 0;
	cout << "������� ������� ������ ���������� � ����� ��� �����\n";
	cin >> n;
	cin >> m;
	for (i = n; i <= m; i++)
	{
		if (SqrtOrNot(i))
		{
			if (!flag)
			{
				cout << "�������� �������:\n";
			}

			flag = 1;
			cout << i << " ";
		}
		if (!flag) {
			cout << "�� ���� ������� ��� ������ �����\n";
			break;
		}
	}
	cin >> a;
	return 0;
}
