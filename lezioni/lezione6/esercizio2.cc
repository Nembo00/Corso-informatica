#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // costruzione vettori v e w 
    const int N = 5;
    double *v = new double[N];
    double *w = new double [N];
    v[0] = 2, v[1] = 5, v[2] = 10, v[3] = 20, v[4] = 50;
    w[0] = 10, w[1] = -5, w[2] = 3, w[3] = 1, w[4] = 100;
    // calcolo prodotto scalare tra v e w
    double s = 0;
    for (int i = 0; i<N; i++) {
        s += v[i] * w[i];
    }
    cout << "Prodotto scalare tra v e w: " << s << endl;

    //creo vettore dinamico z identico a v
    double *z = new double[5];
    for (int j = 0; j<N; j++) {
        z[j] = v[j];
    }
    z[2] = 0;

    // stampo norma euclidea del vettore z
    double norma = 0;
    for (int k = 0; k < N; k++) {
        norma += z[k] * z[k];
    }
    norma = sqrt(norma);
    cout << "Norma euclidea vettore z: " << norma << endl;

    // Normalizzo vettore ossia, dividere ogni elemento zi per la sua norma
    cout << "Vettore normalizzato: " << endl;
    for (int l = 0; l < N; l++) {
        cout << "Norma z[" << l << "] = " << z[l] / norma << endl;
    }
    delete[] v;
    delete[] w;
    delete[] z;

    return 0;
}