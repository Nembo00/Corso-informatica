#include <iostream>
#include <string>
using namespace std;

struct prodotto{
    int peso;
    double prezzo;
    string nome;
};

void stampa_prodotto(prodotto p);

int main() {
    prodotto banana = {200, 2.5, "banana"};

    stampa_prodotto(banana);
    return 0;
}

void stampa_prodotto(prodotto p) {
    cout << "Prodotto:" << endl;
    cout << "  - Nome: " << p.nome << endl;
    cout << "  - Peso: " << p.peso << endl;
    cout << "  - Prezzo: " << p.prezzo << endl;
}
