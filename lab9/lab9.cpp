#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<string>
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
// due to the fact that the "rand()" function has a different upper bound each time
// the sequence generated within the given limits will always be considered pseudorandom

bool checkprime(int a) // this function checks the divisibility of a given number 
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
// for optimization purposes the loop is executed only up to the number numerically equal to the next natural number
// after the square root of the given number
// it is clear that from the point of view of Number Theory such a simplification of the enumeration (cycle) is optimal 
// since it can be considered that if A has non-trivial divisors except 1 and A then at least one of them belongs to the segment [2; sqrt(|A|)]

bool checkpal(string word) // this function checks the received number for a palindrome
{
    int len = word.length();
    for (int j = 0; j < len / 2; j++)
    {
        if (word[j] != word[len - j - 1])
            return false;
    }
    return true;
}
// the function gets a given number turned into a string and checks if the elements standing on
// the same places from different ends of the word match

int mainlab9()
{
    cout << "enter the array capacity\n";
    int n, max, min, sch, flag, l;
    // array initialization
    srand(time(NULL)); // required to initialize a pseudo-random numeric sequence
    // each time after the program start a unique upper limit of the "rand()" function is specified
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

    //! prime numbers
    sch = 0; // zero the meter
    cout << "prime numbers: ";
    for (int i = 0; i < n; i++)
    {
        if (checkprime(a[i]) == false) 
        {
            sch++; // if the function finds no divisors (return false), the counter is triggered
            cout << a[i] << " ";
        }
    }
    cout << endl;
    cout << "all prime numbers: " << sch << endl;

    //! palindromes
    sch = 0; //zero the meter
    cout << "palindromes: ";
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) >= 10)
        {
            if (checkpal(to_string(a[i])))
            {
                cout << a[i] << " ";
                sch++;
            }
        }
    }
    cout << endl << "all palindromes: " << sch << endl;

    //! multiples of the entered number
    cout << "enter a number to check the multiplicity" << endl;
    cin >> l;
    sch = 0; // zero the meter
    cout << "multiples: ";
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            if ((a[i] % l) == 0)
            {
                cout << a[i] << " ";
                sch++;
            }
        }
    }
    cout << endl << "total multiples: " << sch << endl;

    _getch(); //the standard windows terminal sometimes closes automatically after code execution, with the empty command "_getch()"
	//let's put it in "standby mode" before entering any character via <Enter> (if you use the standard MS VS Code terminal, this command can be removed)
    return 0;
}