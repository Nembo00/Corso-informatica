#include <iostream>
using namespace std;

int main() {
    int n;
     const int r=2; 
    //chiedi a utente numero n
    cout << "Inserisci numero: ";
    cin >> n;

    //Operazioni su numero inserito
    int incremento  = ++n;
    int decremento  = --n;
    int divisione = n/r;
    int resto = n%r;

    //Risultati a schermo
    cout << "Numero inserito: " << n << endl;
    cout << "Incremento numero: " << incremento << endl;
    cout << "Decremento numero: " << decremento << endl;
    cout << "Divisione per 2: " << divisione << endl;
    cout << "Resto divisione: " << resto << endl;

    return 0;
}

// incremnto = n;
// decremento = n;
// incremento++;
// decremento--;