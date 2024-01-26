#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<iso646.h>
using namespace std;

int rand(int max, int min) // the function generates random numbers from the range [min, max]
{
    return rand() % (max - min + 1) + min;
}

bool checkprime(int a)
{
    bool flag;
    flag = false;
    for (int i = 2; i < sqrt(abs(a)) + 1; i ++)
    {
        if (a % i == 0)
        {
            flag = true;
        }
    }
    return flag;
}

bool checkpal(string word)
{
    int len = word.length();
    for (int j = 0; j < len / 2; j++)
    {
        if (word[j] != word[len - j - 1])
            return false;
    }
    return true;
}

int main()
{
    cout << "enter the array capacity\n";
    int n, max, min, sch, flag, l;
    // array initialization
    srand(time(NULL)); // required to initialize a pseudo-random numeric sequence
    cin >> n;
    cout << "set the range of values: first the maximum element, then the minimum element\n";
    cin >> max;
    cin >> min;
    int *a = new int[n];
    cout << "resulting array:\n";
    // fill the array with random numbers and display it on the screen
    for (int i = 0; i < n; i++)
    {
        a[i] = rand(max, min);
        cout << setw(4) << a[i]; // display the array element (output field width - 4)
    }
    cout << endl;

    // let's find the given numbers
    // prime numbers
    sch = 0; //zero the meter
    cout << "prime numbers: ";
    for (int i = 0; i < n; i++)
    {
        if (checkprime(a[i]) == false)
        {
            sch = sch + 1;
            cout << a[i] << " ";
        }
    }
    cout << endl;
    cout << "all prime numbers: " << sch;
    cout << endl;


    _getch(); //the standard windows terminal sometimes closes automatically after code execution, with the empty command "_getch()"
	//let's put it in "standby mode" before entering any character via <Enter> (if you use the standard MS VS Code terminal, this command can be removed)
    return 0;
}