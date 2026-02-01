#include <iostream>
#include <string>
using namespace std;

int main(){

    //dichiaro variabili
    char nome[20];
    string cognome;
    int matricola;

    //chiedo info a utente
    cout << "Inserisci nome ";
    cin >> nome;

    cout << "Inserisci cognome ";
    cin >> cognome;
    
    cout << "Inserisci matricola ";
    cin >> matricola;

    //stampo info a schermo
    cout << cognome << " " << nome << " e' registrato con numero matricola: " << matricola << endl;

    return 0;
}