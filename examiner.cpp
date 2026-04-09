#include "Header.h"
#include <iostream>

Examiner::Examiner(int maxSize) {
    capacity = maxSize;
    storage = new Message[capacity];
    count = 0;
    totalStudents = 0;
    for (int i = 0; i < 10; i++) {
        results[i] = 0;
    }
}

Examiner::~Examiner() {
    delete[] storage;
}

void Examiner::add(Message msg) {
    if (count >= capacity) return;
    storage[count++] = msg;
    bool exists = false;
    for (int i = 0; i < totalStudents; i++) {
        if (names[i] == msg.name) {
            exists = true;
            break;
        }
    }
    if (!exists) {
        names[totalStudents++] = msg.name;
    }
}

void Examiner::evaluate() {
    for (int i = 0; i < count; i++) {
        if (sameRoots(storage[i].roots, storage[i].eq.getRoots())) {
            for (int j = 0; j < totalStudents; j++) {
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
    for (int i = 0; i < totalStudents; i++) {
        std::cout << names[i] << " -> " << results[i] << std::endl;
    }
}