#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int n;
    double x, sum = 0;
    fstream file;
    file.open("data.dat", ios::in);
    if (!file.is_open()) {
        cout << "Errore apertura file!" << endl;
        return -1;
    }
    while (!file.eof()) {
        file >> x;
        sum += x;
        n++;
    }
    file.close();
    cout << n << endl;
    cout << "Media: " << sum / n << endl;
    return 0;
} 