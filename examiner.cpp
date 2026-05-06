#include <iostream>
#include "Examiner.h"
#include "eq.h"

Examiner::Examiner() {}

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

        if (Eq::sameRoots(storage[i].roots, real)) {
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