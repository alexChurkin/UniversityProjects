#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//���� ������ - ������� � ���������� �� ��������� ����������
class TException
{
private:
    char* file; //��� �����
    char* func; //��� �������
    int line;   //����� ������
    char* desc; //��������� ��������

public:
    //������� ����������� 1
    TException(const char* _file, const char* _func, int _line, const char* _desc)
    {
        //���������� �������
        //n + 1, ����� ������� ����� �� ������� ������
        //strcpy �������� ������ �����, ����� ��� ������ ����������������
        int n1 = strlen(_file);
        file = new char[n1 + 1];
        strcpy(file, _file);

        int n2 = strlen(_func);
        func = new char[n2 + 1];
        strcpy(func, _func);

        int n3 = strlen(_desc);
        desc = new char[n3 + 1];
        strcpy(desc, _desc);

        line = _line;
    }

    //����������� �����������
    TException(const TException& e)
    {
        int n1 = strlen(e.file);
        file = new char[n1 + 1];
        strcpy(file, e.file);

        int n2 = strlen(e.func);
        func = new char[n2 + 1];
        strcpy(func, e.func);

        int n3 = strlen(e.desc);
        desc = new char[n3 + 1];
        strcpy(desc, e.desc);

        line = e.line;
    }

    //������ ���������� �� �����
    //const, ������ ��� ����� �� ������� �������� �����,
    //�.�. ��� ����� �������� � � const-�������
    //const-����� ������ ����
    //����� �������� ������ ������ ����������� ������
    void print() const
    {
        cout << "<<��������� ����������>>\n";
        cout << "����: " << file << '\n';
        cout << "�������: " << func << '\n';
        cout << "����� ������: " << line << '\n';
        cout << "���������: " << desc << '\n';
    }

    //����� �� ����� � ����� �������� ����
    friend ostream& operator<<(ostream& os, const TException& e)
    {
        os << "<<��������� ����������>>\n";
        os << "����: " << e.file << '\n';
        os << "�������: " << e.func << '\n';
        os << "����� ������: " << e.line << '\n';
        os << "���������: " << e.desc << '\n';
        return os;
    }

    //����������
    ~TException()
    {
        delete[] file;
        delete[] func;
        delete[] desc;
    }
};