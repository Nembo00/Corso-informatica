# **Appunti C++** 
### ***Matricola: 74381A***
## **Contenuti:**
**Bash, Makefile, iomanip, Cmath, Strutture di controllo, Cicli, Array, File I/O, Puntatori, Funzioni, Struct, Classi, Algoritmi utili.** 
## **Bash**
### Comandi utili:
|**Codice**| **Funzione**|
| :--- | :--- |
| `valgrind --leak-check=full ./nomeprogramma`| Esegue il programma con Valgrind per controllare perdite di memoria|
| `evince nomefile.pdf &`| Apre un file pdf in background|
| `less nomefile.txt`| Apre un file di testo in lettura|
|     `CTRL + Z`| Esce da less|
| `cp -r nomedirtarget nomedirdestinazione`| Copia una directory in modo ricorsivo|
|     `cp target destinazione`| Copia un file|
| `cat nomefile.txt`| Mostra il contenuto di un file|
| `ssh user@indirizzo_ip`| Connessione remota a un server|
| `ssh jacopo.viscillo@tolab.fisica.unimi.it`| Connessione remota al tolab|
| `scp user@indirizzo_ip:/percorso/file destinazione_locale`| Copia un file da un server remoto alla macchina locale|
| `wget urlfile`| Scarica un file da internet|  
| `wget -O corso.zip https://github.com/Nembo00/Corso-informatica/archive/refs/heads/main.zip`| Scarica un file da internet e lo salva con un nome specifico|  
| `unzip nomefile.zip`| Estrae il contenuto di un file zip|
| `git clone urlrepository`| Clona un repository git|
| `git pull`| Aggiorna il repository locale con le ultime modifiche dal repository remoto|
 

## **Makefile**
### Struttura di un Makefile (classico)
```Makefile
all: compila

compila: esempio.cc
    g++ -o prog1 esempio.cc

esegui: prog1
    ./prog1

clean:
    rm -f prog1
```
### Struttura di un Makefile (avanzato)
```Makefile
CC = g++
TARGET = prog1  
all: compila

compila: $(TARGET)

$(TARGET): esempio.cc funzioni.h funzioni.cc
    $(CC) -o $@ esempio.cc funzioni.cc

esegui: $(TARGET)
    ./$(TARGET)

clean:
    rm -f $(TARGET)
```
## **Iomanip**
### Funzioni utili:
| Codice | Descrizione | 
| :--- | :--- | 
| `#include <iomanip>` | Include la libreria iomanip | 
| `setw(n)` | Imposta la larghezza del campo di output a n caratteri | 
| `setprecision(n)` | Imposta il numero di cifre significative a n | 
| `fixed` | Usa la notazione a virgola fissa per i numeri in virgola mobile | 
| `scientific` | Usa la notazione scientifica per i numeri in virgola mobile | 
| `left` | Allinea il testo a sinistra | 
| `right` | Allinea il testo a destra |   
## **Cmath**
### Funzioni utili:
| Codice | Matematica | Descrizione | 
| :--- | :---: | :--- | 
| `pow(x, y)` | $x^y$ | Elevamento a potenza | 
| `sqrt(x)` | $\sqrt{x}$ | Radice quadrata | 
| `fabs(x)` | $\|x\|$ | Valore assoluto | 
| `hypot(x, y)` | $\sqrt{x^2 + y^2}$ | Ipotenusa / Modulo vettore | 
| `floor(x)` | $\lfloor x \rfloor$ | Arrotonda per difetto (verso $-\infty$) | 
| `ceil(x)` | $\lceil x \rceil$ | Arrotonda per eccesso (verso $+\infty$) | 
| `trunc(x)` | - | Tronca i decimali (verso $0$) | 
| `round(x)` | - | Arrotonda all'intero più vicino |
| `log(x)` | $\ln(x)$ | Logaritmo naturale | 
| `log10(x)` | $\log_{10}(x)$ | Logaritmo in base 10 | 
| `sin(x)` | $\sin(x)$ | Seno (x in radianti) | 
| `cos(x)` | $\cos(x)$ | Coseno (x in radianti) | 
| `tan(x)` | $\tan(x)$ | Tangente|   


