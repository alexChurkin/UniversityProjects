#pragma once
#include "TVector.h"

template <class T>
class TMatrix {
private:
	//Матрица - массив строк
	//Строка - это вектор
	int size;
	TVector<T>* pMatrix;

public:
	TMatrix(int _size = 5);
	TMatrix(const TMatrix<T>& m);
	~TMatrix();

	TVector<T>& operator[](int pos);
	//TMatrix operator+(TMatrix);
};

template <class T>
TMatrix<T>::TMatrix(int _size)
{
	size = _size;
	pMatrix = new TVector<T>[size];
	//Временный вектор для присваивания и фикса размера
	TVector<T> tmp(size);
	for (int i = 0; i < size; i++)
		//Данный оператор присваивания выравнивает размер
		pMatrix[i] = tmp;
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T>& M)
{
	size = M.size;
	pMatrix = new TVector<T>[size];
	for (int i = 0; i < size; i++)
		pMatrix[i] = M[i];
}

template <class T>
TMatrix<T>::~TMatrix()
{
	delete[] pMatrix;
}

template <class T>
TVector<T>& TMatrix<T>::operator[](int pos)
{
	return pMatrix[pos];
}

