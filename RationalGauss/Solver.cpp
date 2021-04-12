#include <iostream>
#include "tools.h"
using namespace std;

//���������� ������ ������
bool gauss_solve(Rational** A, Rational*& x, Rational* b, int n)
{
    x = new Rational[n];
    //������ ��� ������ ������
    for (int j = 0; j < n; j++)
    {
        Rational alpha;

        //���������� ������ � ����. j-�
        //��������� �� ������� j
        int maxJ = j;
        for (int i = j + 1; i < n; i++)
        {
            if (abs(A[maxJ][j]) < abs(A[i][j]))
                maxJ = i;
        }
        if (j != maxJ) {
            swap(A[j], A[maxJ]);
            swap(b[j], b[maxJ]);
            cout << "> ����� ����� "
                << j << " � " << maxJ << '\n';
            if (n <= 10)
                print_system(A, b, n);
            cout << "\n\n";
        }
        if (A[maxJ][j] == 0) {
            cout << "������� �����������.\n";
            return false;
        }//

        for (int i = j + 1; i < n; i++)
        {
            alpha = A[i][j] / A[j][j];
            for (int k = j; k < n; k++)
            {
                A[i][k] -= alpha * A[j][k];
            }
            b[i] -= alpha * b[j];
        }
        cout << "> ������ ��� " << j + 1 << ":\n";
        if (n <= 10)
            print_system(A, b, n);
        cout << "\n\n";
    }

    //�������� ��� ������ ������
    for (int i = n - 1; i >= 0; i--)
    {
        Rational sum = 0;
        for (int j = i + 1; j < n; j++)
            sum += A[i][j] * x[j];

        x[i] = (b[i] - sum) / A[i][i];
    }
    return true;
}