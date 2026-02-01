#include "funzioni.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    // Variabili
    stringstream ss;
    string fileLanci = "lanci.dat";
    string fileZone = "zone.dat";
    
    // Caricamento dati pacchi
    ifstream fileIn(fileLanci);
    if(!fileIn.is_open()) {
        cerr << "Errore apertura file: " << fileLanci << endl;
        return -1;
    }
    int N = 65;
    pacco* p = new pacco[N];

    for(int i = 0; i < N; i++) {
        fileIn >> p[i].x0 >> p[i].y0 >> p[i].z0;
        fileIn >> p[i].vx >> p[i].vy;
        fileIn >> p[i].m;
        fileIn >> p[i].t;
        p[i].xf = 0;
        p[i].yf = 0;
    }
    fileIn.close();

    // Assegnazione valori xf e yf
    for(int i = 0; i < N; i++) {
        simulaCaduta(p[i]);
    }

    // Caricamento dati zone
    int nzone = countlines(fileZone);
    if(nzone == -1) {
        cerr << "Errore apertura file: " << fileZone << endl;
        return -1;
    }

    zona *z = new zona[nzone];

    
    

    ifstream fileZoneIn(fileZone);
    for(int i = 0; i < nzone; i++) {
        fileZoneIn >> z[i].x >> z[i].y >> z[i].r;
    }
    fileZoneIn.close();

    // Scrematura pacchi
    scrematura_pacchi(p, N, z, nzone);

    // Output richieste
    ss << "========== Richiesta 1 ==========" << endl;
    ss << " (i) Numero pacchi caricati: " << N << endl;
    desc_pacco(p, 0, ss);
    desc_pacco(p, N-1, ss);
    ss << endl << endl;

    ss << "========== Richiesta 2 ==========" << endl;
    ss << " | Valori xf e yf caricati!" << endl << endl;
    ss << endl << endl;

    ss << "========== Richiesta 3 ==========" << endl;
    desc_zone(z, ss, nzone);
    ss << endl << endl;

    ss << "========== Richiesta 4 ==========" << endl;
    ss << " | Scrematura pacchi effettuata" << endl;
    ss << endl << endl;

    ss << "========== Richiesta 5 ==========" << endl;
    quantita_aiuti(p, N, ss);
    ss << endl << endl;


    string output = ss.str();
    cout << output;

    ofstream fileOut("risultati.dat");
    if(fileOut.is_open()) {
        fileOut << output;
        fileOut.close();
    } else {
        cerr << "Errore apertura file di output!" << endl;
    }

    return 0;
}