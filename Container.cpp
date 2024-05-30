#ifndef CONTAINER_H
#define CONTAINER_H


#include <vector>
#include <memory>
#include <fstream>
#include "Figura.cpp"
#include "Patrat.cpp"
#include "Triunghi.cpp"
#include "Cerc.cpp"

class Container {
    std::vector<std::shared_ptr<Figura>> figuri;
public:
    void adaugaFigura(std::shared_ptr<Figura> figura) {
        figuri.push_back(figura);
    }
    void stergeFigura(size_t index) {
        if (index < figuri.size())
            figuri.erase(figuri.begin() + index);
    }
    void print() const {
        for (const auto& figura : figuri)
            figura->print();
    }
    void save(const std::string& filename) const {
        std::ofstream out(filename);
        if (!out) {
            std::cerr << "Eroare la deschiderea fisierului pentru salvare!" << std::endl;
            return;
        }
        for (const auto& figura : figuri)
            figura->save(out);
    }
    void load(const std::string& filename) {
        std::ifstream in(filename);
        if (!in) {
            std::cerr << "Eroare la deschiderea fisierului pentru incarcare!" << std::endl;
            return;
        }
        figuri.clear();
        char type;
        while (in >> type) {
            std::shared_ptr<Figura> figura;
            if (type == 'C')
                figura = std::make_shared<Cerc>();
            else if (type == 'T')
                figura = std::make_shared<Triunghi>();
            else if (type == 'P')
                figura = std::make_shared<Patrat>();
            else
                continue;
            figura->load(in);
            figuri.push_back(figura);
        }
    }
};

#endif
