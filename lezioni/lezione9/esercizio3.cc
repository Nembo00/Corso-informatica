#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

struct dati {
    double x;
    double y;
};

bool distanza(const double x_c, const double y_c, const double r, dati p);

int main() {
    //variabili cerchio
    const double x_c = 0.5;
    const double y_c = 0.5;
    const double r = 0.5;
    

    //lettura dati file
    fstream file;
    file.open("data3.dat", ios::in);
    if (!file.is_open()) {
        cout << "Errore apertura file!" << endl;
    }
    const int n = 1000;
    dati *punti = new dati[n];

    for (int i = 0; i < n; i++) {
        file >> punti[i].x;
        file >> punti[i].y;
    }
    file.close();

    fstream fileDentro;
    fileDentro.open("dentro.dat", ios::out);
    if (!fileDentro.is_open()) {
        cout << "Errore apertura fileDentro!" << endl;
        return -1;
    }

    fstream fileFuori;
    fileFuori.open("fuori.dat", ios::out);
    if (!fileFuori.is_open()) {
        cout << "Errore apertura file<fuori!" << endl;
        return -1;
    }
    
    for (int i = 0; i < n; i++) {
        if (distanza(x_c, y_c, r, punti[i]) == true) {
            fileDentro << punti[i].x;
            fileDentro << " ";
            fileDentro << punti[i].y;
            fileDentro << endl;
        } else {
            fileFuori << punti[i].x;
            fileFuori << " ";
            fileFuori << punti[i].y;
            fileFuori << endl;
        }
    }

    fileDentro.close();
    fileFuori.close();
    delete[] punti;

    return 0;
}

bool distanza(const double x_c, const double y_c, const double r, dati p) {
    double distance = sqrt(pow(x_c - p.x, 2) + pow(y_c - p.y, 2));
    if (distance < r) {
        return true;
    } else {
        return false;
    }
}
