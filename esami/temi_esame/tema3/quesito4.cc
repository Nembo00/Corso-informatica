void ordina(int* X, int dim, int p) {
    for(int i = 0; i < dim; i+=p) {
        for(int j = i+p; j < dim; j+=p) {
            if(X[i] > X[j]) {
                int tmp = X[i];
                X[i] = X[j];
                X[j] = tmp;

            }
        }
    }
}