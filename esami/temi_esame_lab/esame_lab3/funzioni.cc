#include "funzioni.h"
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

void print_info_stelle(const catalogo &a, const int index, stringstream &ss) {
    ss << " | ID: " << left << setw(22) << a.elenco_stelle[index].id;
    ss << " | Magnitudine apparente: " << right << setw(7) << a.elenco_stelle[index].magnitudine_apparente;
    ss << " | Tipo spettrale: " << right << setw(7) << a.elenco_stelle[index].tipo_spettrale << endl;
}

void stelle_vicine(const catalogo &a, stringstream &ss) {
    for(int i = 0; i < a.num_stelle; i++) {
        float distanza = 1000/a.elenco_stelle[i].parallasse;
        if(distanza < 20) {
            ss << " | ID: " << left << setw(22) << a.elenco_stelle[i].id;
            ss << " | Distanza(mas): " << right << fixed << setw(5) << setprecision(2) << distanza << " mas" << endl;
        }
    }
}

float get_max_magnitude(const catalogo &a, const int index) {
    float max = a.elenco_stelle[index].osservazioni[0];
    for(int i = 0; i < a.elenco_stelle[index].num_osservazioni; i++) {
        if(a.elenco_stelle[index].osservazioni[i] > max) {
            max = a.elenco_stelle[index].osservazioni[i];
        }
    }
    return max;
}

float get_min_magnitude(const catalogo &a, const int index) {
    float min = a.elenco_stelle[index].osservazioni[0];
    for(int i = 0; i < a.elenco_stelle[index].num_osservazioni; i++) {
        if(a.elenco_stelle[index].osservazioni[i] < min) {
            min = a.elenco_stelle[index].osservazioni[i];
        }
    }
    return min;
}

void stelle_variabili(const catalogo &a, bool *b, stringstream &ss) {
    for(int i = 0; i < a.num_stelle; i++) {
        float differenza = fabs(get_max_magnitude(a, i) - get_min_magnitude(a, i));
        if(differenza > 0.05) {
            b[i] = true;
        } else {
            b[i] = false;
        }
    }
    for(int j = 0; j < 10; j++) {
        ss << " | ID: " << left << setw(22) << a.elenco_stelle[j].id;
        if(b[j] == true) {
            ss << " | Stato variabilità: Variabile" << endl;
        } else {
            ss << " | Stato variabilità: Stabile" << endl;
        }
    }
}

void get_abs_mag(const catalogo &a, float *b) {
    for(int i = 0; i < a.num_stelle; i++) {
        b[i] = (a.elenco_stelle[i].magnitudine_apparente) - (5)*log10((1000/a.elenco_stelle[i].parallasse)) + 5;
        // M = m - 5* log10(1000/p) + 5
    }
}

void sort_stelle_by_absmag(catalogo &a, float b[], stringstream &ss) {
    for(int i = 0; i < a.num_stelle - 1; i++) {
        for(int j = i + 1; j < a.num_stelle; j++) {
            if(b[i] > b[j]) {
                stella tmp = a.elenco_stelle[i];
                a.elenco_stelle[i] = a.elenco_stelle[j];
                a.elenco_stelle[j] = tmp;
                float tmp_mag = b[i];
                b[i] = b[j];
                b[j] = tmp_mag;
            }
        }
    }
}

void print_id_m_M(const catalogo &a, const float *b, stringstream &ss) {
    for(int i = 0; i < 6; i++) {
        ss << " | ID: " << left << setw(22) << a.elenco_stelle[i].id;
        ss << " | Magnitudine apparente: " << right << fixed << setw(6) << setprecision(2) << a.elenco_stelle[i].magnitudine_apparente;
        ss << " | Magnitudine assoluta: " << right << fixed << setw(6) << setprecision(2) << b[i] << endl;
    }
}

