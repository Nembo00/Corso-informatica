#include <iostream>
#include "function.h"
using namespace std;



double scalar(vettore a, vettore b);
vettore somma(vettore a, vettore b);

int main() {
    vettore a;
    vettore b;
    a = {1, 0, 0};
    b = {0, 1, 0};
    

    cout << "Prodotto scalare: " << scalar(a, b) << endl;

    
    vettore c = somma(a, b);
    cout << "Vettore somma di coordinate: " << endl;
    cout << "x = " << c.x << " y = " << c.y << " z = " << c.z << endl;

    vettore d = prodotto_vettoriale(a, b);
    cout << "Prodotto vettoriale a X b: " << endl;
    cout << "d = (" << d.x << ", " << d.y << ", " << d.z << ")" << endl;

    return 0;

}

double scalar(vettore a, vettore b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;    
}

vettore somma(vettore a, vettore b) {
    vettore c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return c;
}
