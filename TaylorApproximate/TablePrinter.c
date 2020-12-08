#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "input_struct.h"

typedef struct row {
	double x;
	double fx;
	double my_fx;
	double error;
} row;

void print_table(input inp) {
	row* rows = (row*)malloc(sizeof(row) * 5000);

	int size = 0;

	double f_x, myf_x;
	for (double x = inp.a; x <= inp.b; x += inp.step) {
		f_x = inp.func(x);
		myf_x = inp.myfunc(x, inp.n);

		row r = { x, f_x, myf_x, f_x - myf_x };
		rows[size] = r;
		size++;
	}

	printf("\nx\t\t\t%s(x)\t\t\tmy_%s(x)\t\terror(x)\n\n", 
		inp.f_name, inp.f_name);

	double max_error = rows[0].error;
	double error_x = rows[0].x;

	for (int i = 0; i < size; i++) {
		printf("%lf\t\t%lf\t\t%lf\t\t%e\n",
			rows[i].x, rows[i].fx, rows[i].my_fx, rows[i].error);
		if (fabs(rows[i].error) > fabs(max_error)) {
			max_error = rows[i].error;
			error_x = rows[i].x;
		}
	}
	printf("\nmax_error (макс. ошибка) = %e\nerror_x (x в этой точке) = %lf\n",
		max_error, error_x);
	free(rows);
}