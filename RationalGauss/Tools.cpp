#include <iostream>
#include <fstream>
#include <iomanip>
#include "rational.h"
using namespace std;

Rational** init_matrix(int n)
{
    Rational** matrix = new Rational*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new Rational[n];
    return matrix;
}

void print_system(Rational** A, Rational* b, int n)
{
    cout << fixed;
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < n; j++) {
            cout.width(10);
            cout << setprecision(5)
                << A[i][j] << ' ';
        }
        cout << " |";
        cout.width(10);
        cout << setprecision(5)
            << b[i] << "  |" << '\n';
    }
}

void print_solution(Rational* x, int n) {
    cout << "x = [ ";
    for (int i = 0; i < n - 1; i++) {
        cout << x[i] << ' ';
    }
    cout << x[n - 1] << "]\n";
}

//���������� ������� � ���������� ��� ��������
//(� ����������� �� n)
void request_system(Rational**& A, Rational*& b, int n)
{
    A = init_matrix(n);
    b = new Rational[n];

    cout << "������� ���������:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
        cin >> b[i];
    }
    return;
}

//������������ ������ �� �������
void destroy_system(Rational**& A, Rational*& x, Rational*& b, int n)
{
    if (A != NULL) {
        for (int i = 0; i < n; i++)
            delete[] A[i];
        delete[] A;
        A = NULL;
    }
    if (x != NULL) {
        delete[] x;
        x = NULL;
    }
    if (b != NULL) {
        delete[] b;
        b = NULL;
    }
}