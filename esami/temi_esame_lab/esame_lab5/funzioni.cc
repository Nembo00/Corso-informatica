#include "funzioni.h"
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int countlines(const string& filename) {
    ifstream file(filename);
    if(!file.is_open()) return -1;
    string tmp;
    int count = 0;
    for(;;) {
        getline(file, tmp);
        if (file.eof()) break;
        count++;
    }
    file.close();
    return count;
}

void stampa_info(const misure *m, const int n, stringstream &ss) {
    for(int i = 0; i < n; i++) {
        ss << " | Istante: " << right << setw(4) << m[i].t;
        ss << " | Velocità: " << left << setw(12) << m[i].vx << left << setw(12) << m[i].vy << left << setw(12) << m[i].vz;
        ss << " | Energia Cinetica: " << left << setw(6) << m[i].K;
        ss << " | Massa: " << left << setw(4) << m[i].massa << endl;
        }
}

void sort_misure_by_t(misure *m, const int n, stringstream &ss) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(m[i].t > m[j].t) {
                misure tmp = m[i];
                m[i] = m[j];
                m[j] = tmp;
            }
        }
    }
}

void get_position(const misure *m, const int index, stringstream &ss) {
    double x, y, z;
    x = m[index].vx * m[index].t;
    y = (m[index].vy * m[index].t) + (pow(m[index].t, 2) / 0.5);
    z = (m[index].t) * sqrt(m[index].vz);

    ss << " | Istante: " << right << setw(4) << m[index].t;
    ss << " | Posizione (x, y, z): " << left << setw(12) << x << left << setw(12) << y << left << setw(12) << z << endl;
}

void get_massa(misure *m, const int n, double *val_massa, stringstream &ss) {
    for(int i = 0; i < n; i++) {
        val_massa[i] = (2 * m[i].K) / (pow(m[i].vx, 2) + pow(m[i].vy, 2) + pow(m[i].vz, 2));
        m[i].massa = val_massa[i]; 
    }
}

void get_mean_stdvar(const misure *m, const int n, stringstream &ss) {
    double somma = 0.0;
    for(int i = 0; i < n; i++) {
        somma += m[i].massa;
    }
    double mean = somma / n;

    double somma_std = 0.0;
    for(int j = 0; j < n; j++) {
        somma_std += pow((m[j].massa - mean), 2);
    }
    double std_var = sqrt(somma_std / n);

    ss << " | Valor medio massa: " << setw(7) << mean;
    ss << " | Deviazione Standard: " << setw(7) << std_var << endl;
}


//facoltativo: serve per grafico con pythoon/matplotlib

void salva_masse(const double *val_massa, const int n, const string& filename) {
    ofstream file(filename);
    if(file.is_open()) {
        for(int i = 0; i < n; i++) {
            file << val_massa[i] << endl;
        }
        file.close();
    }
}
