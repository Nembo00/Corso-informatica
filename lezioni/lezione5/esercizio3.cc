#include <iostream>
using namespace std;

/* Programma in ciclo while (sconsigliato in questo caso poiche' CTRL + D viene preso come input da else)
int main() {
    int pari = 0, dispari = 0, x;
    cout << "       Contatore numeri pari o dispari     " << endl;
    cout << "Inserisci i numeri: " << endl;
    while (!cin.eof()) {
        cin >> x;
        if (x % 2 == 0){
          pari++;  
        } else {
          dispari++;
        }
    }
    cout << "I numeri pari sono: " << pari << " e i numeri dispari sono: " << dispari << endl;
    return 0;
} */

//Programma in ciclo for

int main() {
    int pari = 0, dispari = 0, x;
    cout << "       Contatore numeri pari o dispari     " << endl;
    cout << "Inserisci i numeri: " << endl;
    for (;;) {
        cin >> x;
        if (cin.eof()) break;
        else if (x % 2 == 0) {
            pari++;  
        } else {
            dispari++;
        }
        
    }
    cout << "I numeri pari sono: " << pari << " e i numeri dispari sono: " << dispari << endl;
    return 0;
}