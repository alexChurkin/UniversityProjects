
void gauss_call(double** A, double* b, double* x, int n)
{
    //������ ��� ������ ������
    for (int j = 0; j < n; j++)
    {
        double alpha;
        for (int i = j + 1; i < n; i++)
        {
            alpha = A[i][j] / A[j][j];
            for (int k = j; k < n; k++)
            {
                A[i][k] -= alpha * A[j][k];
            }
            b[i] -= alpha * b[j];
        }
    }

    //�������� ��� ������ ������
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }
}