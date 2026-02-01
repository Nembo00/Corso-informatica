#include <iostream>
using namespace std;

bool collatz(int n) {
    int i = 0;
    while (n > 1 && i < 100) {
        if(n % 2 == 0) n = n / 2;
        else n = (3*n) + 1;
        i++;
        }  
    if (n == 1) return true;
    else return false;
}

int main () {
    int corrente;
    int minimo = -1;
    cout << "Inserisci una sequenza di interi (0 per terminare): " << endl;
    do{
        cin >> corrente;
        if (corrente < 0) continue;
        if (corrente > 0 && collatz(corrente)) {
            if (minimo == -1 || corrente < minimo) {
                minimo = corrente;
            }
        }
    } while (corrente != 0);
    if (minimo != -1) {
        cout << "Il piu' piccolo intero positivo valido e': " << minimo << endl;
    } else {
        cout << "Nessun numero inserito soddisfa i criteri." << endl;
    }
    return 0;
}