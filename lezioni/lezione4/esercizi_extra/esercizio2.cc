#include <iostream>
using namespace std;

int main() {
    //chiedo anno
    int anno;
    cout << "       E' Bisestile?       " << endl;
    cout << "Inserisci un anno per vericare se esso sia bisestile: " << endl;
    cin >> anno;
    cout << "Anno selezionato: " << anno << endl;
    
    //Condizioni per anno bisestile
    if (anno % 400 == 0) {
        cout << "L'anno: " << anno << " e' bisestile!" << endl;
    } else if (anno % 4 == 0 && anno % 100 != 0) {
        cout << "L'anno: " << anno << " e' bisestile!" << endl;
    } else {
        cout << "L'anno: " << anno << " non e' bisestile!" << endl;
    }
    return 0;
}