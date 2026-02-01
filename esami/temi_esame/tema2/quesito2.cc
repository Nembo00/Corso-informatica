float totale = 0;
char a;
int b;

do {
    cout << "Inserisci nome prodotto e quantità desiderata: ";
    cin >> a >> b;
    float r = totaleCostoProd(C, d, a, b);
    if(r != -1) {
        totale += r;
    }
} while (a != '#');
cout << "Totale spesa: " << totale << endl;