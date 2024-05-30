#include <iostream>
#include "Container.cpp"
#include "Cerc.cpp"
#include "Triunghi.cpp"
#include "Patrat.cpp"

void afiseazaMeniu() {
    std::cout << "Meniu:\n";
    std::cout << "1. Adaugare figura\n";
    std::cout << "2. Stergere figura\n";
    std::cout << "3. Afisare figuri\n";
    std::cout << "4. Salvare figuri in fisier\n";
    std::cout << "5. Incarcare figuri din fisier\n";
    std::cout << "6. Iesire\n";
}


int main() {
    Container container;
    int optiune;
    do {
        afiseazaMeniu();
        std::cin >> optiune;
        switch (optiune) {
        case 1: {
            std::cout << "Tip figura (C - Cerc, T - Triunghi, P - Patrat): ";
            char tip;
            std::cin >> tip;
            if (tip == 'C') {
                double raza;
                std::cout << "Raza: ";
                std::cin >> raza;
                container.adaugaFigura(std::make_shared<Cerc>(raza));
            }
            else if (tip == 'T') {
                double latura;
                std::cout << "Latura: ";
                std::cin >> latura;
                container.adaugaFigura(std::make_shared<Triunghi>(latura));
            }
            else if (tip == 'P') {
                double latura;
                std::cout << "Latura: ";
                std::cin >> latura;
                container.adaugaFigura(std::make_shared<Patrat>(latura));
            }
            else {
                std::cout << "Tip invalid!" << std::endl;
            }
            break;
        }
        case 2: {
            std::cout << "Index figura de sters: ";
            size_t index;
            std::cin >> index;
            container.stergeFigura(index);
            break;
        }
        case 3: {
            container.print();
            break;
        }
        case 4: {
            std::string filename;
            std::cout << "Nume fisier: ";
            std::cin >> filename;
            container.save(filename);
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Nume fisier: ";
            std::cin >> filename;
            container.load(filename);
            break;
        }
        case 6:
            std::cout << "Iesire din program." << std::endl;
            break;
        default:
            std::cout << "Optiune invalida!" << std::endl;
        }
    } while (optiune != 6);
    return 0;
}
