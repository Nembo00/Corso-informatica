#include "function.h"
vettore prodotto_vettoriale(vettore a, vettore b) {
    vettore d;
    d.x = a.y * b.z - a.z * b.y;
    d.y = a.z * b.x - a.x * b.z;
    d.z = a.x * b.y - a.y * b.x;
    return d;
}