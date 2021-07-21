    #include <iostream>
#include "FirstClass.h"
    int FirstClass::objectCounter=0;
    int main() {
        FirstClass obiekt1;
        FirstClass obiekt2;
        FirstClass obiekt3;
        FirstClass* wsk1 = new FirstClass;
        FirstClass* wsk2 = new FirstClass;
        FirstClass* wsk3 = new FirstClass;

        delete wsk1;
        delete wsk2;
        delete wsk3;
        return 0;
    }
