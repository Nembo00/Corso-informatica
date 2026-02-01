        //esempi dichiarazione array stack
/*
#define N 3  //macro (costante)

int main() {
    int a[N]; //def vettore tramite macro

    //oppure
    const int M = 3;
    int b[M];

    //oppure
    int C[3]
    return 0;
} */

        //esempio calcolo media di un array

/*#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    double dat[N], sum = 0; //array di 10 double

    //caricamento elementi
    for (int i = 0; i < N; i++) {
        cin >> dat[i];
    }

    //loading sum
    for (int j = 0; j < N; j++) {
        sum += dat[j]; //somma degli elementi in dat
    }

    //media
    cout << "Media: " << sum / N << endl;

    return 0;
} */

        //caricamento di un numero imprecisato di elementi
/*
#using <iostream>
using namespace std;

int main() {
    int n = 0; //counter
    const int N = 10000; //dimensione massima consentita
    double v[N], x;

    for (;;) {
        cin >> x;
        if (cin.eof() || n > N - 1) break;
        v[N] = x;
        n++;
    }
    cout << "Numero totale elementi: " << n << endl;
    return 0;
} */

        //inizializzazione inline
/*
double p[3] = {2.0, 2.5, 3.7};
double p[] = {2.0, 2.5, 3.7}; esempio con 'char' const char cognome[] = 'Hello'
int l[10] = {0};
double v[20] = {0, 1, 2}; quindi v[20]= 0, 1, 2, 0, 0, ... , 0
*/

        //dimensione a runtime
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Inserisci la dimensione: " ;
    cin >> n;

    //allocazione dinamica nello HEAP
    int *dynamic_v = new int[n];

    //...uso dell'array

    for (int i = 0; i < n; i++) {
        cout << dynamic_v[i] << endl;
    }
    //rilascio della memoria (obbligatorio!)
    delete[] dynamic_v;
    
    return 0;
    
} */