***Trucco per avere valore pi greco:***
```cpp
#include <cmath>
const double PI = acos(-1.0);
```
## Strutture di controllo
### If-Else
```cpp
if(condizione1) {
    // codice da eseguire se condizione1 è vera
} else if(condizione2) {
    // codice da eseguire se condizione2 è vera
} else {
    // codice da eseguire se nessuna condizione è vera
}
```
### Switch-Case
```cpp
switch(espressione) {
    case valore1:
        // codice da eseguire se espressione == valore1
        break;  //importante poiché evita di eseguire i casi successivi
    case valore2:
        // codice da eseguire se espressione == valore2
        break;  //importante poiché evita di eseguire i casi successivi
    default:
        // codice da eseguire se nessun caso è soddisfatto
        break; //importante poiché evita di eseguire i casi successivi
}
```
## **Cicli**
### For
Usato quando si sa in anticipo quante volte il ciclo deve essere eseguito.
```cpp
for(inizializzazione; condizione; incremento) {     
    // codice da eseguire ad ogni iterazione
}
```
***Esempio:***
```cppcpp
for(int i = 0; i < 10; i++) {
    cout << i << endl;  //stampa i numeri da 0 a 9
}
```
### While
Usato quando non si sa in anticipo quante volte il ciclo deve essere eseguito.
```cpp
while(condizione) {
    // codice da eseguire finché la condizione è vera
}
```
***Esempio:***
```cppcpp
int i = 0;
while(i < 10) {
    cout << i << endl;  //stampa i numeri da 0 a 9
    i++;
}
```
### Do-While
**Do-While** è utile quando si vuole eseguire il codice **almeno una volta**, indipendentemente dalla condizione. Ad esempio, è perfetto per la **validazione dell'input dell'utente**.
```cpp
do {
    // codice da eseguire almeno una volta e poi finché la condizione è vera
} while(condizione);
```
***Esempio:***
```cpp
int i = 0;
do {
    cout << i << endl;  //stampa i numeri da 0 a 9
    i++;
} while(i < 10);
```
### Break e Continue
|Istruzione|Effetto|Contesto|
| :--- | :--- | :--- |
| `break;` | Esce immediatamente dal ciclo più interno | Uscita anticipata da ciclo |
| `continue;` | Salta l'iterazione corrente e passa alla successiva | Ignorare dati che non soddisfano criterio |   
## **Array** 
### Stack Array
**Usati per array di dimensione fissa.**
```cpp
DataType nome_array[dimensione];
```
***Esempi:***
|**Scenario** |**Codice C++**| 
| :--- | :--- |
|Dichiarazione con costante| `const int N = 10; int data[N];` |
|Inizializzazione e accesso| `int v[3]; v[0] = 3; cout << v[0];` |
|Inizializzazione a zero| `int arr[5] = {0};` |   
### Dynamic Array
**Usati per array di dimensione variabile.**
```cpp
DataType* nome_array = new DataType[dimensione];
```
***Uso:***
|**Operazione**|**Sintassi**|**Esempio**|
| :--- | :--- | :--- |
|Creazione| `dataType* nome_array = new DataType[dimensione];` | `int* arr = new int[n];` |
|Pulizia| `delete[] nome_array;` | `delete[] arr;` |   

## **File I/O**
### Apertura di un file
```cpp
#include <fstream>
using namespace std;

int main() {
    fstream file;  // Creazione dell'oggetto file
    file.open("nomefile.txt", ios::in); // Apertura del file in modalità lettura
    if (!file.is_open()) {
        cout << "Errore nell'apertura del file." << endl;
        return 1;
    }
    // Operazioni sul file
    file.close(); // Chiusura del file
    return 0;
}
```
### Modalità di apertura
| Modalità | Descrizione |
| :--- | :--- |
| `ios::in` | Apertura per lettura |
| `ios::out` | Apertura per scrittura (crea il file se non esiste) |
| `ios::app` | Apertura in modalità append (scrittura alla fine del file) |
| `ios::ate` | Apertura e posizionamento alla fine del file |
| `ios::binary` | Apertura in modalità binaria |
### Lettura da un file
```cpp
int numero;
string testo;
file >> numero; // Lettura di un intero
file >> testo; // Lettura di una riga di testo
```
### Scrittura su un file
```cpp
file << "Ciao, mondo!" << endl; // Scrittura di una stringa
file << 42 << endl; // Scrittura di un intero
```
## **Puntatori**
|**Operatore**| **Descrizione**|
|:--- | :--- |
| `&` (address-of)| restituisce l'indirizzo di una variabile.|
| `*` (dereference)| accede al valore memorizzato all'indirizzo puntato.|   

