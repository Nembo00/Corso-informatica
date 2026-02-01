#include <iostream>
using namespace std;

int main() {
    int n;
    //chiedi a utente numero n
    cout << "Inserisci numero intero: ";
    cin >> n;

    bool risultato = (n%2) == 0;
    cout << "Il resto tra numero e 2 = " << n%2 << endl;
    cout << "Il numero e' pari? A: " << risultato << endl;

    if (risultato) {
        cout << "Il numero e' pari" << endl;
    } else {
         cout << "Il numero e' dispari" << endl;
    }
    return 0;
   
}