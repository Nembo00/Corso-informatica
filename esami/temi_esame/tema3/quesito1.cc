int pari_count = 0;
int dispari_count = 0;
int scrittura = 0;

for(int lettura = 0; lettura < 50; lettura++) {
    if((X[lettura] % 2) == 0) {
        X[scrittura] = X[lettura];
        scrittura++;
        pari_count++;
    } else {
        dispari_count++;
    }
}

int pos_lettura = pari_count - 1;
int pos_scrittura = 2 * pari_count - 1;
while(pos_lettura >= 0) {
    int valore = X[pos_lettura];
    X[pos_scrittura] = valore;
    X[pos_scrittura - 1] = valore;

    pos_lettura--;
    pos_scrittura -= 2;
}
cout << "Pari aggiunti: " << pari_count << " Dispari eliminati: " << dispari_count << endl;