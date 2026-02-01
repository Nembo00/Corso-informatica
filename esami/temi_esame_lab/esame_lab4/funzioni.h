#ifndef FUNZIONI_H
#define FUNZIONI_H

#include <sstream>
#include <string>
#define GRAV 9.81

struct pacco{
double x0,y0,z0; //Posizione aereo
double vx,vy; //Velocita‘ aereo
double m; //Massa pacco
char t; //Tipologia aiuto
double xf,yf; //Punto di caduta
};

struct zona{
double x,y; //Coordinate zona
double r; //Raggio zona
};

void simulaCaduta(pacco &p);
void desc_pacco(const pacco *p, const int index, std::stringstream &ss);
int countlines(const std::string& filename);
void desc_zone(const zona *z, std::stringstream &ss, const int nzone);
bool falledInZone(pacco p, zona* z, int nzone);
void scrematura_pacchi(pacco* &p, int &N, zona* z, int nzone);
void quantita_aiuti(const pacco* p, int N, std::stringstream &ss);

#endif