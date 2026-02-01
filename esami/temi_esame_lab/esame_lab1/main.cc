#include "funzioni.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    stringstream ss;
    string filename = "traiettorie.dat";
    traiettorie t;

    // Conta le righe del file
    int file_lines = countLines(filename);
    if (file_lines < 2) {
        cerr << "Errore: file non valido o vuoto" << endl;
        return -1;
    }
    
    t.ntraj = file_lines - 1;  // N: numero traiettorie

    // Apri il file
    ifstream fileInput(filename);
    if (!fileInput.is_open()) {
        cerr << "Errore: impossibile aprire il file " << filename << endl;
        return -1;
    }

    // Leggi M
    int M;
    fileInput >> M;
    if (fileInput.fail()) {
        cerr << "Errore nella lettura di M" << endl;
        fileInput.close();
        return -1;
    }

    // Carica le traiettorie
    t.sample = new traj[t.ntraj];
    for(int i = 0; i < t.ntraj; i++) {
        t.sample[i].npoints = M + 1;
        t.sample[i].path = new float[M + 1];
        for (int j = 0; j < M + 1; j++) {
            fileInput >> t.sample[i].path[j];
        }
    }
    fileInput.close(); 

    // ========== RICHIESTA 1 ==========
    ss << "========== Richiesta 1 ==========" << endl;
    ss << " (i) Numero traiettorie: " << t.ntraj << endl;
    ss << " (ii) Lunghezza traiettorie: " << M + 1 << endl;
    
    // Ampiezza salti
    float deltax = fabs(t.sample[0].path[1] - t.sample[0].path[0]);
    ss << " (iii) Ampiezza salti: " << deltax << endl;
    
    // Prime e ultime 3 posizioni della prima e dell'ultima traiettoria
    ss << " (iv) Prime e ultime posizioni:" << endl;
    primeTrePosizioni(t.sample[0], 1, ss); 
    ultimeTrePosizioni(t.sample[0], 1, ss);
    primeTrePosizioni(t.sample[t.ntraj - 1], t.ntraj, ss);
    ultimeTrePosizioni(t.sample[t.ntraj - 1], t.ntraj, ss);

    // ========== RICHIESTA 2 ==========
    ss << "\n========== Richiesta 2 ==========" << endl;
    
    // Scrematura
    int eliminate = scrematuraSample(t, ss);
    int S = t.ntraj - eliminate;
    
    // Crea nuovo array con solo le traiettorie valide
    traj *nuovo_sample = new traj[S];
    int k = 0;
    for (int i = 0; i < t.ntraj; i++) {
        if(t.sample[i].path != nullptr) {
            nuovo_sample[k].npoints = t.sample[i].npoints;
            nuovo_sample[k].path = t.sample[i].path;
            k++;
        } 
    }
    
    delete[] t.sample;
    t.sample = nuovo_sample;
    t.ntraj = S;

    // ========== RICHIESTA 3 ==========
    ss << "\n========== Richiesta 3 ==========" << endl;
    
    double *vmeans = new double[M + 1];
    double *vvars = new double[M + 1];

    // Calcola media
    media(t, vmeans);
    primeTrePosVettori(vmeans, "vmeans", ss);
    ultimeTrePosVettori(vmeans, M, "vmeans", ss);

    // Calcola varianza
    std_var(t, vmeans, vvars);
    primeTrePosVettori(vvars, "vvars", ss);
    ultimeTrePosVettori(vvars, M, "vvars", ss);

    // ========== RICHIESTA 4 ==========
    ss << "\n========== Richiesta 4 ==========" << endl;
    ordinaPerDistanzaFinale(t);
    ss << "Traiettorie ordinate per distanza finale crescente." << endl;

    // Output su video e file
    string output = ss.str();
    cout << output;

    ofstream fileOutput("risultati.dat");
    if (fileOutput.is_open()) {
        fileOutput << output;
        fileOutput.close();
        cout << "\nRisultati salvati in risultati.dat" << endl;
    } else {
        cerr << "Errore: impossibile creare risultati.dat" << endl;
    }

    // Libera memoria
    delete[] vmeans;
    delete[] vvars;
    for(int i = 0; i < t.ntraj; i++) {
        delete[] t.sample[i].path;
    }
    delete[] t.sample;

    return 0;
}