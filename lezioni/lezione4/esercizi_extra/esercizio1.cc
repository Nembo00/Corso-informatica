#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    //Chiedo numeri per operazione
    double a, b;
    cout << "       Calcolatrice        " << endl;
    cout << "Inserisci valore di a e b: " << endl;
    cin >> a;
    cin >> b;
    cout << "I valori inseriti sono a = " << a << " e b = " << b << endl;

    //Creazione variabile per selezionare operazione + scelta
    char operazione;
    cout << "Scegli l'operazione (+, -, *, /): ";
    cin >> operazione;

    //creazione switch per selezionare operazione
    switch (operazione) {
        case '+': //somma
            cout << "Hai scelto la somma a + b" << endl;
            cout << "La somma e': " << a + b << endl;
            break;
        case '-': //differenza
        cout << "Hai scelto la differrenza a - b" << endl;
        cout << "La differenza e': " << a - b << endl;
            break;
        case '*': //prodotto
            cout << "Hai scelto il prodotto a * b" << endl;
            cout << "Il prodotto e': " << a * b << endl;
            break;
        case '/': //rapporto
            cout << "Hai scelto il rapporto a / b" << endl;
            if (b == 0) {
                cout << "Impossibile dividere per 0" << endl;
            } else {
                cout << "Il rapporto e': " << a / b << endl;
                break;
            }
        default:
            cout << "Operazione non eseguibili" << endl;
            break;
            
    }
    cout << "Blocco switch saltato" << endl;

    return 0;
}