#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

double gauss(double x);
double parabola(double x);
double integrate_gaussian(double a, double b, int n);
double integrate_function(double (*f)(double), double a, double b, int n);

double gauss(double x) {
    return (1 / sqrt(2 * M_PI)) * exp(-x * x / 2);
}

double parabola(double x) {
    return x * x;
}


double integrate_gaussian(double a, double b, int n) {
    double area = 0;
    double d = (b-a)/n;
    for (int i = 0; i < n; i++) {
        area += (gauss(a + i*d) + gauss(a + (i+1) * d )) /2;
    }
    return area * d;
}


double integrate_function(double (*f)(double), double a, double b, int n) {
    double area = 0;
    double d = (b-a)/n;
    for (int i = 0; i < n; i++) {
        area += (f(a + i*d) + f(a + (i+1) * d )) /2;
    }
    return area * d;
}


int main() {

    cout << "n = 100" << endl;
    cout << integrate_function(gauss, -10, 10, 100) << endl;
    cout << integrate_function(parabola, -1, 1, 100) << endl;

    cout << "n = 10" << endl;
    cout << integrate_function(gauss, -10, 10, 10) << endl;
    cout << integrate_function(parabola, -1, 1, 10) << endl;
    return 0;
}