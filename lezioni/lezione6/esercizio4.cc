#include <iostream>
#include <fstream>
#include <cmath>
#define N 10000
using namespace std;

int main() {
    //apertura file e lettura dati
    ifstream file;
    file.open("data_higgs.dat", ios::in);
    if (!file.is_open()) {
        cout << "Errore apertura file!" << endl;
        return -1;
    } 
    // definisco vettore mass e carico elementi da file a vettore
    double *mass = new double [N];  
    for (int i = 0; i < N; i++) {
        file >> mass[i];
    }
    file.close();
    //Selection sort crescente per vettore mass + cout valore max e min
    for (int j = 0; j < N-1; j++) {
        for (int k = j + 1; k < N; k++) {
            if (mass[j] > mass[k]) {
                double tmp = mass[j];
                mass[j] = mass[k];
                mass[j] = tmp;
            }
        }
    }
    const double massmin = mass[0];
    const double massmax = mass[9999];
    cout << "Valore minimo: " << massmin <<  endl;
    cout << "Valore massimo: " << massmax << endl;

    //creazione array din bins che contiene upper edge
    int nbins = int((massmax - massmin) / 5) + 1; //+1 per prendere anche ultimo upper edge
    double *bins = new double[nbins];
    int *freq = new int[nbins];

    //riempimento bins
    for (int i = 0; i < nbins; i++) {
        bins[i] = mass[0] + i * 5.0; //binning con lower edges
        freq[i] = 0;
    }

    //istogrammare

    for (int i = 0; i < N; i++) {
        for (int b = 0; b < nbins; b++) {
            if (mass[i] <= bins[b+1]) { //prendo upper edge del bin come soglia
                freq[b]++;
                break;
            }
        }
    }

    //stampare l'istogramma
    cout << endl;
    cout << "Istogramma: " << endl;
    for (int b = 0; b < nbins; b++) {
        cout << "M = " << bins[b] << " GeV -> " << freq[b] << endl;
    }

    //indice in cui frequenza è massima
    int fmax = 0;
    int freqmax = freq[0];

    for (int i = 0; i < nbins; i++) {
        if (freq[i] > freqmax) {
            fmax = i;
            freqmax = freq[i];
        }
    }
    cout << endl;
    cout << "Valore del bin più frequente M = " << bins[fmax]
         << " GeV con freq = " << freq[fmax] << endl;

    delete[] mass;
    delete[] bins;
    delete[] freq;
    return 0;
}