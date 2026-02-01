#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "        Calcolatore successione di Fibonacci      " << endl;
    cout << "Digita quanti elementi della succcessione desideri calcolare: ";
    cin >> n;
    int a = 0, b = 1, c;
    if (n <= 0) {
        cout << "Inserisci numero positivo" << endl;
    } else if (n >= 1) {
        cout << a << endl;
    } else if (n >=2) {
        cout << b << endl;
    }
    for (int i = 2; i < n; i++) {
        c = a + b;

        cout << c << endl;
        a = b;
        b = c;
        }
        
    
    return 0;
}