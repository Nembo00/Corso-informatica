#include <iostream>
using namespace std;

int main() {

    //chiedo matricola a utente
    int matricola;
    cout << "       Indentificazione studente tramite matricola        " << endl;
    cout << "Inserisci numero matricola: ";
    cin >> matricola;

    //Costruisco switch contenente dati matricole
    switch (matricola) {
        case 123:
            cout << "La matricola inserita corrisponde a Tizio Caio!" << endl;
            break;
        default:
            cout << "Matricola non trovata. Riprovare." << endl;
            break;
    }
    return 0;
}