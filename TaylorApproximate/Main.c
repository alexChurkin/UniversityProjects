#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include "input_struct.h"
#include "functions.h"
#include "rangeprinter.h"

void main()
{
	setlocale(LC_CTYPE, "rus");
	double a, b, step;
	int n, number;

	printf("Выберите функцию:\n>1 - exp(x)\n>2 - sin(x)\n>3 - cos(x)\n");
	scanf("%i", &number);
	printf("Введите a (начало отрезка), b (конец отрезка), step (шаг), n (кол-во слагаемых):\n");
	scanf("%lf %lf %lf %d", &a, &b, &step, &n);

	input inp = { a, b, step, n, NULL, NULL, "" };
	switch (number)
	{
	case 1:
		inp.func = exp;
		inp.myfunc = my_exp;
		inp.f_name = "exp";
		break;
	case 2:
		inp.func = sin;
		inp.myfunc = my_sin;
		inp.f_name = "sin";
		break;
	case 3:
		inp.func = cos;
		inp.myfunc = my_cos;
		inp.f_name = "cos";
		break;
	}
	print_range_table(inp);
}