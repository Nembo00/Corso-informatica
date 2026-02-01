#include <iostream>
using namespace std;

int main() {

    double x = 5.5;
    double* p = NULL;  //puntatore p, inizializzato a NULL

    cout << x << endl;  //Output: valore variabile x
    cout << &x <<endl;  //Output: Indirizzo di memoria variabile x
    cout << p << endl;  //Output: Indirizzo puntato da p
    cout << &p << endl; //Output: Indirizzo di memoria del ptr p

    p = &x;  //Assegno a ptr p indirizzo della variabile x
    cout << p << endl;
    cout << *p << endl;  //Output: Valore salvato all'indirizzo puntato da ptr p

    double b;
    cout << "Inserisci double: ";
    cin >> b;
    *p = b;  //Assegna input da terminale a ciò che è puntato da ptr p
    cout << x << endl;

    int n = 10;
    double *v = new double[10];
    for (int i = 0; i < n; i++) {
        cout << "&v[" << i << "] = " << &v[i] << endl;
    }
    delete[] v;

    return 0;
}