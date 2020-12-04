
double my_exp(double x, int n)
{
    double result = 1;

    double a = 1.0;

    long long i;
    for (i = 1l; i <= n; i++)
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
    short sign = 1;

    long long i, j;
    for (i = 1l, j = 1l; i <= n; i++, j += 2l)
    {
        result += sign * a;
        sign = -sign;
        a *= (x / (j + 1l)) * (x / (j + 2l));
    }
    return result;
}

double my_cos(double x, int n)
{
    double result = 0.0;

    double a = 1.0;
    short sign = 1;

    long long i;
    for (i = 1; i <= n; i++)
    {
        result += sign * a;
        a *= (x / (2l * i - 1l)) * (x / (2l * i));
        sign = -sign;
    }
    return result;
}