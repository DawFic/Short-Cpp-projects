#include <iostream>
#include "matrix.h"

int main()
{
	Matrix<int> m1;
	Matrix<int> m2;
	Matrix<int> m3;
	std::cout<<"First matrix:"<<std::endl;
	m1.enterValues();
	std::cout<<"Second matrix:"<<std::endl;
	m2.enterValues();
//	std::cout<<"Third matrix:"<<std::endl;
//	m3.enterValues();
	m3 = m1 * m2;
	m3 = m1 + m2;
	m3 = m1 - m2;
	return 0;	
}

