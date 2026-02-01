#ifndef AIUTI_H
#define AIUTI_H

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

#endif
