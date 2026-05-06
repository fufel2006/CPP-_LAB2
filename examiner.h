#pragma once

#include <vector>
#include <string>
#include "Student.h"
#include "eq.h"

class Examiner {
private:
    std::vector<Message> storage;
    std::vector<std::string> names;
    std::vector<int> results;

public:
    Examiner();

    void add(Message msg);
    void evaluate();
    void print();
};
