#include <iostream>
#include "Simulador2D.h"

int main() {
    
    Simulador2D<float> sim(4, 4);
    
    std::cout << "Grid de inicio:" << std::endl;
    sim.mostrarGrid();
    
    sim.agregarFuente(100.0f);
    sim.agregarFuente(50.0f);
    sim.agregarFuente(75.0f);
    
    std::cout << "Numero de fuentes: " << sim.getNumFuentes() << std::endl;
    std::cout << "Fuente 0: " << sim.getFuente(0) << std::endl;
    std::cout << "Fuente 1: " << sim.getFuente(1) << std::endl;
    std::cout << "Fuente 2: " << sim.getFuente(2) << std::endl;
    
    std::cout << "Aplicando fuentes..." << std::endl;
    sim.aplicarFuenteAlGrid(0, 1, 1);
    sim.aplicarFuenteAlGrid(1, 0, 0);
    sim.aplicarFuenteAlGrid(2, 3, 3);
    
    sim.mostrarGrid();
    
    std::cout << "Constantes fisicas:" << std::endl;
    std::cout << "Coef. Difusion: " << sim.getConstante(0) << std::endl;
    std::cout << "DeltaX: " << sim.getConstante(1) << std::endl;
    std::cout << "DeltaT: " << sim.getConstante(2) << std::endl;
    
    
    return 0;
}