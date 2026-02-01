#include <iostream>
#include <string>
using namespace std;

struct prodotto{
    int peso;
    double prezzo;
    string nome;
};

prodotto* trova_maggiore(prodotto *p, int size);

int main() {
    const int n = 3;
    prodotto* p = new prodotto[n];
    for (int i = 0; i < n; i++) {
        cout << "Inserisci nome: ";
        cin >> p[i].nome;
        cout << "Inserisci prezzo: ";
        cin >> p[i].prezzo;
        cout << "Inserisci peso: ";
        cin >> p[i].peso;
    }
    prodotto *prezzo_max = trova_maggiore(p, n);
    cout << "Prodotto più costoso: " << prezzo_max -> nome << endl;
    cout << "Prezzo: " << prezzo_max->prezzo << endl;

    delete[] p;
    return 0;
}

prodotto* trova_maggiore(prodotto *p, int size) {
    prodotto* max = p;
    for (int i = 0; i < size; i++) {
        if (p[i].prezzo > max -> prezzo) {
            max = &p[i];
        }
    }
    return max;
}