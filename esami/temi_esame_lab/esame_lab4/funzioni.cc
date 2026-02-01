#include "funzioni.h"
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

void simulaCaduta(pacco &p){

    double ftime = sqrt(2*p.z0/GRAV);
    p.xf = p.x0 + p.vx * ftime;
    p.yf = p.y0 + p.vy * ftime;

}

void desc_pacco(const pacco *p, const int index, stringstream &ss) {
    ss << " | Pacco " << setw(3) << index + 1 << ": ";
    ss << " | Posizione aereo: " << left << setprecision(3) << setw(5) << p[index].x0  << left << setprecision(3) << setw(5) << p[index].y0 << left << setprecision(3) << setw(5) << p[index].z0;
    ss << " | Velocità aereo: " << right << setprecision(3) << setw(5) << p[index].vx << right << setprecision(3) << setw(5) << p[index].vy;
    ss << " | Massa e tipologia pacco: " << right << setprecision(3) << setw(4) << p[index].m << right << setw(3) << p[index].t << endl;
}

int countlines(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return -1;
    }
    string tmp;
    int count = 0;
    for (;;) {
        getline(file, tmp);
        if (file.eof()) break;
        count++;
    } 
    file.close();
    return count;
}

void desc_zone(const zona *z, stringstream &ss, const int nzone) {

    ss << " | Numero zone caricate: " << nzone << endl;
    for (int i = 0; i < nzone; i++) {
        ss << " | Zona " << setw(3) << i + 1 << ": ";
        ss << " | Coordinate centro: " << left << setw(6) << z[i].x << left << setw(6) << z[i].y;
        ss << " | Raggio: " << right << setw(6) << z[i].r << endl;
    }
}

bool falledInZone(pacco p, zona* z, int nzone) {
    for (int i = 0; i < nzone; i++) {
        double distance = sqrt(pow(p.xf - z[i].x, 2) + pow(p.yf - z[i].y, 2));
        if (distance <= z[i].r) {
            return true;
        }
    }
    return false;
}

void scrematura_pacchi(pacco* &p, int &N, zona* z, int nzone) {
    pacco* filteredPacchi = new pacco[N];
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (falledInZone(p[i], z, nzone)) {
            filteredPacchi[count] = p[i];
            count++;
        }
    }
    delete[] p;
    p = filteredPacchi;
    N = count;
}

void quantita_aiuti(const pacco* p, int N, stringstream &ss) {
    int countA = 0, countC = 0, countM = 0;
    for (int i = 0; i < N; i++) {
        if (p[i].t == 'A') {
            countA++;
        } else if (p[i].t == 'C') {
            countC++;
        } else if (p[i].t == 'M') {
            countM++;
        }
    }
    ss << " | Quantità aiuti consegnati per tipologia:" << endl;
    ss << " | Tipologia A: " << countA << " Kg" << endl;
    ss << " | Tipologia C: " << countC << " Kg" << endl;
    ss << " | Tipologia M: " << countM << " Kg" << endl;
}