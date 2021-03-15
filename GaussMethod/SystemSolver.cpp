#include <iostream>
#include "gauss_tools.h"
using namespace std;

//���������� ������ ������
bool gauss_solve(double** A, double* &x, double* b, int n)
{
    x = new double[n];
    //������ ��� ������ ������
    for (int j = 0; j < n; j++)
    {
        double alpha;

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
        print_system(A, b, n);
        cout << "\n\n";
    }

    //�������� ��� ������ ������
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
            sum += A[i][j] * x[j];

        x[i] = (b[i] - sum) / A[i][i];
    }
    return true;
}

//�������� ������� ���������
double error_check(double** A, double* x, double* b, int n)
{
    double err = 0.0, str_sum;
    for (int i = 0; i < n; i++)
    {
        str_sum = 0.0;
        for (int j = 0; j < n; j++)
            str_sum += A[i][j] * x[j];
        
        double diff = abs(str_sum - b[i]);
        if (diff > err)
            err = diff;
    }
    return err;
}