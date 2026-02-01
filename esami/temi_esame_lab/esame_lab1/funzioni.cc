#include "funzioni.h"
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int countLines(const string& filename) {
    fstream file(filename, ios::in);
    if (!file.is_open()) {
        return -1;
    }
    string tmp;
    int count = 0;
    
    while (getline(file, tmp)) {
        count++;
    }
    file.clear();
    file.seekg(0);
    file.close();
    return count;
}

void primeTrePosizioni(const traj &A, const int index, stringstream& ss) {
    ss << "Prime tre posizioni traiettoria " << index << " : ";
    for(int i = 0; i < 3; i++) {
        ss << A.path[i] << " ";
    }
    ss << endl;
}

void ultimeTrePosizioni(const traj &A, const int index, stringstream& ss) {
    ss << "Ultime tre posizioni traiettoria " << index << " : ";
    for(int i = A.npoints - 3; i < A.npoints; i++) {
        ss << A.path[i] << " ";
    }
    ss << endl;
}

int scrematuraSample(traiettorie &A, stringstream& ss) {
    int counter_eliminate = 0;
    int index_eliminata = 0;
    for(int i = 0; i < A.ntraj; i++) {
        for(int j = 0; j < A.sample[i].npoints - 1; j++) {
            if(A.sample[i].path[j] == A.sample[i].path[j + 1]) {
                index_eliminata = i + 1;
                counter_eliminate++;

                ss << " (i) Posizione originale traiettoria eliminata: " << index_eliminata << endl;
                primeTrePosizioni(A.sample[i], index_eliminata, ss);
                ultimeTrePosizioni(A.sample[i], index_eliminata, ss);

                delete[] A.sample[i].path;
                A.sample[i].path = nullptr;
                break;

            }
        }
    }
    ss << "Traiettorie Eliminate: " << counter_eliminate << endl;
    return counter_eliminate;
}

void primeTrePosVettori(const double *v,const string& vtrname, stringstream& ss) {
    ss << "Prime tre posizioni vettore " << vtrname << ": ";
    for(int i = 0; i < 3; i++) {
        ss << v[i] << " ";
    }
    ss << endl;
}

void ultimeTrePosVettori(const double *v,int M, const string& vtrname, stringstream& ss) {
    ss << "Ultime tre posizioni vettore " << vtrname << ": ";
    for(int i = M - 2; i < M + 1; i++) {
        ss << v[i] << " ";
    }
    ss << endl;
}

void media(const traiettorie &A, double *v) {
    int S = A.ntraj;
    int n_punti = A.sample[0].npoints;

    for(int i = 0; i < n_punti; i++) {
        double somma = 0.0;
        for(int j = 0; j < S; j++) {
            somma += A.sample[j].path[i];
        }
        v[i] = somma / S;
    }
}

void std_var(traiettorie &A, const double *v, double *w) {
    int S = A.ntraj;
    int n_punti = A.sample[0].npoints;
    for(int i = 0; i < n_punti; i++) {
        double somma = 0.0;
        for(int j = 0; j < S; j++) {
            somma += pow(A.sample[j].path[i] - v[i], 2);
        }
        w[i] = somma / (S - 1);
    }

}

void ordinaPerDistanzaFinale(traiettorie &A) {
    int S = A.ntraj; // Numero di traiettorie valide [cite: 43]
    int M = A.sample[0].npoints - 1; // L'ultimo istante è M [cite: 7, 22]

    for (int i = 0; i < S - 1; i++) {
        for (int j = 0; j < S - 1 - i; j++) {
            // Calcolo della distanza finale |x_M| per le due traiettorie 
            double dist_j = fabs(A.sample[j].path[M]);
            double dist_j1 = fabs(A.sample[j+1].path[M]);

            // Se la distanza di j è maggiore di j+1, scambiamo le strutture 
            if (dist_j > dist_j1) {
                traj temp = A.sample[j];
                A.sample[j] = A.sample[j+1];
                A.sample[j+1] = temp;
            }
        }
    }
}