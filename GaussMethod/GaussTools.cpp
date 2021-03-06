#include <iostream>
#include <iomanip>
using namespace std;

double** init_matrix(int n)
{
    double** matrix = new double* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new double[n];
    return matrix;
}

//Вывод системы уравнений на экран
void print_system(double** A, double* b, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < n; j++) {
            cout.width(6);
            cout << A[i][j] << ' ';
        }
        cout.width(6);
        cout << b[i] << "      |" << '\n';
    }
}

//Заполнение системы с клавиатуры или случайно
//(в зависимости от n)
void request_system(double** &A, double* &b, double* &x, int& n)
{
    cout << "Введите размер системы n: ";
    cin >> n;

    A = init_matrix(n);
    b = new double[n];
    x = new double[n];

    if (n <= 4)
    {
        cout << "Введите уравнения:\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> A[i][j];
            cin >> b[i];
        }
        return;
    }

    cout << "Матрица будет заполена автоматически.\n";
    srand((unsigned int)time(NULL));
    int range_min, range_max;
    cout << "Введите минимальное значение: \n";
    cin >> range_min;
    cout << "Введите максимальное значение: \n";
    cin >> range_max;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] =
                (int)((double)rand() / (RAND_MAX + 1) * (range_max + 1 - range_min) +
                    range_min);
        }
        b[i] = (int)((double)rand() / (RAND_MAX + 1) * (range_max + 1 - range_min) +
                    range_min);
    }
    if (n <= 10)
    {
        cout << "Успешно создана система:\n";
        print_system(A, b, n);
    }
    else
    {
        cout << "Успешно создана система "
            << n << " x " << n << "\n";
    }
}

//Освобождение памяти от системы
void destroy_system(double**& A, double*& b, double*& x, int n)
{
    if (A != NULL) {
        for (int i = 0; i < n; i++)
            delete[] A[i];
        delete[] A;
        A = NULL;
    }
    if (b != NULL) {
        delete[] b;
        b = NULL;
    }
    if (x != NULL) {
        delete[] x;
        x = NULL;
    }
}