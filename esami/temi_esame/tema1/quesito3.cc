bool sorted(int* A, int d) {
    for(int i = 0; i < d - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }
    return true;
}