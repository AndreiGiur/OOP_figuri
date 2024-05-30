#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
#include <fstream>

class Figura {
public:
    virtual void print() const = 0;
    virtual void save(std::ofstream& out) const = 0;
    virtual void load(std::ifstream& in) = 0;
    virtual ~Figura() {}
};

#endif
