#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <string>
#include "texception.h"
using namespace std;

class Vector
{
private:
    int n;
    double* arr;

public:
    //����������� �������
    Vector(int _n = 3);
    //����������� �����������
    Vector(const Vector& v);
    //����������
    ~Vector();

    void resize(int _n);

    Vector operator+(const Vector& b);
    Vector operator-(const Vector& b);
    double operator*(const Vector& b);

    Vector operator+(double b);
    Vector operator-(double b);
    Vector operator*(double b);
    Vector operator/(double b);

    //��������� ������������
    Vector& operator=(const Vector& b);
    Vector& operator+=(const Vector& b);
    Vector& operator-=(const Vector& b);

    Vector& operator+=(double b);
    Vector& operator-=(double b);
    Vector& operator*=(double b);
    Vector& operator/=(double b);

    //��������� i-� ���������� ��� ������/������ (set/get)
    double& operator[](int i);

    //c+v
    friend Vector operator+(double a, const Vector& b);
    //c-v
    friend Vector operator-(double a, const Vector& b);
    //c*v
    friend Vector operator*(double a, const Vector& b);
    //����� �� �����
    friend ostream& operator<<(ostream& os, const Vector& v);
    //���� � ����������
    friend istream& operator>>(istream& is, Vector& v);
};