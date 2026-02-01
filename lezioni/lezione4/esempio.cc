/*

esempio else if

#include <iostream>
using namespace std;

int main() {
    double delta = 5.0;
    if (delta > 0) {
        cout << "Due radici reali e distinte" << endl;
    } else if (delta == 0) {
        cout << "Due radici reali e coincidenti" << endl;
    } else {
        cout << "Due radici complesse coniugate" << endl;
    }
    return 0;
}


//nested-condition

#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a > 0) {
        if (b < 50) {
            cout << "Condizione superata!" << endl;
        }
    }
    //equivalnte a 
    if ( a > 0 && b < 50) {
        cout << "Condizione superata!" << endl;
    }
    //verificare che a < 0 oppure b > 50
    if ( a > 0 || b < 50) {
        cout << "Condizione superata!" << endl;
    }
    //esempio piu' complesso: a > 0 oppure a < -5 e b > -10
    if (a > 0 || (a >-5 && b > -10)) {
        cout << "Condizione superata!" << endl;
    }

    //la condizionale inline
    int c = (a > 5) ? 2 * a : 3 * a;

    return 0;
} 

#include <iostream>
using namespace std;

int main() {
    int mese = 2; //Febbraio
    switch (mese) {
        case 4:  //Aprile
        case 6:  //Giugno
        case 9:  //Settembre
        case 11: //Novembre
            cout << "30 giorni" << endl;
            break;
        case 2:  //Febbraio
            cout << "28 o 29 giorni" << endl;
            break:
        default:
            cout << "31 giorni" << endl;
            break;
    }
    return 0;
} 

//Esempio: scope locale (crash)

#include <iostream>
using namespace std;

int main() {
    if (true) {
        double x = 5.0; // x esiste solo qui
        cout << x;
    } //x viene ELIMINATA e non esiste piu'

    cout << x; // CRASH x e' OUT OF SCOPE
    return 0;
} 

//variabile globale (costante fisica)

#include <iostream>
using namespace std;

const double G = 6.674e-11;

int main () {
    cout << "Costante gravitazionale: " << G << endl;
    return 0;
}
*/