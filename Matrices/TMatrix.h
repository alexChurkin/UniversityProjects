#pragma once
#include "TVector.h"

//Класс квадратной матрицы
//Матрица - массив строк
//Одна её строка - это вектор
template <class T>
class TMatrix {
private:
	int size;
	TVector<T>* pMatrix;

public:
	TMatrix(int _size = 5);
	TMatrix(const TMatrix<T>& m);
	~TMatrix();

	TVector<T>& operator[](int pos);

	TMatrix operator+(const TMatrix& b) const;
	TMatrix operator-(const TMatrix& b) const;
	TMatrix operator*(const TMatrix& b) const;

	TMatrix operator+(const T& b) const;
	TMatrix operator-(const T& b) const;
	TMatrix operator*(const T& b) const;
	TMatrix operator/(const T& b) const;

	TMatrix& operator=(const TMatrix& m);
	TMatrix& operator+=(const TMatrix& b);
	TMatrix& operator-=(const TMatrix& b);
	TMatrix& operator*=(const TMatrix& b);

	TMatrix& operator+=(const T& b);
	TMatrix& operator-=(const T& b);
	TMatrix& operator*=(const T& b);
	TMatrix& operator/=(const T& b);

	template <class K>
	friend TMatrix operator+(const K& a, const TMatrix<K>& b)
	{
		TMatrix<K> result(b);
		for (int i = 0; i < result.size; i++)
			result.pMatrix[i] += b;
		return result;
	}

	template <class K>
	friend TMatrix operator-(const K& a, const TMatrix<K>& b)
	{
		TMatrix<K> result(b);
		for (int i = 0; i < result.size; i++)
			result.pMatrix[i] = b - result.pMatrix[i];
		return result;
	}

	template <class K>
	friend TMatrix operator*(const K& a, const TMatrix<K>& b)
	{
		TMatrix<K> result(b);
		for (int i = 0; i < result.size; i++)
			result.pMatrix[i] *= b;
		return result;
	}

	//Умножение матрицы на вектор
	template <class K>
	friend TVector<K> operator*(const TMatrix<K>& a, const TVector<K>& b)
	{

	}

	//Умножение матрицы на вектор с записью результата в текущую матрицу
	template <class K>
	friend TVector<K> operator*=(const TMatrix<K>& a, const TVector<K>& b)
	{

	}

	template <class K>
	friend ostream& operator<<(ostream& os, const TMatrix<K>& m)
	{
		for (int i = 0; i < size; i++)
			os << pMatrix[i];
		return os;
	}

	template <class K>
	friend istream& operator>>(istream& is, TMatrix<K>& m)
	{
		for (int i = 0; i < size; i++)
			is >> pMatrix[i];
		return is;
	}
};

template <class T>
TMatrix<T>::TMatrix(int _size)
{
	if (size <= 0)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Matrix size cannot be <= 0");

	size = _size;
	pMatrix = new TVector<T>[size];
	//Вектор tmp в цикле используется для исправления
	//Размера всех векторов матрицы
	//(Т.к. по умолчанию длины векторов не являются size)
	TVector<T> tmp(size);
	for (int i = 0; i < size; i++)
		pMatrix[i] = tmp;
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T>& M)
{
	size = M.size;
	pMatrix = new TVector<T>[size];
	for (int i = 0; i < size; i++)
		pMatrix[i] = M.pMatrix[i];
}

template <class T>
TMatrix<T>::~TMatrix()
{
	delete[] pMatrix;
}

