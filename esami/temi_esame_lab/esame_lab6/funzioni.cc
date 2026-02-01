#include "funzioni.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <fstream>
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

void print_info(const evento *e, const int n, stringstream& ss) {
    int n_segnale = 0;
    int n_background = 0;
    for(int i = 0; i < n; i++) {
        if(e[i].segnale == true) {
            n_segnale++;
        } else {
            n_background++;
        }
    }
    ss << " | Eventi segnale: " << n_segnale << endl;
    ss << " | Eventi background: " << n_background << endl;
    ss << " | Percentuale eventi segnale: " << right << setprecision(4) << (n_segnale*100.0)/n << "%" << endl;
    ss << " | Percentuale eventi background: " << right << setprecision(4) << (n_background*100.0)/n << "%" << endl;
}

void get_massainv(evento *e, const int n) {
    for(int i = 0; i < n; i++) {
        double E_tot = e[i].p1[0] + e[i].p2[0];
        double px_tot = e[i].p1[1] + e[i].p2[1];
        double py_tot = e[i].p1[2] + e[i].p2[2];
        double pz_tot = e[i].p1[3] + e[i].p2[3];

        double modulo_p_quadro = px_tot*px_tot + py_tot*py_tot + pz_tot*pz_tot;

        e[i].massainv = sqrt(E_tot*E_tot - modulo_p_quadro);
    }
}

void print_massainv(const evento *e, const int n, std::stringstream& ss) {
    for(int i = 0; i < n; i++) {
        ss << " | Massa invariata evento " << right << setw(3) << i + 1 << ": ";
        ss << " | " << right << setw(10) << e[i].massainv << endl;
    }
}

void info_evento(const evento *e, const int n, stringstream& ss) {
    for(int i = 0; i < n; i++) {        
        if (i < 4 || i >= n - 4) {
            ss << " | Massa invariante evento " << right << setw(5) << i + 1 << ": " << fixed << setprecision(2) << e[i].massainv << endl;
            if(e[i].segnale) {
                ss << " | Tipo evento: Segnale" << endl;
            } else {
                ss << " | Tipo evento: Background" << endl;
            }
            ss << " | Info particella 1: " << left << setw(10) << e[i].p1[0] << left << setw(10) << e[i].p1[1] << left << setw(10) << e[i].p1[2] << left << setw(10) << e[i].p1[3] << endl;
            ss << " | Info particella 2: " << left << setw(10) << e[i].p2[0] << left << setw(10) << e[i].p2[1] << left << setw(10) << e[i].p2[2] << left << setw(10) << e[i].p2[3] << endl << endl;
        }
    }
}

void sort_by_massainv(evento *e, const int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(e[i].massainv > e[j].massainv) {
                evento temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

void statistiche_eventi(const evento *e, const int n, stringstream& ss) {
    double somma_media_segnale = 0.0;
    double somma_media_background = 0.0;
    int segnale = 0;
    int background = 0;
    for(int i = 0; i < n; i++) {
        if(e[i].segnale == true) {
            somma_media_segnale += e[i].massainv;
            segnale++;
        } else {
            somma_media_background += e[i].massainv;
            background++;
        }
    }
    double media_segnale = somma_media_segnale / segnale;
    double media_background = somma_media_background / background;
    double media = (somma_media_segnale + somma_media_background) / (segnale + background);

    double somma_std_segnale = 0.0;
    double somma_std_background = 0.0;
    for(int j = 0; j < n; j++) {
        if(e[j].segnale == true) {
            somma_std_segnale += pow((e[j].massainv - media_segnale), 2);
        } else {
            somma_std_background += pow((e[j].massainv - media_background), 2);
        }
    }
    double std_segnale = sqrt(somma_std_segnale/segnale);
    double std_background = sqrt(somma_std_background/background);
    double std = sqrt((somma_std_background + somma_std_segnale) / (segnale + background));

    double max_segnale = e[0].massainv;
    double max_background = e[0].massainv;
    for(int k = 0; k < n; k++) {
        if(e[k].segnale == true) {
            if(e[k].massainv > max_segnale) {
                max_segnale = e[k].massainv;
            }
        } else {
            if(e[k].massainv > max_background) {
                max_background = e[k].massainv;
            }
        }
    }
    double max;
    if(max_segnale > max_background) {
        max = max_segnale;
    } else {
        max = max_background;
    }

    double min_segnale = e[0].massainv;
    double min_background = e[0].massainv;
    for(int m = 0; m < n; m++) {
        if(e[m].segnale == true) {
            if(e[m].massainv < min_segnale) {
                min_segnale = e[m].massainv;
            }
        } else {
            if(e[m].massainv < min_background) {
                min_background = e[m].massainv;
            }
        }
    }
    double min;
    if(min_segnale < min_background) {
        min = min_segnale;
    } else {
        min = min_background;    
}
    ss << " | Valori per tutti gli eventi: " << endl;
    ss << " | Media massa: " << media << endl;
    ss << " | Deviazione standard massa: " << std << endl;
    ss << " | Valore massimo massa: " << max << endl;
    ss << " | Valore minimo massa: " << min << endl << endl;

    ss << " | Valori per eventi segnale: " << endl;
    ss << " | Media massa segnale: " << media_segnale << endl;
    ss << " | Deviazione standard massa segnale: " << std_segnale << endl;
    ss << " | Valore massimo massa segnale: " << max_segnale << endl;
    ss << " | Valore minimo massa segnale: " << min_segnale << endl << endl;

    ss << " | Valori per eventi background: " << endl;
    ss << " | Media massa background: " << media_background << endl;
    ss << " | Deviazione standard massa background: " << std_background << endl;
    ss << " | Valore massimo massa background: " << max_background << endl;
    ss << " | Valore minimo massa background: " << min_background << endl << endl;
}