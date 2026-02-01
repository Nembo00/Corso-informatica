#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <sstream>
#include <string>

struct evento {
double p1[4]; // energia-momento particella 1 (E1, p1x, p1y, p1z)
double p2[4]; // energia-momento particella 2 (E2, p2x, p2y, p2z)
bool segnale; // Segnale se 1|true, background se 0|false
double massainv; // Massa invariante
};

int countlines(const std::string& filename);
void print_info(const evento *e, const int n, std::stringstream& ss);
void get_massainv(evento *e, const int n);
void print_massainv(const evento *e, const int n, std::stringstream& ss);
void info_evento(const evento *e, const int n, std::stringstream& ss);
void sort_by_massainv(evento *e, const int n);
void statistiche_eventi(const evento *e, const int n, std::stringstream& ss);


#endif