#include <iostream>
#include <fstream>
#include <ctime>
#include "Header.h"

int main() {
    std::srand(std::time(nullptr));
    Student* group[3];
    group[0] = new Good("Good student");
    group[1] = new Mid("Mid student");
    group[2] = new Bad("Bad student");
    Eq tasks[10];
    int n = 0;
    std::ifstream fin("problems.txt");
    if (!fin) {
        std::cout << "Error: cannot open file\n";
        return 1;
    }

    double a, b, c;
    while (fin >> a >> b >> c && n < 10) {
        tasks[n++] = Eq(a, b, c);
    }
    fin.close();
    std::cout << "Number of equations: " << n << std::endl;
    Examiner teacher(50);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            teacher.add(group[i]->process(tasks[j]));
        }
    }
    teacher.evaluate();
    teacher.print();
    for (int i = 0; i < 3; i++) {
        delete group[i];
    }
    return 0;
}