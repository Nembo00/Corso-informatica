#include <iostream>
using namespace std;

void print_array(const int a[], int n);
int max_array(const int a[], int n);
int min_array(const int a[], int n);
void min_max_array(const int a[], int n, int &min, int &max);
void sort_array(int a[], int n);
int binary_search(int a[], int n, int w);

void print_array(const int a[], int n) {  //funzione che stampa l'array 
    for (int i = 0; i < n; i++) {
        cout << "v[" << i << "] = " << a[i] << endl;
    }
}

int min_array(const int a[], int n) {   //funzione che riporta nel main il valore min dell'array
    double min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int max_array(const int a[], int n) {  // //funzione che riporta nel main il valore max dell'array
    double max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void min_max_array(const int a[], int n, int &min, int &max){  //funzione che calcola max e min di un array usando min e max di riferimento(&)
    max = max_array(a, n);
    min = min_array(a, n);
}


void sort_array(int a[], int n) {
    for (int i = 0; i < n -1; i++) {
        for (int j = i +1; j < n; j++) {
            if (a[i] > a[j]) {
                double tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}


int binary_search(int a[], int n, int target) {
    int low = 0;
    int high = n -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == target) {
            return mid;
        }
        if (a[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    } return -1;
}


int main() {
    const int n = 10;
    int v[10] = {9, 2, 1, 3, 4, 7, 0, 11, 20, 5};

    print_array(v, n);
    cout << "max = " << max_array(v, n) << endl;
    cout << "min = " << min_array(v, n) << endl;

    int min, max;
    min_max_array(v, n, min, max);
    cout << "min = " << min << ", max = " << max << endl;

    sort_array(v, n);
    print_array(v, n);

    int target = 0;

    cout << "Inserisci valore da cercare in array: ";
    cin >> target;
     int indice = binary_search(v, n, target);
     if (indice != -1) {
        cout << "Trovato all'indice: " << indice << endl;
     } else {
        cout << "Elemento non presente nell'array!" << endl;
     }
    return 0;
}