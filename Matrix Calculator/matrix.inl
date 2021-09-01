#include <iostream>
#include "matrix.h"

template <typename T>

void Matrix<T>::enterValues()
{
	std::cout<<"Set number of rows"<<std::endl;
	std::cin>>this->rows;
	std::cout<<std::endl;
	std::cout<<"Set number of columns"<<std::endl;
	std::cin>>this->cols;
	matrix.resize(this->rows, std::vector<T>(this->cols));
	for(int i = 0; i<this->matrix.size(); i++)
	{
		for(int j=0; j<this->matrix[i].size(); j++)
		{
			std::cout<<"Enter data ["<<i<<"]["<<j<<"]"<<std::endl;
			std::cin>>this->matrix[i][j];
		}
	}

}
/*
Matrix& Matrix<T>::operator=(const Matrix& secondMatrix)//copying Matrix object
{
	if(this->matrix.size() == secondMatrix.matrix.size() && this->matrix[0].size() == secondMatrix.matrix[0].size())
	{
		for(int i = 0; i<this->matrix.size(); i++)
		{
			for(int j=0; j<this->matrix[i].size(); j++)
			{
				this->matrix[i][j] = secondMatrix.matrix[i][j];
			}
		}
	}
//	else
		//return error
	return *this;
}
*/
template <typename T>
Matrix<T>& Matrix<T>::operator=(const std::vector<std::vector<T>>& secondMatrix)//copying matrix from equation
{
	if(this->matrix.size() == secondMatrix.size() && this->matrix[0].size() == secondMatrix[0].size())
	{
		for(int i = 0; i<this->matrix.size(); i++)
		{
			for(int j=0; j<this->matrix[i].size(); j++)
			{
				this->matrix[i][j] = secondMatrix[i][j];
			}
		}
	}
//	else
		//return error
	return *this;
}
template <typename T>
std::vector<std::vector<T>> Matrix<T>::operator+(const Matrix<T>& secondMatrix)
{
	std::vector<std::vector<T>> resultMatrix;
	resultMatrix.resize(this->rows, std::vector<T>(this->cols));
	if(this->matrix.size() == secondMatrix.matrix.size() && this->matrix[0].size() == secondMatrix.matrix[0].size())
	{
		for(int i = 0; i<this->matrix.size(); i++)
		{
			for(int j=0; j<this->matrix[i].size(); j++)
			{
				resultMatrix[i][j] = this->matrix[i][j] + secondMatrix.matrix[i][j];
			}
		}
	}
//	else
		//return error
	return resultMatrix; 
}
template <typename T>
std::vector<std::vector<T>> Matrix<T>::operator-(const Matrix<T>& secondMatrix)
{
	std::vector<std::vector<T>> resultMatrix;
	resultMatrix.resize(this->rows, std::vector<T>(this->cols));
	if(this->matrix.size() == secondMatrix.matrix.size() && this->matrix[0].size() == secondMatrix.matrix[0].size())
	{
		for(int i = 0; i<this->matrix.size(); i++)
		{
			for(int j=0; j<this->matrix[i].size(); j++)
			{
				resultMatrix[i][j] = this->matrix[i][j] - secondMatrix.matrix[i][j];
			}
		}
	}
//	else
		//return error
	return resultMatrix; 
}
template <typename T>
std::vector<std::vector<T>> Matrix<T>::operator*(const Matrix<T>& secondMatrix)
{
	std::vector<std::vector<T>> resultMatrix;
	resultMatrix.resize(this->cols, std::vector<T>(secondMatrix.cols)); 
	if(this->matrix.size() == secondMatrix.matrix[0].size())
	{
		for(int i = 0; i<this->matrix[0].size(); i++)
		{
			for(int j=0; j<secondMatrix.matrix.size(); j++)
			{
				for(int k = 0; k<this->matrix.size();k++)
				{
					int sum = 0;
					for(int l = 0; l<secondMatrix.matrix[k].size(); l++)
					{
						sum += this->matrix[l][k] * secondMatrix.matrix[k][l];
					}
					resultMatrix[i][j] = sum;
				}
			}
		}
	}
//	else

		//return error
	return resultMatrix; 
}
