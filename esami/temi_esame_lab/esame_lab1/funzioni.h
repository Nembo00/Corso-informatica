#include <string>
#include <sstream>

struct traj{
    int npoints;  //M + 1: numero totale di posizioni registrate per quella specifica traiettoria
    float *path;  //array posizione traiettoria
};

struct traiettorie{
    int ntraj;  //N
    traj *sample;  //array traiettorie
};

int countLines(const std::string& filename);
void primeTrePosizioni(const traj &A, const int index, std::stringstream& ss);
void ultimeTrePosizioni(const traj &A, const int index, std::stringstream& ss);
int scrematuraSample(traiettorie &A, std::stringstream& ss);
void media(const traiettorie &A, double *v);
void std_var(traiettorie &A, const double *v, double *w);
void primeTrePosVettori(const double *v, const std::string& vtrname, std::stringstream& ss);
void ultimeTrePosVettori(const double *v, int M, const std::string& vtrname, std::stringstream& ss);
void ordinaPerDistanzaFinale(traiettorie &A);

