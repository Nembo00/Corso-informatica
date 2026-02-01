#include <iostream>
#include <fstream>
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

    //creo file risultato.dat
    ofstream file ("risultato.dat");
    //apro file mod scrittura
    file.open("risultato.dat", ios::out);
    //verifico apertura file
    if (!file.is_open()) {
        cout << "Errore: impossibile aprire il file" << endl;
        return -1;
    }
    //copio info dentro file 'risultato.dat'
    file << cognome << " " << nome  << " e' registrato con numero matricola: " << matricola << endl;
    
    //chiusura file
    file.close();
    

    return 0;    
}