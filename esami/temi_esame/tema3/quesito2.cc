int* set(int* X, int d) {
    int* risultato = new int[d]; 
    int quanti_unici = 0; // Questo conta quanti numeri diversi abbiamo trovato finora
    // 2. Ciclo principale: prendo ogni numero dell'array originale X uno alla volta
    for (int i = 0; i < d; i++) {
        bool gia_visto = false;
        // 3. Controllo se X[i] è già dentro il mio array 'risultato'
        for (int j = 0; j < quanti_unici; j++) {
            if (X[i] == risultato[j]) {
                gia_visto = true; // L'ho trovato! È un duplicato.
                break;            // Smetto di cercare nel ciclo interno
            }
        }
        // 4. Se DOPO il controllo 'gia_visto' è ancora false, allora è un numero nuovo!
        if (!gia_visto) {
            risultato[quanti_unici] = X[i]; // Lo aggiungo al nuovo array
            quanti_unici++;                 // Aumento il numero di elementi unici trovati
        }
    }
    return risultato; // Restituisco l'indirizzo del nuovo array "pulito" 
}