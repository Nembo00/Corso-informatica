bool disjoint(int* X, int dx, int* Y, int dy) {
    for(int i = 0; i < dx; i++) {
        for(int j = 0; j < dy; j++) {
            if(X[i] == Y[j]) return false;
        }
    }
    return true;
}