#include "aiuti.h"

void simulaCaduta(pacco &p){

    double ftime = sqrt(2*p.z0/GRAV);
    p.xf = p.x0 + p.vx * ftime;
    p.yf = p.y0 + p.vy * ftime;

}