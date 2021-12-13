// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------

void main()
{
  /*TMatrix<int> a(5), b(5), c(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления треугольных матриц"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;
  TMatrix<int> d((c-b));
  cout << "Matrix (d = a + b - b) == a" << endl << (d == a) << endl;
  cout << "Matrix b + a - a - b" << endl << b + a - a - b << endl;
  cout << "Matrix d != (b + a - a - b)" << endl << (d != (b + a - a - b)) << endl << endl;*/

  /*cout << "Testing of random matrix operators\n";
  cout << "Enter size: \n";
  size_t size;
  cin >> size;
  TMatrix<int> sample(size);
  for (size_t i = 0; i < size; i++)
      for (size_t j = i; j < size; j++)
      {
          sample[i][j] = rand();
      }
  TMatrix<int> plus(size);
  for (size_t i = 0; i < size; i++)
      for (size_t j = i; j < size; j++)
      {
          plus[i][j] = rand();
      }
  TMatrix<int> minus(size);
  for (size_t i = 0; i < size; i++)
      for (size_t j = i; j < size; j++)
      {
          minus[i][j] = rand();
      }
  TMatrix<int> temp(sample);
  cout << "Random matrix =\n" << sample << '\n';
  cout << "Plus matrix =\n" << plus << '\n';
  cout << "Minus matrix =\n" << minus << '\n';
  cout << "Enter the number of experiments:";
  size_t count;
  cin >> count;
  TVector<int> op(count);
  for (size_t k = 0; k < count; k++)
  {
      op[k] = (rand() % 2);
      if (op[k] == 0)
      {
          sample = sample + plus;
      }
      if (op[k] == 1)
      {
          sample = sample - minus;
      }
  }
  cout << "Vector operator(0 +, 1 -): " << op << '\n';
  cout << "Matrix after transformations =\n" << sample << '\n';
  for (size_t k = 0; k < count; k++)
  {
      if (op[k] == 0)
      {
          sample = sample - plus;
      }
      if (op[k] == 1)
      {
          sample = sample + minus;
      }
  }
  cout << "Matrix after inverse transformations =\n" << sample << '\n';
  cout << "The original matrix =\n" << temp << '\n';
  cout << "The original matrix == matrix after inverse transformations: " << (temp == sample) << '\n';*/
    cout << "Testing matrix operators\n";
    bool flag0 = true;
    bool flag1 = true;
    bool flagop = true;
    while (flag0)
    {
        flag1 = true;
        cout << "Enter size: \n";
        size_t size;
        cin >> size;
        TMatrix<double> sample1(size);
        TMatrix<double> sample2(size);
        cout << "Enter (0) your first matrix(A) or create (1) random matrix: \n";
        size_t check;
        cin >> check;
        switch (check)
        {
        case 0:
            cin >> sample1;
            break;

        case 1: 
            for (size_t i = 0; i < size; i++)
                for (size_t j = i; j < size; j++)
                {
                    sample1[i][j] = double(rand())/100;
                }
            cout << "Matrix A: \n";
            cout << sample1 << '\n';
            break;

        default:
            cout << "Wrong input, try again\n";
            flag1 = false;
            flagop = false;
            break;
        }
        while (flag1)
        {
            flagop = true;
            cout << "Enter (0) your second matrix(B) or create (1) random matrix: \n";
            cin >> check;
            switch (check)
            {
            case 0:
                cin >> sample2;
                break;
            case 1:
                for (size_t i = 0; i < size; i++)
                    for (size_t j = i; j < size; j++)
                    {
                        sample2[i][j] = double(rand()) / 100;
                    }
                cout << "Matrix B: \n";
                cout << sample2 << '\n';
                break;
            default:
                cout << "Wrong input, try again\n";
                flagop = false;
                break;
            }
            while (flagop)
            {
                cout << "Enter operator (+ or -): \n";
                char op;
                cin >> op;
                switch (op)
                {
                default:
                    cout << "Wrong operator, try again\n";
                    break;
                case '+':
                    cout << "A + B: \n";
                    sample1 = sample1 + sample2;
                    cout << sample1 << '\n';
                    flagop = false;
                    break;
                case '-':
                    cout << "A - B: \n";
                    sample1 = sample1 - sample2;
                    cout << sample1 << '\n';
                    flagop = false;
                    break;
                }

                if (!flagop)
                {
                    cout << "Start over(0), finish(1), continue with the result(other): \n";
                    cin >> check;
                    switch (check)
                    {
                    default:
                        break;
                    case 0:
                        flag1 = false;
                        break;
                    case 1:
                        flag0 = false;
                        flag1 = false;
                        break;
                    }
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
