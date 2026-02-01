void sortEven(int* A, int d){
    for(int i = 0; i < d -2; i+=2){
        for(int j = i + 2; j < d; j+=2){
            if(A[i] > A[j]) {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}