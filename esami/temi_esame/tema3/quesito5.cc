int attuale, precedente;
bool ok = true;

// Chiediamo il primo numero per iniziare il confronto
cin >> precedente; 

// Se il primo numero è 0, la sequenza è vuota o finisce subito
if (precedente != 0) {
    do {
        cin >> attuale;

        // Se attuale è 0, la sequenza è finita e non va confrontato
        if (attuale != 0) {
            // Condizione: ogni numero deve essere maggiore del precedente [cite: 60]
            if (attuale <= precedente) {
                ok = false; // Se è minore o uguale, non è strettamente crescente
            }
            precedente = attuale; // Aggiorniamo il precedente per il prossimo giro
        }
    } while (attuale != 0); // Il ciclo continua finché l'utente non inserisce 0 
}

// Al termine, stampiamo il messaggio richiesto [cite: 62]
if (ok) {
    cout << "OK" << endl;
} else {
    cout << "KO" << endl;
}