#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include "rangetable.h"

void main()
{
	setlocale(LC_CTYPE, "rus");
	printf("Введите a (начало отрезка), b (конец отрезка), step (шаг), n (кол-во слагаемых)\n");
	double a, b, step;
	int n;

	scanf("%lf %lf %lf %d", &a, &b, &step, &n);

	int size = 0;
	print_exp_range(a, b, step, n, &size);
}