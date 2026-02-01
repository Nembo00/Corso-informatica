#include "funzioni.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main() {
    stringstream ss;  //Per mandare a video e in file risultati.dat
    string filename = "sensori.dat";
    dati_sensori ds;

    ifstream fileIn(filename);
    if(!fileIn.is_open()) {
        
     cerr << "Errore apertura file " << filename << endl;   return -1;
    }

    fileIn >> ds.num_sensori;  //S: numero sensori

    ds.elenco_sensori = new sensore[ds.num_sensori];

    for(int i = 0; i < ds.num_sensori; i++) {
        
        fileIn >> ds.elenco_sensori[i].id;
        fileIn >> ds.elenco_sensori[i].num_letture;
        ds.elenco_sensori[i].dati = new lettura[ds.elenco_sensori[i].num_letture];
        
        for(int j = 0; j < ds.elenco_sensori[i].num_letture; j++) {
            fileIn >> ds.elenco_sensori[i].dati[j].temperatura;
            fileIn >> ds.elenco_sensori[i].dati[j].umidita;
        }
    }

    fileIn.close();

    float* media_umid = new float[ds.num_sensori];

    ss << "========== Richiesta 1 ==========" << endl;
    ss << "(i) Numero sensori caricati: " << ds.num_sensori << endl;
    ss << "(ii) " << endl << endl;
    print_id_and_nread(ds, 0, ss);
    print_id_and_nread(ds, ds.num_sensori - 1, ss);

    ss << "========== Richiesta 2 ==========" << endl;
    media_temp(ds, ss);

    ss << "========== Richiesta 3 ==========" << endl;
    media_umidita(ds, media_umid, ss);

    ss << "========== Richiesta 4 ==========" << endl;
    sort_sensori(ds, ss);

    //Debug
    /*
    for(int i = 0; i < ds.num_sensori; i++) {
       ss << ds.elenco_sensori[i].num_letture << endl;
       ss << ds.elenco_sensori[i].id << endl;
    }
    */

    string output = ss.str();
    cout << output;

    ofstream fileOut("risultati.dat");
    if(!fileOut.is_open()) {
        cerr << "Errore creazione file" << endl;
        return -1;
    }
    fileOut << output;
    fileOut.close();

    delete[] media_umid;
    for (int i = 0; i < ds.num_sensori; i++) {
        delete[] ds.elenco_sensori[i].dati;
    }
    delete[] ds.elenco_sensori;


    return 0;
}