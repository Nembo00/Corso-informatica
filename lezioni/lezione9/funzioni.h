struct point2d {
    double *coordinate;
    double distance;
};

void compute_distance(point2d &p);
double mean(point2d punti[], const int n);
void dealloca_punti(point2d *punti, int size);
double trova_min_distanza(point2d *punti, int size);
double trova_max_distanza(point2d *punti, int size);