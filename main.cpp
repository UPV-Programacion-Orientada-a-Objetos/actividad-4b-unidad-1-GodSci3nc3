#include <iostream>
#include "Simulador2D.h"

int main() {
    std::cout << "--- Simulador Generico de Fluidos (Difusion) ---" << std::endl;
    std::cout << std::endl;
    
    std::cout << ">> Inicializando Sistema (Tipo FLOAT) <<" << std::endl;
    std::cout << "Creando Grid (FLOAT) de 5x5..." << std::endl;
    Simulador2D<float> sim(5, 5);
    std::cout << std::endl;
    
    std::cout << ">> Agregando Fuentes de Concentracion <<" << std::endl;
    sim.agregarFuente(100.0f);
    std::cout << "Agregar Fuente 1 (Valor 100.0): Exito." << std::endl;
    
    sim.agregarFuente(50.0f);
    std::cout << "Agregar Fuente 2 (Valor 50.0): Exito." << std::endl;
    std::cout << std::endl;
    
    std::cout << ">> Aplicando Valores Iniciales <<" << std::endl;
    sim.aplicarFuenteAlGrid(0, 2, 2);
    std::cout << "Grid[2,2] = 100.0 (Fuente 1)" << std::endl;
    
    sim.aplicarFuenteAlGrid(1, 4, 0);
    std::cout << "Grid[4,0] = 50.0 (Fuente 2)" << std::endl;
    std::cout << std::endl;
    
    std::cout << "--- Grid Inicial (Paso 0) ---" << std::endl;
    sim.mostrarGrid();
    
    std::cout << "Opcion: Simular 1 Paso" << std::endl;
    std::cout << std::endl;
    std::cout << "Simulando Propagacion..." << std::endl;
    std::cout << std::endl;
    
    sim.simularPaso();
    
    std::cout << "--- Grid Despues del Paso 1 ---" << std::endl;
    sim.mostrarGrid();
    
    std::cout << "Opcion: Redimensionar" << std::endl;
    sim.redimensionarGrid(6, 6);
    std::cout << "Redimensionando Grid a 6x6. Datos copiados." << std::endl;
    std::cout << std::endl;
    
    std::cout << "Opcion: Salir" << std::endl;
    std::cout << "Liberando memoria del Grid y Fuentes... Sistema cerrado." << std::endl;
    
    return 0;
}