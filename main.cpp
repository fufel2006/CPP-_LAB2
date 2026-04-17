#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

#include "Eq.h"
#include "Student.h"
#include "Examiner.h"

int main() {
    std::srand(std::time(nullptr));
    std::vector<Student*> group;
    group.push_back(new Good("Good student"));
    group.push_back(new Mid("Mid student"));
    group.push_back(new Bad("Bad student"));
    std::vector<Eq> tasks;
    std::ifstream fin("problems.txt");
    if (!fin) {
        std::cout << "Error: cannot open file\n";
        return 1;
    }
    double a, b, c;
    while (fin >> a >> b >> c) {
        tasks.push_back(Eq(a, b, c));
    }
    fin.close();
    std::cout << "Number of equations: "
        << tasks.size()
        << std::endl;
    Examiner teacher;
    for (size_t i = 0; i < group.size(); i++) {
        for (size_t j = 0; j < tasks.size(); j++) {
            teacher.add(group[i]->process(tasks[j]));
        }
    }
    teacher.evaluate();
    teacher.print();
    for (size_t i = 0; i < group.size(); i++) {
        delete group[i];
    }
    return 0;
}