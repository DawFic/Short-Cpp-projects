#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template <typename T>
class Matrix
{
	public:	
	//	Matrix & operator=(const Matrix& secondMatrix);
		Matrix<T> & operator=(const std::vector<std::vector<T>>& secondMatrix);	
		std::vector<std::vector<T>> operator+(const Matrix<T>& secondMatrix);
		std::vector<std::vector<T>> operator-(const Matrix<T>& secondMatrix);
		std::vector<std::vector<T>> operator*(const Matrix<T>& secondMatrix);
		void enterValues();
	private:
		int rows, cols;
		std::vector<std::vector<T>> matrix;	
};

#include "matrix.inl"
#endif
