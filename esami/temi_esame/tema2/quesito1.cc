float totaleCostoProd(prodotto* C, int d, char a, int b) {
    for(int i = 0; i < d; i++) {
        if(C[i].nome == a && b >= 0) {
            return C[i].pu * b;
        }
    }
    return -1;
}