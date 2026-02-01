#include <iostream>
#include <cmath>
using namespace std;

int main () {
    //richiesta variabili a utente per calcolo eq secondo grado
    double a, b, c;
    cout << "       Calcolatore soluzioni per  ax^2 + bx + c = 0      " << endl;
    cout << "Inserisci valori di a, b, c: " << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    //Calcolo discriminante per distinzione casi + blocchi if else per calcolo soluzioni
    double delta = pow (b, 2) - (4 * a * c);
    cout << delta << endl;

    if (delta > 0) {
        double x1_dmaggiore = ((-1 * b) - sqrt(delta)) / (2 * a);
        double x2_dmaggiore = ((-1 * b) + sqrt(delta)) / (2 * a);  
        cout << "L'equazione ha 2 radici reali e distinte" << endl;
        cout << "Le radici sono: x1 = " << x1_dmaggiore << " e x2 = " << x2_dmaggiore << endl;
    } else if (delta == 0) {
        double x1_2_dUguale = (-1 * b) / (2 * a);
        cout << "L'equazione ha 2 radici reali e coincidenti" << endl;
        cout << "Le radici sono: x1,2 = " << x1_2_dUguale << endl;
    } else {
        double p_reale = (-1 * b) / (2 * a);
        double p_immaginaria = sqrt(fabs(delta)) / (2 * a);
        double x1_dMinore = p_reale - p_immaginaria;
        double x2_dMinore = p_reale + p_immaginaria;
        cout << "L'equazione ha 2 radici complesse coniugate" << endl;
        cout << "Le radici sono: x1 = " << p_reale << "-" << p_immaginaria << "i e x2 = " << p_reale << "+" << p_immaginaria << "i" << endl;

    }
    return 0;
}