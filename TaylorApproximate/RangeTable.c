#include <stdlib.h>
#include <math.h>
#include "functions.h"

typedef struct row {
	double x;
	double fx;
	double my_fx;
	double error;
} row;

void print_exp_range(double a, double b, double step, int n, int* size)
{
	row *rows = (row*) malloc(sizeof(row) * 1000);

	(*size) = 0;
	double exp_x, myexp_x;
	for (double x = a; x <= b; x += step) {
		exp_x = exp(x);
		myexp_x = my_exp(x, n);

		row r = { x, exp_x, myexp_x, exp_x - myexp_x };
		rows[(*size)] = r;
		(*size)++;
	}

	printf("\nx\t\t\tf(x)\t\t\tmy_f(x)\t\t\terror(x)\n\n");

	double max_error = rows[0].error;
	double max_error_x = rows[0].x;

	for (int i = 0; i < (*size); i++) {
		printf("%lf\t\t%lf\t\t%lf\t\t%e\n",
			rows[i].x, rows[i].fx, rows[i].my_fx, rows[i].error);
		if (rows[i].error > max_error) {
			max_error = rows[i].error;
			max_error_x = rows[i].x;
		}
	}
	printf("\nmax_error (макс. ошибка) = %e\nmax_error (x в этой точке) = %lf\n",
		max_error, max_error_x);
	free(rows);
}