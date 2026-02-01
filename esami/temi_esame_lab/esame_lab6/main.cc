#include "funzioni.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    // Variabili
    stringstream ss;
    string filename = "eventi.dat";

    int n_eventi = countlines(filename);
    evento *e = new evento[n_eventi];

    ifstream fileIn(filename);
    if(!fileIn.is_open()) {
        cerr << "Errore apertura file: " << filename << endl;
        return -1;
    }

    for(int i = 0; i < n_eventi; i++) {
        fileIn >> e[i].p1[0] >> e[i].p1[1] >> e[i].p1[2] >> e[i].p1[3];
        fileIn >> e[i].p2[0] >> e[i].p2[1] >> e[i].p2[2] >> e[i].p2[3];
        fileIn >> e[i].segnale;
        e[i].massainv = 0.0;
    }
    fileIn.close();

    //Output

    ss << "========== Richiesta 1 ==========" << endl;
    ss << " | Numero eventi: " << n_eventi << endl;
    print_info(e, n_eventi, ss);
    ss << endl << endl;

    ss << "========== Richiesta 2 ==========" << endl;
    get_massainv(e, n_eventi);
    print_massainv(e, 10, ss);
    ss << endl << endl;

    ss << "========== Richiesta 3 ==========" << endl;
    sort_by_massainv(e, n_eventi);
    info_evento(e, n_eventi, ss);
    ss << endl << endl;

    ss << "========== Richiesta 4 ==========" << endl;
    statistiche_eventi(e, n_eventi, ss);
    ss << endl << endl;


    string output = ss.str();
    cout << output;

    ofstream fileOut("risultati.dat");
    if(fileOut.is_open()) {
        fileOut << output;
    } else {
        cerr << "Errore creazione file!" << endl;
        return -1;
    }
    fileOut.close();

    delete[] e;
    
    return 0;
}