|**Operazione**|**Sintassi**|**Esempio**|**Descrizione**|
| :--- | :--- | :--- | :--- |
|Dichiarazione| `DataType* nome_puntatore;` | `int* ptr;` | Dichiarazione di un puntatore a DataType |
|Assegnazione indirizzo| `nome_puntatore = &variabile;` | `ptr = &var;` | Assegna l'indirizzo di una variabile al puntatore |
|Accesso al valore| `*nome_puntatore` | `int value = *ptr;` | Accede al valore puntato |
|Allocazione dinamica| `nome_puntatore = new DataType;` | `ptr = new int;` | Alloca memoria dinamicamente |
|Modifica del valore| `*nome_puntatore = nuovo_valore;` | `*ptr = 10;` | Modifica il valore puntato |
|Puntatore nullo| `nome_puntatore = nullptr;` | `ptr = nullptr;` | Inizializza il puntatore a null |
|Deallocazione| `delete nome_puntatore;` | `delete ptr;` | Libera la memoria allocata |   

### Utilità dei puntatori
- Passaggio di grandi strutture dati alle funzioni senza copiarle.
- Creazione di strutture dati dinamiche come liste collegate, alberi, ecc.
- Gestione efficiente della memoria.

## **Funzioni**
### Sintassi
```cpp
dataType FunctionName(parametro1, parametro2, ...) { 
    // corpo della funzione 
    return valore;
} 
```
### Passaggio per riferimento
**Normalmente il programma crea una copia dei parametri passati alla funzione. Usando i riferimenti, si può evitare questa copia e lavorare direttamente con le variabili originali.**
```cpp
void funzione(int& ref) {
    ref = ref + 10; // Modifica il valore originale
}
```
### Passaggio per puntatore
```cpp
void funzione(int* ptr) {
    *ptr = *ptr + 10; // Modifica il valore originale
}
```
## **Struct**
### Sintassi
```cpp
struct NomeStruct {
    DataType membro1;
    DataType membro2;
    // altri membri
};
```
### Esempio
```cpp
NomeStruct variabile;  //Crea variabile di tipo NomeStruct
//Assegnazione valori ai membri
variabile.membro1 = valore1;  //Assegna valore a membro1
variabile.membro2 = valore2;  //Assegna valore a membro2
//Alternativa
NomeStruct variabile2 = {valore1, valore2}; //Inizializza i membri
```
### Array di Struct
```cpp
NomeStruct arrayStruct[dimensione]; //Crea un array di struct
arrayStruct[0].membro1 = valore; //Assegna valore al membro1 del primo elemento
cout << arrayStruct[1].membro2; //Stampa il membro2 del secondo elemento
```
### Puntatori a Struct
```cpp
NomeStruct* ptr = new NomeStruct; //Crea un puntatore a struct
ptr->membro1 = valore; //Assegna valore al membro1 usando il puntatore
cout << ptr->membro2; //Stampa il membro2 usando il puntatore
delete ptr; //Libera la memoria allocata
```
### Funzioni con Struct
-**passaggio per riferimento:** usato per modificare la struct originale senza copiarla.
-**passaggio per riferimento costante:** usato per leggere la struct senza modificarla.
```cpp
void funzione(NomeStruct& s) { //passaggio per riferimento
    s.membro1 = nuovo_valore; //Modifica il membro1
}
void funzioneConst(const NomeStruct& s) { //passaggio per riferimento costante
    cout << s.membro2; //Legge il membro2 senza modificarlo
}
```
## **I/O Avanzato con sstream**
### Sintassi
|iostream|sstream|Descrizione|
| :--- | :--- | :--- |
| `cout << "Data";` | `stringstream ss; `| Dichiarazione di un flusso di stringa |
| `cout << ... << endl; `| `ss << "Data"; `| Scrittura nel flusso di stringa |
| N/A| `string str = ss.str(); `| Ottiene la stringa dal flusso |   

### Pulizia
- `ss.str(""); `: Resetta il contenuto del flusso.
- `ss.clear(); `: Resetta lo stato del flusso (utile dopo errori di lettura).

