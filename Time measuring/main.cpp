#include <iostream>
#include <cmath>
#include "Timer.h"
using namespace std;

double pochodna(double (*fcn)(double),double x){
	double dx = 0.00001;
	return (fcn(x + dx) - fcn(x)) / dx;
}
double liniowa(double x){
	return 2*x + 3;
}

double kwadratowa(double x){
	return 2*pow(x,2) + 3*x + 1;
}
double wykladnicza(double x){
	return pow(2,x);
}


int main(){
	Timer lin, kwa, wyk;
	lin.start();
	cout << "Pochodna w pkt 100, liniowa= " << pochodna(liniowa, 100) << endl;
	lin.stop();
	cout << "Czas obliczen dla funkcji liniowej " << lin << endl;
	kwa.start();
	cout << "Pochodna w pkt 100, kwadratowa= " << pochodna(kwadratowa, 100) << endl;
	kwa.stop();
	cout << "Czas obliczen dla funkcji kwadratowej " << kwa << endl;
	wyk.start();
	cout << "Pochodna w pkt 100, wykladnicza= " << pochodna(wykladnicza, 100) << endl;
	wyk.stop();
	cout << "Czas obliczen dla funkcji wykladniczej " << wyk << endl;
	return 0;

}
