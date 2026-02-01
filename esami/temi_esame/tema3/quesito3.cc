
int* unione_insiemistica(int* A, int da, int* B, int db) {
    // 1. Allocazione dinamica: lo spazio massimo è la somma delle dimensioni 
    int* risultato = new int[da + db];
    int k = 0;

    // 2. Primo ciclo: inseriamo elementi di A se non già presenti 
    for (int i = 0; i < da; i++) { 
        bool gia_visto = false;
        for (int j = 0; j < k; j++) { 
            if (A[i] == risultato[j]) {
                gia_visto = true;
                break;
            }
        }
        if (!gia_visto) {
            risultato[k] = A[i];
            k++;
        }
    }

    // 3. Secondo ciclo: inseriamo elementi di B se non già presenti in 'risultato' 
    for (int i = 0; i < db; i++) { 
        bool gia_visto = false;
        for (int j = 0; j < k; j++) {
            if (B[i] == risultato[j]) {
                gia_visto = true;
                break;
            }
        }
        if (!gia_visto) {
            risultato[k] = B[i];
            k++;
        }
    }

    return risultato; // Restituisce il puntatore all'array creato 
}