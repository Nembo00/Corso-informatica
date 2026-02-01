#include <iostream>
#include <cmath>
using namespace std;

double scalar(const double a[], const double b[], int n);
double norm(const double a[], int n);
void scambia(double &a, double &b);

double scalar(const double a[], const double b[], int n){
    double prodotto_scalare = 0;
    for (int i = 0; i < n; i++) {
        prodotto_scalare += a[i] * b[i];
    }
    return prodotto_scalare;
}

double norm(const double a[], int n) {
    return sqrt(scalar(a, a, n));
}

void scambia(double &a, double &b) {
    double tmp = a;
    a = b;
    b = tmp;
}




int main() {
    const int n = 5;
    const double v[n] = {1, 2, 3, 4, 5};
    const double w[n] = {10, 2, 4, 3, 2};
    double M[3][3]  = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

    cout << "Prodotto scalare = " << scalar(v, w, n) << endl;
    cout << "Norma vetoore v = " << norm(v, n) << endl;
    
    for (int i = 0; i < 3; i++) {
        for (int j = i; j < 3; j++) {
            scambia(M[i][j], M[j][i]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << " ";    
        }
        cout << endl;
    }
    return 0;
}