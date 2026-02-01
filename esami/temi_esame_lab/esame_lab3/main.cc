#include "funzioni.h"
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    stringstream ss;
    string filename = "catalogo_stellare.dat";
    catalogo c;

    ifstream fileIn(filename);
    if(!fileIn.is_open()) {
        cerr << "Errore apertura file: " << filename << endl;
        return -1;
    }

    fileIn >> c.num_stelle;
    c.elenco_stelle = new stella[c.num_stelle];

    for(int i = 0; i < c.num_stelle; i++) {
        fileIn >> c.elenco_stelle[i].id;
        fileIn >> c.elenco_stelle[i].magnitudine_apparente;
        fileIn >> c.elenco_stelle[i].tipo_spettrale;
        fileIn >> c.elenco_stelle[i].parallasse;
        fileIn >> c.elenco_stelle[i].num_osservazioni;
        c.elenco_stelle[i].osservazioni = new float[c.elenco_stelle[i].num_osservazioni];

        for(int j = 0; j < c.elenco_stelle[i].num_osservazioni; j++) {
            fileIn >> c.elenco_stelle[i].osservazioni[j];
        }
    }
    fileIn.close();

    bool* variabilita = new bool[c.num_stelle];
    float* mag_assoluta = new float[c.num_stelle];


    ss << "========== Richiesta 1 ==========" << endl;
    ss << "Numero stelle caricate: " << c.num_stelle << endl;
    print_info_stelle(c, 0, ss);
    print_info_stelle(c, c.num_stelle -1, ss);
    ss << endl;

    ss << "========== Richiesta 2 ==========" << endl;
    stelle_vicine(c, ss);
    ss << endl;

    ss << "========== Richiesta 3 ==========" << endl;
    stelle_variabili(c, variabilita, ss);
    ss << endl;

    ss << "========== Richiesta 4 ==========" << endl;
    get_abs_mag(c, mag_assoluta);
    sort_stelle_by_absmag(c, mag_assoluta, ss);
    print_id_m_M(c, mag_assoluta, ss);
    ss << endl;

    string output = ss.str();
    cout << output;

    ofstream fileOut("risultati.dat");
    if(!fileOut.is_open()) {
        cerr << "errore creazione file risultati.dat" << endl;
        return -1;
    }
    fileOut << output;
    fileOut.close();

    delete[] variabilita;
    delete[] mag_assoluta;
    for(int i = 0; i < c.num_stelle; i++) {
        delete[] c.elenco_stelle[i].osservazioni;
    }
    delete[] c.elenco_stelle;
    return 0;
}