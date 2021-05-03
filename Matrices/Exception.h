#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

//������ ���������� �� ������ ��� � ���������� ���������
class Exception
{
private:
	char* file; //��� �����
	char* func; //��� �������
	int line;   //����� ������
	char* desc; //��������� ��������

public:
	Exception(const char* _file, const char* _func, int _line, const char* _desc);
	Exception(const Exception& e);
	~Exception();

	void print() const;
	friend ostream& operator<<(ostream& os, const Exception& e);
};