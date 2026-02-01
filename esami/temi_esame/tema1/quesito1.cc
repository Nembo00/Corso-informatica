#include <iostream>
using namespace std;

bool collatz(int n) {

    int i = 0;
    while (n > 1 && i < 100){
        if(n % 2 == 0) {  //Se n è pari --> n/2
            n = n / 2;
            i++;
        } else {
            n = (3*n) + 1;
            i++;
        }
    }
    if (n == 1){
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cout << "Inserisci n: ";
    cin >> n;
    bool check = collatz(n);
    if (check == true) {
        cout << "è true" << endl;
    } else {
        cout << "è false" << endl;
    }
    return 0;
}