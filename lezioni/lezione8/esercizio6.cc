#include <iostream>
using namespace std;

struct date {
  int giorno;
  int mese;
  int anno;
};

struct evento {
  string nome;
  date data_evento;
};

void stampa_evento(evento *e);

int main() {
    evento e = {"Compleanno", {10, 12, 2025}};
    stampa_evento(&e);


    return 0;
}

void stampa_evento(evento *e) { // Passaggio per puntatore
    cout << "Dettagli evento: " << e->nome << endl;
    cout << "Data: " << e->data_evento.giorno << "/" 
                   << e->data_evento.mese << "/" 
                   << e->data_evento.anno << endl;
}