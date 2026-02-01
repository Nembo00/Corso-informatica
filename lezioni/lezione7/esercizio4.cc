#include <iostream>
#include <cmath>
using namespace std;



//funzione distanza: calcola distanza tra punto generico e centro del cerchio
double distanza(double x_c, double y_c, double x, double y);
//funzione check circle: assegna valore true o false se d >= r
void check_circle(double x_c, double y_c, double x, double y, double r, bool &status);


double distanza(double x_c, double y_c, double x, double y) {
    double d = sqrt(pow(x - x_c, 2) + pow(y - y_c, 2));
    return d;
}

void check_circle(double x_c, double y_c, double x, double y, double r, bool &status) {
    double distance = distanza(x_c, y_c, x, y);
    if (distance <= r) {
        status = true;
    } else {
        status = false;
    }
}


int main() {
    //variabili cerchio
    const double x_c = 1, y_c = 1, r = 1;
    bool status;
    double x, y;
    for (;;) {
        cout << "Inserisci coordinate x e y del punto: " << endl;
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;
        if (cin.eof()) break;

        check_circle(x_c, y_c, x, y, r, status);
        if (status) {
            cout << "Punto interno al cerchio!" << endl;
        } else {
            cout << "Punto esterno al cerchio!" << endl;
        }
    
    }
    return 0;
}