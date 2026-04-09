#include "Header.h"
#include <cmath>

const double EPS = 1e-6;

bool isEqual(double x, double y) {
    return std::fabs(x - y) < EPS;
}

bool sameRoots(std::pair<double, double> a, std::pair<double, double> b) {
    return (isEqual(a.first, b.first) && isEqual(a.second, b.second)) ||
        (isEqual(a.first, b.second) && isEqual(a.second, b.first));
}

Eq::Eq() : A(0), B(0), C(0) {}

Eq::Eq(double a, double b, double c) : A(a), B(b), C(c) {}

double Eq::getDiscriminant() const {
    return B * B - 4 * A * C;
}

std::pair<double, double> Eq::getRoots() const {
    double d = getDiscriminant();
    if (d < 0) {
        return { NAN, NAN };
    }
    double x1 = (-B - std::sqrt(d)) / (2 * A);
    double x2 = (-B + std::sqrt(d)) / (2 * A);
    return { x1, x2 };
}