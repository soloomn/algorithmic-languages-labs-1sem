#include <iostream>
#include <math.h>
#include <conio.h>
#include <windows.h>
using namespace std;

//11. Write a programme that calculates 1/(sqrt(x)), using the recurrence relation: with a given accuracy.
//Display the control value on the screen.
//The given recurrence relation can be viewed in the file "forlab2.png"


int main()
{
    //the selected code block is used to output Cyrillic characters to the console
    //here and further Cyrillic output will be commented out, if necessary you can choose one of two options: English or Russian
    //---------------------------------------------------------
	if (SetConsoleCP(1251) == 0)
	{
		cerr << "Fialed to set codepage!" << endl;
	}
	if (SetConsoleOutputCP(1251) == 0)//same for output
	{
		cerr << "Failed to set OUTPUT page!" << endl;
	}
    //---------------------------------------------------------
	do
    {
		double x, eps;
		float w1, w2; //w1&w2 working solutions x - undersqrt solution
        //cout << "программа вычисляет 1/sqrt(x), используя рекуррентное соотношение с заданной точностью\n";
		cout << "the programme calculates 1/sqrt(x) using a recurrence relation with a given accuracy\n";

		do
		{
			//cout << "введите число x>0\n";
            cout << "enter the number x > 0\n";
			cin >> x;
		} while (x < 0);

		do
		{
			//cout << "введите точность >0 и <1\n"; 
            cout << "enter precision > 0 and < 1\n";
			cin >> eps;
		} while (eps <= 0 || eps >= 1); //it is required to check the permissible accuracy limits, if they are exceeded - the programme will not be executed
		w2 = x / 2;
		do
		{
			w1 = w2;
			w2 = 0.5*((1 / (x*w1)) + w1);
		} while (fabs(w2 - w1) >= eps);
		//cout << "Вычисленное значение " << w2 << endl; 
		//cout << "контрольное значение " << 1 / sqrt(x) << endl;
        cout << "calculated value " << w2 << endl; 
		cout << "control value " << 1 / sqrt(x) << endl; //here we compare the calculated and the control value to understand that the algorithm and the given recurrence relation are correct
	} while (_getch()!=27);
	return 0;
}