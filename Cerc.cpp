#ifndef CERC_H
#define CERC_H

#include "Figura.cpp"
#include <fstream>

class Cerc : public Figura {
    double raza;
public:
    Cerc(double r = 0) : raza(r) {}
    void print() const override {
        std::cout << "Cerc cu raza: " << raza << std::endl;
    }
    void save(std::ofstream& out) const override {
        out << "C " << raza << std::endl;
    }
    void load(std::ifstream& in) override {
        in >> raza;
    }
};

#endif
