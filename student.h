#pragma once
#include <string>
#include "Eq.h"

struct Message {
    std::string name;
    Eq eq;
    std::pair<double, double> roots;
};

class Student {
protected:
    std::string id;

public:
    Student(std::string name);

    virtual Message process(const Eq& eq) = 0;

    std::string getId() const;
};

class Good : public Student {
public:
    Good(std::string name);
    Message process(const Eq& eq) override;
};

class Mid : public Student {
public:
    Mid(std::string name);
    Message process(const Eq& eq) override;
};

class Bad : public Student {
public:
    Bad(std::string name);
    Message process(const Eq& eq) override;
};
