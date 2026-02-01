//#include <iostream>
//using namespace std;

/*//iterazione standard: stampa i numeri da 0 a 10 e da 10 a 0
int main() {

    //inizializza i=0' continua finche' i <=10, incremento i di 1 dopo ogni loop
    for (i=0; i<=10; i++) {
        cout << i << " "; //Output: 0 1 2 3 4 5 6 7 8 9 10
    }
    for (j=10; j >= 0; j--) {
        cout << i << " "; //Output: 10 9 8 7 6 5 4 3 2 1 0
    }
    return 0;
}*/

/*//iterazione con passo personalizzato: stampa i numeri dispari

int main () {

    //stampa i numeri dispari da 1 a 15
    for (int k=1; k<16; k+=2) {
        cout << k << " "; //Output: 1 3 5 7 9 11 13 15
    }
    return 0;
}*/

/*//Ciclo infinito: condizione sempre vera o omessa, richiede istruzione break per uscire

int main() {

    //Non c'e' condizione: e' sempre vera
    for(;;) {
        // ... operazioni ...
        if (condizione_uscita) {
            break;
        }
    }
    return 0;
}*/

/*//calcolare media

int main() {
    //calcolare media di 5 numeri
    int n = 5;
    double sum = 0, x;

    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
    }
    cout << "Media: " << sum / n << endl;
    return 0;
}*/

/*//Calcolare media per numero indeterminato di elementi

int main() {
    int n = 0;
    double sum = 0, x;

    for (;;) {
        cin >> x;
        if (cin.eof()) break; //End-of-file: inviare un CTRL + D
        sum += x;
        n++;
    }
    cout << "Media: " << sum / n << endl;
    return 0;
}*/

/*//Calcolo media per numero indeterminato di elementi da file

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int = n;
    double sum = 0, x;

    fstream f;
    if (!f.is_open()) {
        cout << "Errore apertura file!" << endl;
        return -1;
    }

    for (;;) {
        f >> x;
        if (f.eof()) break;
        sum += x
        n++;
    }

    f.close():
    cout << "Media: " << sum / n << endl;
    return 0;
}*/

/*//Lettura di numeri finche' l'utente non termina l'input

#include <iostream>
using namespace std;

int main() {
    double sum = 0, x;
    int count + 0;

    //l'espressione "cin >> x" e' true se la lettura ha successo
    //diventa false in caso di errore di input o EOF

    while (cin >> x) {
        sum += 0;
        count ++;

    }

    //oppure

    while (!cin.eof()) {
        cin >> x;
        sum += x;
        count ++;
    }

    if (count > 0) {
        cout << "Media: " << sum / count << endl;
    }
} */

/*//Richiesta di input valido nell' intervallo [1,10]

#include <iostream>
using namespace std;

int main () {
    int choice;
    do {
        cout << "Inserisci un numero tra 1 e 10: ";
        cin >> choice;
    } while (choice < 1 || choice > 10); //ripeti se l'input non e' valido
    cout << "Hai scelto: " << choice << endl;
    return 0;
} */

/* //Stampa di una griglia (Matrice 3x3)
#include <iostream>
using namespace std;

int main () {
    //ciclo esterno per le righe (i)
    for (int i =0; i<3; i++) {
        //ciclo interno per le colonne (j)
        for (int j=o; j<3; j++) {
            //stampa coordinate (i, j) sulla stessa riga
            cout << "(" << i << ", " << j << ")";

        }
        cout << endl; //vai a capo dopo che la riga i e' completa
    } /*Output:
        (0,0) (0,1) (0,2)
        (1,0) (1,1) (1,2)
        (2,0) (2,1) (2,2)

        */

/*//esempio usi di break e continue

#include <iostream>
using namespace std;
int main() {
    //iterazione da 1 a 10
    for (int i=0; i<11; i++) {

        //1. uso di continue: salta i numeri pari
        if (i%2 == 0) {
            continue;
        }

        //2. uso di break: Interrompi se i = 7
        if (i == 7) {
            break;
        }
    }
} */
