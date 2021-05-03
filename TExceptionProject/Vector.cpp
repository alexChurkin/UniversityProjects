#define _CRT_SECURE_NO_WARNINGS
#include "vector.h"

Vector::Vector(int _n)
{
    if (_n <= 0)
        throw TException(__FILE__, __FUNCTION__, __LINE__, "Vector size cannot be <= 0");

    n = _n;
    arr = new double[_n];
    for (int i = 0; i < n; i++)
        arr[i] = 0;
}

//� ����������� ����������� ��������� ������!
//����� ����� ����� ������� ����������� �� �������������
//������������ �����������!!! (����������� ����)
//(������ �������� ����������� ��� ����, �����
//�������� �� �������� ������)
Vector::Vector(const Vector& v)
{
    n = v.n;
    arr = new double[v.n];
    for (int i = 0; i < n; i++)
        arr[i] = v.arr[i];
}

Vector::~Vector()
{
    delete[] arr;
}

void Vector::resize(int _n)
{
    if (_n == n)
        return;

    double* arr_new = new double[_n];
    for (int i = 0; i < _n; i++)
        arr_new[i] = 0;

    //����� ������ ������ ������� (������ �������� ��������)
    if (_n > n)
        for (int i = 0; i < n; i++)
            arr_new[i] = arr[i];
    //����� ������ ������� (�������� ��������, ������� ��������)
    else
        for (int i = 0; i < _n; i++)
            arr_new[i] = arr[i];

    delete[] arr;
    arr = arr_new;
    n = _n;
}

//���� 1 --------------------------------
Vector Vector::operator+(const Vector& b)
{
    if (n != b.n)
    {
        throw "Vectors have different dimensions";
    }

    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = arr[i] + b.arr[i];
    return res;
}

Vector Vector::operator-(const Vector& b)
{
    if (n != b.n)
    {
        throw "Vectors have different dimensions";
    }

    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = arr[i] - b.arr[i];
    return res;
}

double Vector::operator*(const Vector& b)
{
    if (n != b.n)
    {
        throw "Vectors have different dimensions";
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i] * b.arr[i];
    return sum;
}

//���� 2 --------------------------------
Vector Vector::operator+(double b)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = (*this)[i] + b;
    //��������� ����� ������ ���������� � ��� �� ���������,
    //����� ���������� � ������� ���������! ��� ����� �����������
    //����� �������������� ����������� ����������� (���� � ������ ����
    //������������� ����)
    //�.�. ����� ���������� ��������� ������ ��� ������������ ����,
    //� � ������������� ������� ��������� ������ �� ���.
    //���������� ��� ������������ ���������� ��������� �����������
    //�����, �� ���� ���������� ������ ����������� ������,
    //� ������ ��� ��������� ����� ���������� ����� ������.
    return res;
}

Vector Vector::operator-(double b)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
        res[i] = (*this)[i] - b;
    return res;
}

Vector Vector::operator*(double b)
{
    Vector res(n);
    for (int i = 0; i < n; i++)
        res.arr[i] = arr[i] * b;
    return res;
}

Vector Vector::operator/(double b)
{
    if (b == 0)
    {
        throw "Division by zero (b = 0)";
    }

    Vector res(n);
    for (int i = 0; i < n; i++)
        res.arr[i] = arr[i] / b;
    return res;
}

//���� 3 --------------------------------
//������� ������� �� ������� ��������� �������� ������ � (x = y) = b
Vector& Vector::operator=(const Vector& v)
{
    //�������� �� ��, ���������� �� ������������ ������� ������ ����
    if (this == &v)
        return *this;

    //���� � �������� ������� ������ �� ��������� � v,
    //�� ���������� �������� ������ �������� �������
    //� ������������ � ����������
    if (n != v.n)
    {
        n = v.n;
        delete[] arr;
        arr = new double[n];
    }
    //����� ������ �������� (���������) ��������
    for (int i = 0; i < n; i++)
        arr[i] = v.arr[i];

    return *this;
}

//������� ������ ���������� �����
Vector& Vector::operator+=(const Vector& v)
{
    //���� � �������� ������� ������ �� ��������� � v,
    //�� �� �� ����� �������
    if (n != v.n)
    {
        throw "Vectors have different dimensions";
    }

    //����� ������ �������� (���������) ��������
    for (int i = 0; i < n; i++)
        arr[i] += v.arr[i];

    return *this;
}

Vector& Vector::operator-=(const Vector& v)
{
    if (n != v.n)
    {
        throw "Vectors have different dimensions";
    }

    for (int i = 0; i < n; i++)
        arr[i] -= v.arr[i];

    return *this;
}

//���� 4 --------------------------------
Vector& Vector::operator+=(double b)
{
    for (int i = 0; i < n; i++)
        arr[i] += b;

    return *this;
}

Vector& Vector::operator-=(double b)
{
    for (int i = 0; i < n; i++)
        arr[i] -= b;

    return *this;
}

Vector& Vector::operator*=(double b)
{
    for (int i = 0; i < n; i++)
        arr[i] *= b;

    return *this;
}

Vector& Vector::operator/=(double b)
{
    if(b == 0)
        throw "Division by zero (b = 0)";

    for (int i = 0; i < n; i++)
        arr[i] /= b;

    return *this;
}

double& Vector::operator[](int i)
{
    if (i >= 0 && i < n)
        return arr[i];
    else
        throw "Index out of bounds exception";
}

Vector operator+(double a, const Vector& b)
{
    Vector c(b);
    for (int i = 0; i < c.n; i++)
    {
        c.arr[i] += a;
    }
    //����� ����� ���������� ����������� ����������� � ����������
    //�������
    return c;
}

Vector operator-(double a, const Vector& b)
{
    Vector c(b);
    for (int i = 0; i < c.n; i++)
    {
        c.arr[i] = a - c.arr[i];
    }
    return c;
}

Vector operator*(double a, const Vector& b)
{
    Vector c(b);
    for (int i = 0; i < c.n; i++)
    {
        c.arr[i] = a * c.arr[i];
    }
    return c;
}

ostream& operator<<(ostream& os, const Vector& v)
{
    os << '(';
    for (int i = 0; i < v.n - 1; i++)
    {
        os << v.arr[i] << ", ";
    }
    os << v.arr[v.n - 1] << ')';
    return os;
}

istream& operator>>(istream& is, Vector& v)
{
    for (int i = 0; i < v.n; i++)
    {
        is >> v.arr[i];
    }
    return is;
}