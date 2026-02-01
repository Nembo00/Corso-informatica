#include <iostream>
using namespace std;

int main() {
    //Chiedo temperatura in gradi Celsius a utente
    double T_Celsius;
    cout << "       Programma conversione temperatura       " << endl;
    cout << "Inserisci temperatura in gradi Celsius da convertire: ";
    cin >> T_Celsius;

    //Input per selezionare programma

    int scelta;

    cout << "Digita 1 per C --> K, digita 2 per C --> F: ";
    cin >> scelta;

    //programmi per conversioni
    if (scelta == 1) {
        double T_Kelvin = T_Celsius + 273.15;
        cout << "La temperatura convertita in Kelvin e': " << T_Kelvin << " K" << endl;
    } else if (scelta == 2) {
        double T_Fahrenheit = T_Celsius * (9.0 / 5.0) + 32.0;
        cout << "La temperatura convertita in Fahrenheit e': " << T_Fahrenheit << " F" << endl;        
    } else {
        cout << "Pollo!" << endl;
    }
    return 0;
}