## **Template**
Un template consente di creare funzioni o classi generiche che possono operare con qualsiasi tipo di dato.
### Sintassi 
` template <typename T> ` Indica che la defizione che segue è un template che utilizza un tipo generico T.
### Esempio di funzione max con template
```cpp
template <typename T>
T max(T a, T b) {
    if(a >= b) return a;
    return b;
}
```
In questo esempio la deduzione del tipo avviene automaticamente in base ai tipi degli argomenti passati alla funzione.
Si può anche specificare esplicitamente il tipo quando si chiama la funzione:
```cpp
int massimo = max<int>(3, 5); // Specifica esplicita del tipo
double massimoD = max<double>(3.5, 2.8); // Specifica esplicita del tipo
```
## **OOP - Classi e Oggetti**
### Definizione di una classe
```cpp
class NomeClasse {
private:
    // Membri privati (accessibili solo all'interno della classe)
    DataType membroPrivato;
public:
    // Membri pubblici (accessibili dall'esterno della classe)
    DataType membroPubblico;
    // Costruttore
    NomeClasse(DataType parametro) {
        membroPrivato = parametro;
    }
    // Metodo pubblico
    void metodoPubblico() {
        // Codice del metodo
    }
};
```
### Class Constructor
```cpp
class Point {
private:
    int x, y;
public:
    // Costruttore
    Point(int xCoord, int yCoord) {
        x = xCoord;
        y = yCoord;
    }
    ~Point() {
        // Codice di pulizia (se necessario)
    }
};
```
### Inheritance (Ereditarietà)
|**Membro in mother**|**Ereditato in child con public inheritance**|**Ereditato in child con protected inheritance**| **Ereditato in child con private inheritance**|
| :--- | :--- | :--- | :--- |
| public | public | protected | private |
| protected | protected | protected | private |
| private | non ereditato | non ereditato | non ereditato |   

## **Algoritmi utili**
### Media 
```cpp
const int N = 10;
double v[N];
//caricamento valori in v
double sum = 0.0;
for(int i = 0; i < N; i++) {
    sum += v[i];
}
double media = sum / N;
```
### Standard Deviation
```cpp
const int N = 10;
double v[N];
//caricamento valori in v
double sum2 = 0.0;
for(int i = 0; i < N; i++) {
    sum2 += pow(v[i]-media, 2);
}
double devstd = sqrt(sum2 / N);
```
### Minimo e Massimo
```cpp
const int N = 10;
double v[N];
//caricamento valori in v
double maxVal = v[0];
for(int i = 1; i < N; i++) {
    if(v[i] > maxVal) {  //Per minimo cambiare > con <
        maxVal = v[i];
    }
}
```
### Ricerca Lineare
```cpp
const int N = 10;
double v[N];
//caricamento valori in v
double target = 5.0;
int index_loc = -1;
for(int i = 0; i < N; i++) {
    if(v[i] == target) {  //confronto elemento
        index_loc = i;  //trova l'indice
        break;
    }
}
```
### Selection Sort
```cpp
const int N = 10;
double v[N];
//caricamento valori in v
//ordine crescente
for(int i = 0; i < N-1; i++) {
    for(int j = i+1; j < N; j++) {
        if(v[i] > v[j]) {  //confronto elemento; per ordine decrescente cambiare > con <
            double temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    } 
}
```

### Lettura da un file
```cpp
#include <fstream>
using namespace std;

int main() {
    fstream file;  // Creazione dell'oggetto file
    file.open("nomefile.txt", ios::in); // Apertura del file in modalità lettura
    if (!file.is_open()) {
        cout << "Errore nell'apertura del file." << endl;
        return 1;
    }
    // Operazioni sul file
    file.close(); // Chiusura del file
    return 0;
}
```

### Conteggio righe in un file
```cpp
int countlines(const string& filename) {
    fstream file(filename, ios::in);
    if (!file.is_open()) {
        cout << "Errore nell'apertura del file." << endl;
        return -1;
    }
    string tmp;
    int count = 0;
    for (;;) {
        getline(file, tmp);
        if (file.eof()) break;
        count++;
    } 
    file.close();
    cout << "Numero di righe: " << count << endl;
    return count;
}
```
### Attenzione
**Dopo aver letto il file, per rileggerlo è necessario tornare a inizio file:**
- Cancellare Flag di errore: (failbit o eofbit); si usa `file.clear();`
- Tornare a inizio file: `file.seekg(0);`
