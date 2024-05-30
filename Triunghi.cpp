#ifndef TRIUNGHI_H
#define TRIUNGHI_H

#include "Figura.cpp"

class Triunghi : public Figura {
    double latura;
public:
    Triunghi(double l = 0) : latura(l) {}
    void print() const override {
        std::cout << "Triunghi cu latura: " << latura << std::endl;
    }
    void save(std::ofstream& out) const override {
        out << "T " << latura << std::endl;
    }
    void load(std::ifstream& in) override {
        in >> latura;
    }
};

#endif
