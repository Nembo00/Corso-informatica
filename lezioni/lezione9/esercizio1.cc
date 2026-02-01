#include <iostream>
#include <fstream>
#include <cmath>
#include "funzioni.h"
using namespace std;

int main() {
    const int n = 1000;
    point2d punti[n];
    
    fstream file;
    file.open("data1.dat", ios::in);
    if(!file.is_open()) {
        cout << "Errore apertura file!" << endl;
        return -1;
    }

    for (int i = 0; i < n; i++) {
        punti[i].coordinate = new double[2];
        file >> punti[i].coordinate[0]; 
        file >> punti[i].coordinate[1];
    }
    file.close();

    for (int i = 0; i < n; i++) {
        compute_distance(punti[i]);
    }

    double media = mean(punti, n);
    cout << "Media = " << media << endl;

    double max_distanza = trova_max_distanza(punti, 1000);
    double min_distanza = trova_min_distanza(punti, 1000);

    cout << "Distanza massima: " << max_distanza << endl;
    cout << "Distanza minima: " << min_distanza << endl;              

    dealloca_punti(punti, 1000);
    return 0;
}