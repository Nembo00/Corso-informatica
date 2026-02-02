#include "funzioni.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
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

void print_info_voto(const voto *v, const int n, stringstream& ss) {
    double sufficiente = 0.0;
    double insufficiente = 0.0;
    for(int i = 0; i < n; i++) {
        if(v[i].val >= 18) {
            sufficiente++;
        } else {
            insufficiente++;
        }
    }
    ss << " | Voti caricati: " << right << setw(5) << n;
    ss << " | Voti sufficienti: " << right << setw(5) << setprecision(2) << (sufficiente/n);
    ss << " | Voti insufficienti: " << right << setw(5) << setprecision(2) << (insufficiente/n) << endl << endl;
}

void print_desc_voto(const voto *v, const int n, stringstream& ss) {
    for(int i = 0; i < n; i++) {
        if(i < 3 || i >= n - 3) {
            ss << " | Voto " << setw(4) << i + 1 << ": ";
            ss << " | Codice: " << right << setw(10) << v[i].cod;
            ss << " | Crediti: " << right << setw(10) << v[i].cre;
            ss << " | Voto: " << right << setw(3) << v[i].val << endl;
        }
    }
}

void get_is_out_stat(studente *s, const int n) {
    for(int i = 0; i < n; i++) {
        if(s[i].nfails >= 5) {
            s[i].is_out = true;
        } else {
            s[i].is_out = false;
        }
    }
}
void print_studente_espulso(const studente *s, const int n, stringstream& ss) {
    ss << " | Studenti espulsi: " << endl;
    for(int j = 0; j < n; j++) {
        if(s[j].is_out) {
            ss << " | Matricola: " << right << setw(10) << s[j].matr;
            ss << " | Crediti: " << right << setw(6) << s[j].cre;
            ss << " | Media pesata: " << right << setw(5) << setprecision(4) << s[j].wm;
            ss << " | Tentativi falliti: " << right << setw(3) << s[j].nfails;
            ss << " | Status: Fuori" << endl;
        }
    }
}

void print_studenti_caricati(const studente *s, const int n, stringstream& ss) {
    int espulsi = 0;
    int no_espulsi = 0;
    for(int i = 0; i < n; i++) {
        if(s[i].is_out) {
            espulsi++;
        } else {
            no_espulsi++;
        }
    }
    ss << " | Numero totale studenti: " << right << setw(3) << n;
    ss << " | Numero studenti non espulsi: " << right << setw(3) << no_espulsi;
    ss << " | Numero studenti espulsi: " << right << setw(3) << espulsi << endl;
}

int get_new_n_studente(studente *s, const int n) {
    int k = 0;
    for(int i = 0; i < n; i++) {
        if(!s[i].is_out) {
            s[k] = s[i];
            k++;
        }
    }
    return k;
}

void screma_arr_studenti_e_sort(studente *s, const int n, stringstream& ss) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(s[i].matr > s[j].matr) {
                studente temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for(int m = 0; m < n; m++) {
        if(m < 3 || m > n - 4) {
            ss << " | Studente " << setw(4) << m + 1 << ": ";
            ss << " | Matricola: " << right << setw(10) << s[m].matr;
            ss << " | Crediti: " << right << setw(6) << s[m].cre;
            ss << " | Media pesata: " << right << setw(5) << setprecision(4) << s[m].wm;
            ss << " | Tentativi falliti: " << right << setw(3) << s[m].nfails << endl;
        }
    }

    
}

void get_new_desc(studente *s, const int n, const voto *v, const int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i].matr == v[j].matr) {
                if(v[j].val >= 18) {
                    // Calcolo media pesata corretta
                    float nuovi_cre = s[i].cre + v[j].cre;
                    s[i].wm = ((s[i].wm * s[i].cre) + (v[j].val * v[j].cre)) / nuovi_cre;
                    s[i].cre = nuovi_cre; // IMPORTANTE: aggiorna i crediti!
                } else {
                    s[i].nfails++;
                    // Verifica espulsione solo per questo studente
                    if(s[i].nfails >= 5) s[i].is_out = true;
                }
            }
        }
    }
}