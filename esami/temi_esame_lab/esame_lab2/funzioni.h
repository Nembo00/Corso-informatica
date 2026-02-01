#include <sstream>

struct lettura {
float temperatura;
float umidita;
};

struct sensore {
char id[11]; // Identificativo del sensore
int num_letture;
lettura *dati; // Array di letture
};

struct dati_sensori {
int num_sensori;
sensore *elenco_sensori; // Array di sensori
};

void print_id_and_nread(const dati_sensori &a, const int index, std::stringstream& ss);
void media_temp(const dati_sensori &a, std::stringstream &ss);
void media_umidita(const dati_sensori &a, float *b, std::stringstream &ss);
void sort_sensori(dati_sensori &a, std::stringstream &ss);