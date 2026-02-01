#include <iostream>
#include <fstream>
#include <cmath>
#define N 1000
using namespace std;

int main() {
    //apro file data_moto.dat in modalità lettura
    ifstream file;
    file.open("data_moto.dat", ios::in);
    if (!file.is_open()) {
        cout << "Errore apertura file!" << endl;
        return -1;
    }
    //creo vettore v
    double v[N];
    double spazio, tempo;
    //inserisco dati da file in array v
    for (int i = 0; i < N; i++) {
        file >> spazio >> tempo;
        v[i] = spazio / tempo; //carico v istantanea nel vettore v
    }
    file.close();
    //calcolo media v istantanea
    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i];
    }
    double media = sum / N;
    cout << "La media delle velocità istntanee è: " << media << " m/s" << endl;
    
    //calcolo std dev
    double sum2 = 0;
    for (int i = 0; i < N; i++) {
        sum2 += pow(v[i] - media, 2); 
    }
    double std_dev = sqrt (sum2 / (N-1));
    cout << "La std dev è: +-" << std_dev << " m/s" << endl;

    //ricerca velocità massima
    double max = v[0];
    for (int i = 1; i < N; i++) {
        if (v[i] > max) {
            max = v[i];
            
        }
    }
    cout << "La velocità massima è: " << max << " m/s" << endl;

    //ricerca valore minimo
    double min = v[0];
    for (int i = 1; i < N; i++) {
        if (v[i] < min) {
            min = v[i];
            
        }
    }
    cout << "La velocità minima è: " << min << " m/s" << endl;
    return 0;
}