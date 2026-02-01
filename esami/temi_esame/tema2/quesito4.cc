int most_frequent(int* A, int a) {
    int max_freq = 0;
    int best_value = A[0];
    for(int i = 0; i < a; i++) {
        int counter = 0;
        for(int j = 0; j < a; j++) {
            if(A[i] == A[j]) {
                counter++;
            }
        }
        if (counter > max_freq) {
            max_freq = counter;
            best_value = A[i];
        }
    }
    return best_value;
}