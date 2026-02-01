#include <iostream>
using namespace std;

bool sorted(int* A, int d) {
    for(int i = 0; i < d - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    const int N = 100;
    int X[N];
    cout << "Inserisci una sequenza di 100 interi: " << endl;
    for(int i = 0; i < 100; i++) {
        cin >> X[i]; 
    }
    if(sorted(X, 100)) {
        cout << "Numeri già ordinati!" << endl;
    } else {  //Ordinamento X
        for (int i = 0; i < N-1; i++){
            for (int j = i + 1; j < N; j++){
                if (X[i] > X[j]){
                    int tmp = X[i];
                    X[i] = X[j];
                    X[j] = tmp; 
                }
            }
        }
    }
    return 0;
}