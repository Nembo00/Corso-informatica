#include "funzioni.h"
#include <cmath>

void compute_distance(point2d &p) {
    p.distance = sqrt(pow(p.coordinate[0], 2) + pow(p.coordinate[1], 2));
}

double mean(point2d punti[], const int n) {
    double somma = 0;
    for (int i = 0; i < n; i++) {
        somma += punti[i].distance;
    }
    return somma/n;
}

void dealloca_punti(point2d *punti, int size) {
    for (int i = 0; i < size; i++) {
        delete[] punti[i].coordinate;
    }
}

double trova_min_distanza(point2d *punti, int size) {
    double min = punti[0].distance;
    for (int i = 0; i < size; i++) {
        if (punti[i].distance < min) {
            min = punti[i].distance;
        }
    }
    return min;
}

double trova_max_distanza(point2d *punti, int size) {
    double max = punti[0].distance;
    for (int i = 0; i < size; i++) {
        if (punti[i].distance > max) {
            max = punti[i].distance;
        }
    }
    return max;
}