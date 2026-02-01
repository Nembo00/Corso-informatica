#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double funzione(double x);

int main() {
    const int n = 100;
    double x[n];
    
    for (int i = 0; i < n; i++) {
        x[i] = -3.0 + (i * 6.0/99.0);
    }

    fstream file;
    file.open("output.dat", ios::out);
    if (!file.is_open()) {
        cout << "Errore aertura file!" << endl;
        return -1;
    }
    double y[n];
    for (int i = 0; i < n; i++) {
        y[i] = funzione(x[i]);
        file << x[i];
        file << " ";
        file << y[i];
        file << endl;
    }
    file.close();

    return 0;
}

double funzione(double x) {
    return -(sin(pow(x, 2)))/(x) + 0.01 * pow(x, 2);
}