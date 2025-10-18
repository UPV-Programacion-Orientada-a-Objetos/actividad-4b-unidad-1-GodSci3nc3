#ifndef SIMULADOR2D_H
#define SIMULADOR2D_H

#include <iostream>

template <typename T>
class Simulador2D {
private:
    T **_grid;
    int _filas;
    int _columnas;
    
    T *_fuentes;
    int _numFuentes;
    int _capacidadFuentes;
    
    float _constantes[3];
    
    void _inicializarGrid();
    bool _indicesValidos(int fila, int columna) const;

public:
    Simulador2D(int f, int c);
    ~Simulador2D();
    
    T getValor(int fila, int columna) const;
    void setValor(int fila, int columna, T valor);
    void getDimensiones(int& filas, int& columnas) const;
    
    void agregarFuente(T valor);
    T getFuente(int indice) const;
    int getNumFuentes() const;
    void aplicarFuenteAlGrid(int indiceFuente, int fila, int columna);
    
    void setConstante(int indice, float valor);
    float getConstante(int indice) const;
    void inicializarConstantesDefecto();
    
    void redimensionarGrid(int nuevaF, int nuevaC);
    void simularPaso();
    
    void mostrarGrid() const;
    void limpiarGrid();
};

template <typename T>
Simulador2D<T>::Simulador2D(int f, int c) {
    _filas = f;
    _columnas = c;
    
    _grid = new T*[_filas];
    for(int i = 0; i < _filas; i++) {
        _grid[i] = new T[_columnas];
    }
    
    _inicializarGrid();
    
    _capacidadFuentes = 2;
    _numFuentes = 0;
    _fuentes = new T[_capacidadFuentes];
    
    inicializarConstantesDefecto();
}

template <typename T>
void Simulador2D<T>::_inicializarGrid() {
    for(int i = 0; i < _filas; i++) {
        for(int j = 0; j < _columnas; j++) {
            _grid[i][j] = T(0);
        }
    }
}

template <typename T>
void Simulador2D<T>::inicializarConstantesDefecto() {
    _constantes[0] = 0.1f;
    _constantes[1] = 1.0f;
    _constantes[2] = 0.1f;
}

template <typename T>
Simulador2D<T>::~Simulador2D() {
    for(int i = 0; i < _filas; i++) {
        delete[] _grid[i];
    }
    delete[] _grid;
    
    delete[] _fuentes;
}

template <typename T>
bool Simulador2D<T>::_indicesValidos(int fila, int columna) const {
    return fila >= 0 && fila < _filas && columna >= 0 && columna < _columnas;
}

template <typename T>
T Simulador2D<T>::getValor(int fila, int columna) const {
    if(_indicesValidos(fila, columna)) {
        return _grid[fila][columna];
    }
    return T(0);
}

template <typename T>
void Simulador2D<T>::setValor(int fila, int columna, T valor) {
    if(_indicesValidos(fila, columna)) {
        _grid[fila][columna] = valor;
    }
}

template <typename T>
void Simulador2D<T>::getDimensiones(int& filas, int& columnas) const {
    filas = _filas;
    columnas = _columnas;
}

template <typename T>
void Simulador2D<T>::mostrarGrid() const {
    for(int i = 0; i < _filas; i++) {
        std::cout << "| ";
        for(int j = 0; j < _columnas; j++) {
            std::cout << _grid[i][j] << " | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <typename T>
void Simulador2D<T>::limpiarGrid() {
    for(int i = 0; i < _filas; i++) {
        for(int j = 0; j < _columnas; j++) {
            _grid[i][j] = T(0);
        }
    }
}

#endif 