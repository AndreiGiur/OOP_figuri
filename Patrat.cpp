#ifndef PATRAT_H
#define PATRAT_H

#include "Figura.cpp"

class Patrat : public Figura {
    double latura;
public:
    Patrat(double l = 0) : latura(l) {}
    void print() const override {
        std::cout << "Patrat cu latura: " << latura << std::endl;
    }
    void save(std::ofstream& out) const override {
        out << "P " << latura << std::endl;
    }
    void load(std::ifstream& in) override {
        in >> latura;
    }
};

#endif
