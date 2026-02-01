#include <iostream>
using namespace std;

int main() {
    //Chiedo eta', altezza e peso a utente
    int eta;
    double altezza, peso;
    cout << "       Programma telai biciclette     " << endl;
    cout << "Inserisci la tua eta', altezza(m) e peso(kg) per conoscere il telaio piu' adatto: " << endl;
    cin >> eta;
    cin >> altezza;
    cin >> peso;

    cout << "Hai scelto eta: " << eta << endl;
    cout << "Hai scelto altezza: " << altezza << endl;
    cout << "Hai scelto peso: " << peso << endl;

    //Serie di if e else per scelta telaio
    //eta <= 10
    if (eta <= 10) {
        cout << "Hai 10 anni o meno" << endl;
        cout << "Il telaio consigliato e' XS!" << endl;
    }
    //eta tra 10 e 18 compreso 
    else if (eta > 10 &&  eta <= 18) {
        cout << "Hai tra i 10 e i 18 anni" << endl;
        if (altezza <= 1.10) {
            cout << "Il telaio consigliato e' XS!" << endl;
        } else if ((altezza > 1.10 && altezza <= 1.30) && peso <= 40) {
            cout << "Il telaio consigliato e' S!" << endl;
        } else if ((altezza > 1.10 && altezza <= 1.30) && peso > 40) {
            cout << "Il telaio consigliato e' M!" << endl;
        } else if (altezza > 1.30 && altezza <= 1.60) {
            cout << "Il telaio consigliato e' M!" << endl;
        } else if (altezza > 1.60) {
            cout << "Il telaio consigliato e' L!" << endl;
        }
    }
    //eta 18+ 
    else if (eta > 18) {
        cout << "Hai piu' di 18 anni" << endl;
        if (altezza <= 1.40 || peso <= 40) {
            cout << "Il telaio consigliato e' XS!" << endl;
        } else if (altezza > 1.40 && altezza <= 1.60) {
            cout << "Il telaio consigliato e' S!" << endl;
        } else if (altezza > 1.60 && altezza <= 1.70) {
            cout << "Il telaio consigliato e' M!" << endl;
        } else if (altezza > 1.70 && altezza <= 1.90) {
            cout << "Il telaio consigliato e' L!" << endl;
        } else if (altezza > 1.90) {
            cout << "Il telaio consigliato e' XL!" << endl;
        }
    }
    return 0;
}