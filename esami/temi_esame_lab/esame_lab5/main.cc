#include "funzioni.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    stringstream ss;
    string filename = "data.dat";

    int n_misure = countlines(filename);
    misure* m = new misure[n_misure];

    ifstream fileIn(filename);
    if(!fileIn.is_open()) {
        cerr << "Errore apertura file: " << filename << endl;
        return -1;
    }
    for(int i = 0; i < n_misure; i++) {
        fileIn >> m[i].t >> m[i].vx >> m[i].vy >> m[i].vz >> m[i].K;
        m[i].massa = 0.0;
    }
    fileIn.close();

    double *val_massa = new double[n_misure];

    // Output
    ss << "========== Richiesta 1 ==========" << endl;
    ss << " | Numero misure: " << right << setw(3) << n_misure << endl;
    stampa_info(m, n_misure, ss);
    ss << endl << endl;

    ss << "========== Richiesta 2 ==========" << endl;
    sort_misure_by_t(m, n_misure, ss);
    stampa_info(m, n_misure, ss);
    ss << endl << endl;

    ss << "========== Richiesta 3 ==========" << endl;
    get_position(m, 5, ss);
    get_position(m, 10, ss);
    get_position(m, 15, ss);
    ss << endl << endl;

    ss << "========== Richiesta 4 ==========" << endl;
    get_massa(m, n_misure, val_massa, ss);
    salva_masse(val_massa, n_misure, "masse.dat");
    system("python3 plot_istogramma.py masse.dat");
    stampa_info(m, n_misure, ss);
    get_mean_stdvar(m, n_misure, ss);
    ss << endl << endl;

    string output = ss.str();
    cout << output;

    ofstream fileOut("risultati.dat");
    if(fileOut.is_open()) {
        fileOut << output;
    } else {
        cerr << "Errore creazione file" << endl;
        return -1;
    }

    delete[] val_massa;
    delete[] m;
    return 0;
}