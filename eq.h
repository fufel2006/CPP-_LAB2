#pragma once
#include <utility>

class Eq {
public:
    double A, B, C;

    Eq();
    Eq(double a, double b, double c);

    double getDiscriminant() const;
    std::pair<double, double> getRoots() const;

    static bool isEqual(double x, double y);
    static bool sameRoots(std::pair<double, double> a,
        std::pair<double, double> b);

private:
    static const double EPS;
};