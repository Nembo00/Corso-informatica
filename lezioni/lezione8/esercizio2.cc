#include <iostream>
#include <string>
using namespace std;

struct prodotto{
    int peso;
    double prezzo;
    string nome;
};

void fattura(prodotto *p, int size);


int main() {
    const int n = 4;
    prodotto *p = new prodotto[n];

    for (int i = 0; i < 4; i++) {
        cout << "Inserisci nome prodotto: ";
        cin >> p[i].nome;
        cout << "Inserisci prezzo prodotto: ";
        cin >> p[i].prezzo;
        cout << "Inserisci peso prodotto: ";
        cin >> p[i].peso;
    }
    
    fattura(p, 4);
    delete[] p;
    return 0;
}

void fattura(prodotto *p, int size) {
    double prezzo_totale = 0;
    for (int size = 0; size < 4; size++) {
        prezzo_totale += p[size].prezzo;
    }
    cout << "Fattura" << endl;
    cout << "-------------------------" << endl;
    cout << "Nome           Peso        Prezzo" << endl;
    for (int size = 0; size < 4; size++) {
    cout << p[size].nome << "           " << p[size].peso << "        ";
    cout << p[size].prezzo << endl;
    }
    cout << "-------------------------" << endl;
    cout << "Totale (euro): " << prezzo_totale << endl;
    cout << "-------------------------" << endl;


    
}