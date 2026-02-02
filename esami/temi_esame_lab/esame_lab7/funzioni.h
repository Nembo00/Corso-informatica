#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <sstream>
#include <string>

struct voto {
int cod; //codice esame
int cre; //numero crediti esame
int matr; //matricola studente
int val; //voto conseguito
};

struct studente {
int matr; //matricola studente
int cre; //numero crediti conseguiti
float wm; //media pesata
int nfails; //numero esami falliti
bool is_out; //true: espulso
};

int countlines(const std::string& filename);
void print_info_voto(const voto *v, const int n, std::stringstream& ss);
void print_desc_voto(const voto *v, const int n, std::stringstream& ss);
void get_is_out_stat(studente *s, const int n);
void print_studente_espulso(const studente *s, const int n, std::stringstream& ss);
void print_studenti_caricati(const studente *s, const int n, std::stringstream& ss);
int get_new_n_studente(studente *s, const int n);
void screma_arr_studenti_e_sort(studente *s, const int n, std::stringstream& ss);
void get_new_desc(studente *s, const int n, const voto *v, const int m);

#endif