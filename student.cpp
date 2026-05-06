#include "Eq.h"
#include "Student.h"
#include "Examiner.h"
#include <cstdlib>

Student::Student(std::string name) : id(name) {}
std::string Student::getId() const {
    return id;
}

Good::Good(std::string name) : Student(name) {}
Message Good::process(const Eq& eq) {
    return { id, eq, eq.getRoots() };
}

Mid::Mid(std::string name) : Student(name) {}
Message Mid::process(const Eq& eq) {
    auto correct = eq.getRoots();
    double p = (std::rand() % 100) / 100.0;

    if (p < 0.5) {
        return { id, eq, correct };
    }
    else {
        double x1 = (std::rand() % 21 - 10);
        double x2 = (std::rand() % 21 - 10);
        return { id, eq, {x1, x2} };
    }
}

Bad::Bad(std::string name) : Student(name) {}
Message Bad::process(const Eq& eq) {
    return { id, eq, {0, 0} };
}