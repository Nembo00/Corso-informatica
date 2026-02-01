#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    double v[N], w[N];
    v[0] = 2, v[1] = 5, v[2] = 10, v[3] = 20, v[4] = 50;
    w[0] = 10, w[1] = -5, w[2] = 3, w[3] = 1, w[4] = 100;

    // oppure double v[N] = {2, 5, 10, 20, 50};
    for (int i = 0; i<N; i++) {
        cout << "v[" << i << "] = " << v[i] << endl;
    }
    for (int j = 0 ; j < N; j++) {
        cout << "w[" << j << "] = " << w[j] << endl;
    }

    double s[5];
    for (int i = 0; i < 5; i++) {
        s[i] = v[i];
        s[i] += w[i];
        cout << "s[" << i << "] = " << s[i] << endl;   
    }

    return 0;
}