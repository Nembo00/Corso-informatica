#include <iostream>
using namespace std;

double mean(double a[], int n);
double covariance(double a[], double b[], const double a_mean, const double b_mean, int n);

double mean(double a[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum/n;
}

double covariance(double a[], double b[], const double a_mean, const double b_mean, int n) {
    double successione = 0;
    for (int i = 0; i < n; i++) {
        successione += (a[i] - a_mean) * (b[i] - b_mean);
    }
    double cov = 1.0/(n-1) * successione;
    return cov;
}

int main() {
    const int n = 5;
    double v[n] = {10, 25, 34, 48, 52};
    double w[n] = {18, 25, 45, 11, 7};

    double v_mean = mean(v, n);
    double w_mean = mean(w, n);

    double cov = covariance(v, w, v_mean, w_mean, n);
    cout << "Covarianza = " << cov << endl;
    return 0;
}