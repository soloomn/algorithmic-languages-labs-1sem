#include<iostream>
#include<iomanip>
#include<cmath>
#include <cstdlib>
#include<windows.h>
#include <ctime>
#include <fstream>
#include <conio.h>
#include <iso646.h>
using namespace std;


//postroit dva vector kazdiy iz kotorih soderzit n elementov, nayti ugol mezdu nimi? proverit ortogonalnost, ravnost po dline, cheredovaniem elementov vectorov postroit pramoug matricu zadannogo razmera
// opredelit max otric i min polozit elemnt i ih indexi zapisat matr v fayl


int main()
{
    ofstream outf("outputlab8.txt");
    srand(time(nullptr)); // required to initialize a pseudo-random numeric sequence
    // each time after the program start a unique upper limit of the "rand()" function is specified
    int n, m, i1, j1, i2, j2;
    n = 1;
    cout << "enter the number of elements of vectors: ";
    cin >> m;
    int l = m * 2;

    float *vek1, **mat1, *vek2, **mat2;
    vek1 = new float[m*n]; // pointer to a vector as a linear array
    mat1 = new float*[m]; // pointer to pointer array for accessing vector elements
    for (i1 = 0; i1<m; i1++) // fill the array with pointers
        mat1[i1] = &vek1[i1*n]; // division by matrix rows
    cout << "first vector: " << endl;
    for (i1 = 0; i1 < m; i1++)
    {
        for (j1 = 0; j1 < n; j1++)
        {
            mat1[i1][j1] = rand() % 41 - 20; // here we fill the vector with random numbers from -20 to 20
            cout << mat1[i1][j1] << " ";
        }
        cout << endl; // move the cursor to the beginning of the next line
    }

    cout << "-------------------------------------------------------------" << endl;

    vek2 = new float[m*n]; // pointer to a vector as a linear array
    mat2 = new float*[m]; // pointer to pointer array for accessing vector elements
    for (i2 = 0; i2<m; i2++) // fill the array with pointers
        mat2[i2] = &vek2[i2*n]; // division by matrix rows
    cout << "second vector: " << endl;
    for (i2 = 0; i2 < m; i2++)
    {
        for (j2 = 0; j2 < n; j2++)
        {
            mat2[i2][j2] = rand() % 41 - 20; // here we fill the vector with random numbers from -20 to 20
            cout << mat2[i2][j2] << " ";
        }
        cout << endl; // move the cursor to the beginning of the next line
    }

    cout << "-------------------------------------------------------------" << endl;

    //--------------------------------------------------------------------------

    // calculate the modulus of the vectors
    int sum1 = 0,  sum2 = 0;
    float modul1, modul2;

    for (i1 = 0; i1 < m; i1++)
    {
        for (j1 = 0; j1 < n; j1++)
        {
            sum1 = sum1 + int(mat1[i1][j1]) * int(mat1[i1][j1]);
        }
    }
    modul1 = sqrt(sum1);
    cout << "modulus of the first vector: " << modul1 << endl;

    for (i2 = 0; i2 < m; i2++)
    {
        for (j2 = 0; j2 < n; j2++)
        {
            sum2 = sum2 + int(mat2[i2][j2]) * int(mat2[i2][j2]);
        }
    }
    modul2 = sqrt(sum2);
    cout << "modulus of the second vector: " << modul2 << endl;

    if (modul1 == modul2)
    {
        cout << "vectors are equal in length" << endl;
    }
    else
    {
        cout << "vectors are not equal in length" << endl;
    }

    //--------------------------------------------------------------------------

    // calculate the scalar product of vectors and check their orthogonality
    float scal = 0;
    for (i1 = 0; i1 < m; i1++)
    {
        for (j1 = 0; j1 < n; j1++)
        {
            scal = scal + mat1[i1][j1]*mat2[i1][j1];
        }
    }
    cout << "the scalar product of vectors: " << scal << endl;
    if (scal == 0)
    {
        cout << "vectors are orthogonal" << endl;
    }
    else
    {
        cout << "vectors are not orthogonal" << endl;
    }
    
    //--------------------------------------------------------------------------
    
    // calculate the angle between the vectors
    float ugol;
    ugol = acos(scal / (modul1*modul2));
    cout << "the angle between the vectors is: " << ugol << " radians" << endl;

    //--------------------------------------------------------------------------

    // create an array with vector elements for the matrix constructor
    int *qrr {new int[l]};
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
    free(mat1);
    free(mat2);
    
    cout << "the angle between the vectors is: " << ugol << " radians" << endl;

    //--------------------------------------------------------------------------

    //stroim matricu iz elementov vektorov
    int m3, n3; // Количество строк и столбцов
    int i3, j3;
    cout << "задайте размеры матрицы" << "\n";
    cin >> m3 >> n3;
    float *vek3, **mat3;
    vek3 = new float[m3*n3]; // выделяем место под элементы матрицы
    mat3 = new float*[m3]; // выделяем место под массив указателей на строки матрицы
    for (i3 = 0; i3<m3; i3++) // заполняем массив указателями
        mat3[i3] = &vek3[i3*n3]; // деление на строки матрицы

    int iw = 0;
    printf("Полученная матрица:\r\n");
    for (i3 = 0; i3 < m3; i3++)
    {
        for (j3 = 0; j3 < n3; j3++)
        {
            mat3[i3][j3] = qrr[iw];
            iw = iw + 1;
            printf("%10.2f", mat3[i3][j3]); // вывод элемента на экран
        }
        printf("\r\n"); // перевод курсора в начало следующей строки
    }
    free(qrr);
    
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
        cout << "положительных элементов нет" << "\n";
    }
    else
    {
        cout << "минимальный положительный элемент матрицы: " << minpol << " его индексы: " << indmp1 << " " <<indmp2 << "\n";
    }

    if ((maxotr > 0) or (flag1 == FALSE))
    {
        cout << "отрицательных элементов нет" << "\n";
    }
    else
    {
        cout << "максимальный отрицательный элемент матрицы: " << maxotr << " его индексы: " << indmo1 << " " << indmo2 << "\n";
    }


    //----------------------------------------------------------------------------
    //zapisivaem metricu v fayl

    for (i3 = 0; i3<m3; i3++)
    {
        for (j3 = 0; j3<n3; j3++)
        {
            // запись элемента в файл:
            outf << setiosflags(ios::showpoint) << setprecision(2) << setw(10) << mat3[i3][j3];
            // вывод на экран:
            //cout << setiosflags(ios::showpoint) << setprecision(2) << setw(10) << mat3[i3][j3];
            // каждый элемент записывается с двумя цифрами после точки в поле из 8 позиций
        }
        outf << endl;
        // в конце строки матрицы выводим признак конца строки
        cout << endl;
    }
    outf.close();
    free(vek1);
    free(vek2);
    free(vek3);
    free(mat3);
    _getch(); //the standard windows terminal sometimes closes automatically after code execution, with the empty command "_getch()"
	//let's put it in "standby mode" before entering any character via <Enter> (if you use the standard MS VS Code terminal, this command can be removed)
    return 0;
}