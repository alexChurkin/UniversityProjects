#include <iostream>
#include <locale.h>
#include <time.h>
#include "gauss_tools.h"
#include "system_solver.h"
using namespace std;

double** A;
double* x;
double* b;

int n;

double** A1;
double* b1;
double max_err;
bool res;

void print_menu()
{
	cout << "����:\n"
		<< "-----------------\n"
		<< "1. ������ ����� �������\n"
		<< "2. ����� �� ���������\n"
		<< "-----------------\n";
}

void gaussificate()
{
	request_system(A, b, n);
	A1 = copy_matrix(A, n);
	b1 = copy_vector(b, n);
	res = gauss_solve(A, x, b, n);
	if (res)
	{
		print_solution(x, n);
		max_err = error_check(A1, x, b1, n);
		cout << scientific;
		cout << "����������� = " << max_err << "\n";
		cout << fixed;
	}
	cout << "��� ������?..\n";
}

int main()
{
	setlocale(LC_ALL, "russian");
	print_menu();

	gaussificate();

	short inp;
	while (true)
	{
		cin >> inp;
		switch (inp) {
		case 1:
			destroy_system(A, A1, x, b, b1, n);
			gaussificate();
			break;
		case 2:
			cout << "��������� ���������.";
			return 0;
		}
	}
}