#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <sstream>
#include <string>

struct misure {
int t; // instante della misura
double vx; // coordinata vx dell’oggetto
double vy; // coordinata vy dell’oggetto
double vz; // coordinata vz dell’oggetto
double K; // energia cinetica totale dell’oggetto
double massa; // massa dell’oggetto in moto
};

int countlines(const std::string& filename);
void stampa_info(const misure *m, const int n, std::stringstream &ss);
void sort_misure_by_t(misure *m, const int n, std::stringstream &ss);
void get_position(const misure *m, const int index, std::stringstream &ss);
void get_massa(misure *m, const int n, double *val_massa, std::stringstream &ss);
void get_mean_stdvar(const misure *m, const int n, std::stringstream &ss);

//facoltativo: serve per grafico con pythoon/matplotlib
void salva_masse(const double *val_massa, const int n, const std::string& filename); 
#endif 