#include "funzioni.h"
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    // Variabili
    stringstream ss;
    string filename_voti = "votiGF.dat";
    string filename_studenti = "studenti.dat";

    int n_voti = countlines(filename_voti);
    int n_studenti = countlines(filename_studenti);

    voto *v = new voto[n_voti];
    studente *s = new studente[n_studenti];

    ifstream fileIn(filename_voti);
    if(!fileIn.is_open()) {
        cerr << " Errore apertura file " << filename_voti << endl;
        return -1;
    }

    for(int i = 0; i < n_voti; i++) {
        fileIn >> v[i].cod >> v[i].cre >> v[i].matr >> v[i].val;
    }
    fileIn.close();

    ifstream fileIn_s(filename_studenti);
    if(!fileIn_s.is_open()) {
        cerr << " Errore apertura file " << filename_studenti << endl;
        return -1;
    }

    for(int j = 0; j < n_studenti; j++) {
        fileIn_s >> s[j].matr >> s[j].cre >> s[j].wm >> s[j].nfails;
    }
    fileIn_s.close();


    // Output
    ss << "========== Richiesta 1 ==========" << endl;
    print_info_voto(v, n_voti, ss);
    print_desc_voto(v, n_voti, ss);
    ss << endl << endl;

    ss << "========== Richiesta 2 ==========" << endl;
    get_is_out_stat(s, n_studenti);
    print_studenti_caricati(s, n_studenti, ss);
    print_studente_espulso(s, n_studenti, ss);
    ss << endl << endl;    

    ss << "========== Richiesta 3 ==========" << endl;
    int new_n_studenti = get_new_n_studente(s, n_studenti);
    screma_arr_studenti_e_sort(s, new_n_studenti, ss);
    ss << endl << endl; 

    ss << "========== Richiesta 4 ==========" << endl;
    get_new_desc(s, new_n_studenti, v, n_voti);
    print_studente_espulso(s, new_n_studenti, ss);
    

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
    fileOut.close();
    return 0;
}