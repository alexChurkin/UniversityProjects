typedef long long ll;

double my_exp(double x, int n)
{
	double result = 1.0;
	double a = 1.0;

	ll i;
	for (i = 1; i <= n; i++)
	{
		a *= (x / i);
		result += a;
	}
	return result;
}

double my_sin(double x, int n)
{
	double result = 0.0;
	double a = x;

	ll i;
	for (i = 1; i <= n; i++)
	{
		result += a;
		a *= (-1) * (x / (2 * i)) * (x / (2 * i + 1));
	}
	return result;
}

double my_cos(double x, int n)
{
	double result = 0.0;
	double a = 1.0;

	ll i;
	for (i = 1; i <= n; i++)
	{
		result += a;
		a *= (-1) * (x / (2 * i - 1)) * (x / (2 * i));
	}
	return result;
}

double my_log(double x, int n)
{
	double result = 0.0;
	double a = --x;

	ll i;
	for (i = 1; i <= n; i++)
	{
		result += a / i;
		a *= (-1) * x;
	}
	return result;
}