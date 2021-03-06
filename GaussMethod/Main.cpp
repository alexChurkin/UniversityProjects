#include <iostream>
#include <locale.h>
#include <time.h>
#include "gauss_tools.h"
using namespace std;

void print_menu()
{
	cout << "����:\n"
		<< "-----------------\n"
		<< "1. ������ ����� �������\n"
		<< "2. ����� �� ���������\n"
		<< "-----------------\n";
}

int main()
{
	setlocale(LC_ALL, "russian");
	print_menu();

	double** A;
	double* x;
	double* b;

	int n = 0;

	request_system(A, b, x, n);
	//������ �������

	short inp;
	while (true)
	{
		cin >> inp;
		switch (inp) {
		case 1:
			destroy_system(A, b, x, n);
			request_system(A, b, x, n);
			//������ �������
			break;
		case 2:
			cout << "��������� ���������.";
			return 0;
		}
	}
}