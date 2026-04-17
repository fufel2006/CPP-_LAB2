#pragma once
#include <vector>
#include <string>
#include "Student.h"

class Examiner {
private:
    std::vector<Message> storage;
    std::vector<std::string> names;
    std::vector<int> results;

    bool isEqual(double x, double y);
    bool sameRoots(std::pair<double, double> a,
        std::pair<double, double> b);

public:
    Examiner();

    void add(Message msg);
    void evaluate();
    void print();
};