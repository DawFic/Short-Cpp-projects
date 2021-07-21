//
// Created by dawid on 29.10.2020.
//
#include <iostream>
#include "FirstClass.h"

FirstClass::FirstClass() {
    std::cout<<"Stworzyles obiekt"<<std::endl;
    objectCounter++;
    std::cout<<"Liczba obiektow: "<<objectCounter<<std::endl;
}

FirstClass::~FirstClass() {
    std::cout<<"Usunales obiekt"<<std::endl;
    objectCounter--;
    std::cout<<"Liczba obiektow: "<<objectCounter<<std::endl;
}

