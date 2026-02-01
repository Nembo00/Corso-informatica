#include "funzioni.h"
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;

void print_id_and_nread(const dati_sensori &a, const int index, stringstream &ss) {
    ss << " | ID: " << left << setw(12) << a.elenco_sensori[index].id << endl;
    ss << " | Letture: " << setw(5) << a.elenco_sensori[index].num_letture << endl << endl;
}

void media_temp(const dati_sensori &a, std::stringstream &ss) {
    for(int i = 0; i < a.num_sensori; i++) {
        float somma = 0;
        for(int j = 0; j < a.elenco_sensori[i].num_letture; j++) {
            somma += a.elenco_sensori[i].dati[j].temperatura;
        }
        float media = somma / a.elenco_sensori[i].num_letture;

        int countAnomalieTemp = 0;
        int indici[3];
        for(int k = 0; k < a.elenco_sensori[i].num_letture; k++) {
            if(fabs(a.elenco_sensori[i].dati[k].temperatura - media) > 7.0) {
                if(countAnomalieTemp < 3) {
                    indici[countAnomalieTemp] = k;
                }
                countAnomalieTemp++;
            }
        }
        if(countAnomalieTemp > 0) {
            ss << " | ID: " << left << setw(12) << a.elenco_sensori[i].id << endl;
            ss << " | Numero anomalie: " << setw(3) << countAnomalieTemp << endl;
            ss << " | Indici prime tre: ";
            int limite = 0;
            if(countAnomalieTemp < 3) limite = countAnomalieTemp;
            else if(countAnomalieTemp > 3) limite = 3;
            for(int m = 0; m < limite; m++) {
                ss << indici[m] << (m < limite -1 ? ", " : "");
            }
            ss << endl << endl;
        }
    }
}

void media_umidita(const dati_sensori &a, float *b, std::stringstream &ss) {
    for(int i = 0; i < a.num_sensori; i++) {
        float somma = 0;
        for(int j = 0; j < a.elenco_sensori[i].num_letture; j++) {
            somma += a.elenco_sensori[i].dati[j].umidita;
        }
            b[i] = (somma)/(a.elenco_sensori[i].num_letture);
    }
    ss << " | Media umidità primo sensore: " << fixed << setprecision(2) <<  b[0] << " %"<<endl;
    ss << " | Media umidità utlimo sensore: " << fixed << setprecision(2) <<b[a.num_sensori - 1] << " %" << endl;

}

void sort_sensori(dati_sensori &a, std::stringstream &ss) {
    for(int i = 0; i < a.num_sensori - 1; i++) {
        for(int j = i + 1; j < a.num_sensori; j++) {
            if(a.elenco_sensori[i].num_letture > a.elenco_sensori[j].num_letture) {
                sensore tmp = a.elenco_sensori[i];
                a.elenco_sensori[i] = a.elenco_sensori[j];
                a.elenco_sensori[j] = tmp;
            }
        }
    }
    ss << " | Sensori ordinati in modo crescente per numero di letture." << endl;
}