template <class T>
TVector<T>& TMatrix<T>::operator[](int pos)
{
	if (pos <= 0 || pos >= size)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Row index out of bounds");
	return pMatrix[pos];
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& b) const
{
	if (size != b.size)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Matrices have different dimensions");

	TMatrix result(*this);
	for (int i = 0; i < b.size; i++)
			result.pMatrix[i] += b.pMatrix[i];
	return result;
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& b) const
{
	if (size != b.size)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Matrices have different dimensions");

	TMatrix result(*this);
	for (int i = 0; i < b.size; i++)
			result.pMatrix[i] -= b.pMatrix[i];
	return result;
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& b) const
{
	if (size != b.size)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Matrices have different dimensions");

	TMatrix result(size);

	//Цикл по строкам левой матрицы (нашей текущей)
	for (int i = 0; i < b.size; i++)
	{
		//Цикл по столбцам правой матрицы (матрицы b)
		for (int j = 0; j < b.size; j++)
		{
			//Здесь нас интересует i-я строка левой матрицы и j-й столбец правой
			//Идём по элементам a

			//Сложение умноженных элементов (как по правилам умножения матриц)
			T sum = pMatrix[i][0] * b.pMatrix[0][j];
			for (int k = 1; k < b.size; k++)
			{
				sum += pMatrix[i][k] * b.pMatrix[k][j];
			}
			//Запись суммы-результата в [i][j] ячейку
			result[i][j] = sum;
		}
	}
	return result;
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const T& b) const
{
	TMatrix result(*this);
	for (int i = 0; i < result.size; i++)
		result.pMatrix[i] += b;
	return result;
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const T& b) const
{
	TMatrix result(*this);
	for (int i = 0; i < result.size; i++)
		result.pMatrix[i] -= b;
	return result;
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const T& b) const
{
	TMatrix result(*this);
	for (int i = 0; i < result.size; i++)
		result.pMatrix[i] *= b;
	return result;
}

template <class T>
TMatrix<T> TMatrix<T>::operator/(const T& b) const
{
	if(b == NULL)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Division by zero");

	TMatrix result(*this);
	for (int i = 0; i < result.size; i++)
		result.pMatrix[i] /= b;
	return result;
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& m)
{
	if (this == &m)
		return *this;

	if (size != m.size) {
		size = m.size;
		delete[] pMatrix;
		pMatrix = new TVector<T>[size];
	}
	for (int i = 0; i < size; i++)
		pMatrix[i] = m.pMatrix[i];
	return *this;
}

template <class T>
TMatrix<T>& TMatrix<T>::operator+=(const TMatrix<T>& b)
{
	if (size != b.size)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Vectors have different dimensions");

	for (int i = 0; i < size; i++)
		pMatrix[i] += b.pMatrix[i];
	return *this;
}

template <class T>
TMatrix<T>& TMatrix<T>::operator-=(const TMatrix<T>& b)
{
	if (size != b.size)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Vectors have different dimensions");

	for (int i = 0; i < size; i++)
		pMatrix[i] -= b.pMatrix[i];
	return *this;
}

template <class T>
TMatrix<T>& TMatrix<T>::operator*=(const TMatrix<T>& b)
{
	if (size != b.size)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Matrices have different dimensions");

	TMatrix result(size);

	//Цикл по строкам левой матрицы (нашей текущей)
	for (int i = 0; i < b.size; i++)
	{
		//Цикл по столбцам правой матрицы (матрицы b)
		for (int j = 0; j < b.size; j++)
		{
			//Здесь нас интересует i-я строка левой матрицы и j-й столбец правой
			//Идём по элементам a

			//Сложение умноженных элементов (как по правилам умножения матриц)
			T sum = pMatrix[i][0] * b.pMatrix[0][j];
			for (int k = 1; k < b.size; k++)
			{
				sum += pMatrix[i][k] * b.pMatrix[k][j];
			}
			//Запись суммы-результата в [i][j] ячейку
			result[i][j] = sum;
		}
	}
	for (int i = 0; i < size; i++)
		pMatrix[i] = result[i];

	return *this;
}

template <class T>
TMatrix<T>& TMatrix<T>::operator+=(const T& b)
{
	for (int i = 0; i < size; i++)
		pMatrix[i] += b;
	return *this;
}

template <class T>
TMatrix<T>& TMatrix<T>::operator-=(const T& b)
{
	for (int i = 0; i < size; i++)
		pMatrix[i] -= b;
	return *this;
}

template <class T>
TMatrix<T>& TMatrix<T>::operator*=(const T& b)
{
	for (int i = 0; i < size; i++)
		pMatrix[i] *= b;
	return *this;
}

template <class T>
TMatrix<T>& TMatrix<T>::operator/=(const T& b)
{
	if (b == NULL)
		throw Exception(__FILE__, __FUNCTION__,
			__LINE__, "Division by zero");

	for (int i = 0; i < size; i++)
		pMatrix[i] /= b;
	return *this;
}