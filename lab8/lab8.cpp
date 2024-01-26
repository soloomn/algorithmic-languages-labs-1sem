#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<math.h>
#include<conio.h>
#include<String.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<iso646.h>
#include<fstream>
using namespace std;


//postroit dva vector kazdiy iz kotorih soderzit n elementov, nayti ugol mezdu nimi? proverit ortogonalnost, ravnost po dline, cheredovaniem elementov vectorov postroit pramoug matricu zadannogo razmera
// opredelit max otric i min polozit elemnt i ih indexi zapisat matr v fayl


int mainlab8()
{
	if (SetConsoleCP(1251) == 0)
	{
		cerr << "Fialed to set codepage!" << endl;
	}
	if (SetConsoleOutputCP(1251) == 0)
	{
		cerr << "Failed to set OUTPUT page!" << endl;
	}

	ofstream outf("outputlab8.txt");
	srand(time(NULL));
	int n, m;
	n = 1;
	register int i1, j1, i2, j2;
	cout << "������� ���������� ��������� ��������: ";
	std::cin >> m;
	int l = m * 2;

	float *vek1, **mat1, *vek2, **mat2;
	vek1 = new float[m*n]; //uk na vector kak na lin massiv
	mat1 = new float*[m]; //uk na massiv ukazateley dla obr k eltam vectora
	for (i1 = 0; i1<m; i1++) // ��������� ������ �����������
		mat1[i1] = &vek1[i1*n]; // ������� �� ������ �������
	printf("������ ������:\r\n");
	for (i1 = 0; i1 < m; i1++)
	{
		for (j1 = 0; j1 < n; j1++)
		{
			//cin >> mat1[i1][j1];
			mat1[i1][j1] = rand() % 41 - 20;
			printf("%10.2f", mat1[i1][j1]); // ����� �������� �� �����
		}
		printf("\r\n"); // ������� ������� � ������ ��������� ������
	}
	
	//--------------------------------------------------------------------------
	
	printf("-------------------------------------------------------------\n");
	vek2 = new float[m*n]; //uk na vector kak na lin massiv
	mat2 = new float*[m]; //uk na massiv ukazateley dla obr k eltam vectora
	for (i2 = 0; i2<m; i2++) // ��������� ������ �����������
		mat2[i2] = &vek2[i2*n]; // ������� �� ������ �������
	printf("������ ������:\r\n");
	for (i2 = 0; i2 < m; i2++)
	{
		for (j2 = 0; j2 < n; j2++)
		{
			//cin >> mat2[i2][j2];
			mat2[i2][j2] = rand() % 41 - 20;
			printf("%10.2f", mat2[i2][j2]); // ����� �������� �� �����
		}
		printf("\r\n"); // ������� ������� � ������ ��������� ������
	}


	//schitaem moduli vectorov
	int sum1 =0,  sum2 = 0;
	float modul1, modul2;

	for (i1 = 0; i1 < m; i1++)
	{
		for (j1 = 0; j1 < n; j1++)
		{
			sum1 = sum1 + int(mat1[i1][j1])*int(mat1[i1][j1]);
		}
	}
	modul1 = sqrt(sum1);
	cout << "������ ������� �������: " << modul1 << "\n";

	for (i2 = 0; i2 < m; i2++)
	{
		for (j2 = 0; j2 < n; j2++)
		{
			sum2 = sum2 + int(mat2[i2][j2])*int(mat2[i2][j2]);
		}
	}
	modul2 = sqrt(sum2);
	cout << "������ ������� �������: " << modul2 << "\n";

	if (modul1 == modul2)
	{
		cout << "������� ����� �� �����"<<"\n";
	}
	else 
	{
		cout << "������� �� ����� �� �����" << "\n";
	}
	//schitaem scalarnoe proizvedenie
	float scal = 0;
	for (i1 = 0; i1 < m; i1++)
	{
		for (j1 = 0; j1 < n; j1++)
		{
			scal = scal + mat1[i1][j1]*mat2[i1][j1];
		}
	}
	cout << "��������� ������������ �������� �����: " << scal << "\n";
	if (scal == 0)
	{
		cout << "������� ������������" << "\n";
	}
	else
	{
		cout << "������� �� ������������" << "\n";
	}
	//schitaem ugol mezdu vectorami
	float ugol;
	ugol = acos(scal / (modul1*modul2));
	cout << "���� ����� ��������� �����: " << ugol << " ������" << "\n";

	// sozd massiv s elementami vectorov
	int *qrr { new int[l] };
	for (i1 = 0; i1 < m; i1++)
	{
		for (j1 = 0; j1 < n; j1++)
		{
			qrr[i1] = mat1[i1][j1];
		}
	}

	for (i1 = 0; i1 < m; i1++)
	{
		for (j1 = 0; j1 < n; j1++)
		{
			qrr[(l/2)+i1] = mat2[i1][j1];
		}
	}

	//--------------------------------------------------------------------------------------
	printf("-------------------------------------------------------------\n");
	//stroim matricu iz elementov vektorov
	int m3, n3; // ���������� ����� � ��������
	register int i3, j3;
	cout << "������� ������� �������" << "\n";
	cin >> m3 >> n3;
	float *vek3, **mat3;
	vek3 = new float[m3*n3]; // �������� ����� ��� �������� ������� 
	mat3 = new float*[m3]; // �������� ����� ��� ������ ���������� �� ������ �������
	for (i3 = 0; i3<m3; i3++) // ��������� ������ �����������
		mat3[i3] = &vek3[i3*n3]; // ������� �� ������ �������
	
	int iw = 0;
	printf("���������� �������:\r\n");
	for (i3 = 0; i3 < m3; i3++)
	{
		for (j3 = 0; j3 < n3; j3++)
		{
			mat3[i3][j3] = qrr[iw];
			iw = iw + 1;
			printf("%10.2f", mat3[i3][j3]); // ����� �������� �� �����
		}
		printf("\r\n"); // ������� ������� � ������ ��������� ������
	}
	
	//opr min polozh i max otric elementi
	float minpol, maxotr;
	int indmp1, indmp2, indmo1, indmo2;
	minpol = 1000;
	maxotr = -1;
	indmp1 = 1;
	indmp2 = 1;
	indmo1 = 1;
	indmo2 = 2;
	bool flag1 = FALSE;
	for (i3 = 0; i3 < m3; i3++)
	{
		for (j3 = 0; j3 < n3; j3++)
		{
			if (mat3[i3][j3]>0 && mat3[i3][j3] < minpol)
			{
				minpol = mat3[i3][j3];
				indmp1 = i3+1;
				indmp2 = j3+1;
			}
			if (mat3[i3][j3] < 0 && mat3[i3][j3] < maxotr)
			{
				maxotr = mat3[i3][j3];
				indmo1 = i3+1;
				indmo2 = j3+1;
				flag1 = TRUE;
			}
		}
	}

	if ((minpol < 0) or (minpol == 1000))
	{
		cout << "������������� ��������� ���" << "\n";
	}
	else
	{
		cout << "����������� ������������� ������� �������: " << minpol << " ��� �������: " << indmp1 << " " <<indmp2 << "\n";
	}

	if ((maxotr > 0) or (flag1 == FALSE)) 
	{
		cout << "������������� ��������� ���" << "\n";
	}
	else
	{
		cout << "������������ ������������� ������� �������: " << maxotr << " ��� �������: " << indmo1 << " " << indmo2 << "\n";
	}


	//----------------------------------------------------------------------------
	//zapisivaem metricu v fayl

	for (i3 = 0; i3<m3; i3++)
	{
		for (j3 = 0; j3<n3; j3++)
		{
			// ������ �������� � ����:
			outf << setiosflags(ios::showpoint) << setprecision(2) << setw(10) << mat3[i3][j3];
			// ����� �� �����:
			//cout << setiosflags(ios::showpoint) << setprecision(2) << setw(10) << mat3[i3][j3];
			// ������ ������� ������������ � ����� ������� ����� ����� � ���� �� 8 �������
		}
		outf << endl;
		// � ����� ������ ������� ������� ������� ����� ������
		cout << endl;
	}
	outf.close();

	cin >> n;
	return 0;
}