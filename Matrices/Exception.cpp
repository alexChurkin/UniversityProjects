#pragma once
#include <iostream>
#include <fstream>
#include <clocale>
#include <ctime>
#include <cstring>
#include "Exception.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

Exception::Exception(const char* _file, const char* _func, int _line, const char* _desc)
{
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

Exception::Exception(const Exception& e)
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

void Exception::print() const
{
	cout << "<<��������� ����������>>\n";
	cout << "����: " << file << '\n';
	cout << "�������: " << func << '\n';
	cout << "����� ������: " << line << '\n';
	cout << "���������: " << desc << '\n';
}

ostream& operator<<(ostream& os, const Exception& e)
{
	os << "<<��������� ����������>>\n";
	os << "����: " << e.file << '\n';
	os << "�������: " << e.func << '\n';
	os << "����� ������: " << e.line << '\n';
	os << "���������: " << e.desc << '\n';
	return os;
}

Exception::~Exception()
{
	delete[] file;
	delete[] func;
	delete[] desc;
}