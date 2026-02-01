#include <iostream>
using namespace std;

int main() {
    //Chiedo a utente quantita' numeri
    int n;
    cout << "       calcolatore media di n numeri       " << endl;
    cout << "Inserisci quantita' n di numeri per sapere il loro valor medio: ";
    cin >> n;
    cout << "Stai calcolando la media di: " << n << " numeri, inseriscili uno ad uno: " << endl;
    double sum = 0, x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum +=x;
    }
    cout << "Media: " << sum / n << endl;
    return 0;
}