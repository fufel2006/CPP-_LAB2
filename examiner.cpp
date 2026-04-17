#include <iostream>
#include <cmath>
#include "Examiner.h"

const double EPS = 1e-6;

Examiner::Examiner() {}
bool Examiner::isEqual(double x, double y) {
    return std::fabs(x - y) < EPS;
}
bool Examiner::sameRoots(std::pair<double, double> a,
    std::pair<double, double> b) {
    return (isEqual(a.first, b.first) &&
        isEqual(a.second, b.second)) ||
        (isEqual(a.first, b.second) &&
            isEqual(a.second, b.first));
}
void Examiner::add(Message msg) {
    storage.push_back(msg);
    bool found = false;
    for (size_t i = 0; i < names.size(); i++) {
        if (names[i] == msg.name) {
            found = true;
            break;
        }
    }
    if (!found) {
        names.push_back(msg.name);
        results.push_back(0);
    }
}

void Examiner::evaluate() {
    for (size_t i = 0; i < storage.size(); i++) {
        auto real = storage[i].eq.getRoots();
        if (sameRoots(storage[i].roots, real)) {
            for (size_t j = 0; j < names.size(); j++) {
                if (names[j] == storage[i].name) {
                    results[j]++;
                    break;
                }
            }
        }
    }
}

void Examiner::print() {
    std::cout << "\nResults:\n";
    for (size_t i = 0; i < names.size(); i++) {
        std::cout << names[i]
            << " -> "
            << results[i]
            << std::endl;
    }
}