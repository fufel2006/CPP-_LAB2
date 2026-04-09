#pragma once
#include <string>
#include <utility>

class Eq {
public:
    double A, B, C;
    Eq();
    Eq(double a, double b, double c);

    double getDiscriminant() const;
    std::pair<double, double> getRoots() const;
};

bool isEqual(double x, double y);
bool sameRoots(std::pair<double, double> a, std::pair<double, double> b);

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

class Examiner {
private:
    Message* storage;
    int count;
    int capacity;

public:
    std::string names[10];
    int results[10];
    int totalStudents;

    Examiner(int maxSize);
    ~Examiner();

    void add(Message msg);
    void evaluate();
    void print();
};
