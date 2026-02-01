#pragma once
#include <sstream>

struct stella {
char id[21];
float magnitudine_apparente;
char tipo_spettrale[6];
float parallasse; // in milliarcosecondi
int num_osservazioni;
float *osservazioni; // array di misure
};

struct catalogo {
int num_stelle; // n. stelle nel catalogo (N)
stella *elenco_stelle; // array di stelle
};

void print_info_stelle(const catalogo &a, const int index, std::stringstream &ss);
void stelle_vicine(const catalogo &a, std::stringstream &ss);
void stelle_variabili(const catalogo &a, bool *b, std::stringstream &ss);
float get_max_magnitude(const catalogo &a, const int index);
float get_min_magnitude(const catalogo &a, const int index);
void get_abs_mag(const catalogo &a, float *b);
void sort_stelle_by_absmag(catalogo &a, float b[], std::stringstream &ss);
void print_id_m_M(const catalogo &a, const float *b, std::stringstream &ss);