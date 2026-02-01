#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        cout << "Hello, World!" << endl;
    }
    int i = 0;
    while (i < 5) {
        cout << "Hello, World!" << endl;
        i++;
    }
    i = 0;
    do {
        cout << "Hello, World!" << endl;
        i++;
    } while (i < 5);
    return 0;
}