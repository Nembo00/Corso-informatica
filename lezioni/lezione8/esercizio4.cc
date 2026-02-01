#include <iostream>
#include "funzioni.h"
using namespace std;

int main() {
    double a = 5.0, b = 3.0;
    cout << "Valori iniziali: " << endl;
    cout << "a = " << a << " b = " << b << endl;

    scambia1(a, b);
    cout << "a = " << a << " b = " << b << endl;

    scambia2(&a, &b);
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}