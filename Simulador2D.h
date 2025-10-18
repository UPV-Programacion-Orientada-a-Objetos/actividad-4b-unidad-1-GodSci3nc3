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
    T** _crearMatrizTemporal();
    void _copiarMatriz(T** origen, T** destino);
    void _liberarMatrizTemporal(T** matriz);

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

template <typename T>
void Simulador2D<T>::agregarFuente(T valor) {
    if(_numFuentes >= _capacidadFuentes) {
        int nuevaCapacidad = _capacidadFuentes * 2;
        T* nuevoVector = new T[nuevaCapacidad];
        
        for(int i = 0; i < _numFuentes; i++) {
            nuevoVector[i] = _fuentes[i];
        }
        
        delete[] _fuentes;
        _fuentes = nuevoVector;
        _capacidadFuentes = nuevaCapacidad;
    }
    
    _fuentes[_numFuentes] = valor;
    _numFuentes++;
}

template <typename T>
T Simulador2D<T>::getFuente(int indice) const {
    if(indice >= 0 && indice < _numFuentes) {
        return _fuentes[indice];
    }
    return T(0);
}

template <typename T>
int Simulador2D<T>::getNumFuentes() const {
    return _numFuentes;
}

template <typename T>
void Simulador2D<T>::aplicarFuenteAlGrid(int indiceFuente, int fila, int columna) {
    if(indiceFuente >= 0 && indiceFuente < _numFuentes && _indicesValidos(fila, columna)) {
        _grid[fila][columna] = _fuentes[indiceFuente];
    }
}

template <typename T>
void Simulador2D<T>::setConstante(int indice, float valor) {
    if(indice >= 0 && indice < 3) {
        _constantes[indice] = valor;
    }
}

template <typename T>
float Simulador2D<T>::getConstante(int indice) const {
    if(indice >= 0 && indice < 3) {
        return _constantes[indice];
    }
    return 0.0f;
}

template <typename T>
T** Simulador2D<T>::_crearMatrizTemporal() {
    T** temporal = new T*[_filas];
    for(int i = 0; i < _filas; i++) {
        temporal[i] = new T[_columnas];
    }
    return temporal;
}

template <typename T>
void Simulador2D<T>::_copiarMatriz(T** origen, T** destino) {
    for(int i = 0; i < _filas; i++) {
        for(int j = 0; j < _columnas; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}

template <typename T>
void Simulador2D<T>::_liberarMatrizTemporal(T** matriz) {
    for(int i = 0; i < _filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

template <typename T>
void Simulador2D<T>::simularPaso() {
    T** temporal = _crearMatrizTemporal();
    _copiarMatriz(_grid, temporal);
    
    for(int i = 1; i < _filas - 1; i++) {
        for(int j = 1; j < _columnas - 1; j++) {
            T arriba = temporal[i-1][j];
            T abajo = temporal[i+1][j];
            T izquierda = temporal[i][j-1];
            T derecha = temporal[i][j+1];
            
            _grid[i][j] = (arriba + abajo + izquierda + derecha) / T(4);
        }
    }
    
    _liberarMatrizTemporal(temporal);
}

template <typename T>
void Simulador2D<T>::redimensionarGrid(int nuevaF, int nuevaC) {
    T** nuevoGrid = new T*[nuevaF];
    for(int i = 0; i < nuevaF; i++) {
        nuevoGrid[i] = new T[nuevaC];
    }
    
    for(int i = 0; i < nuevaF; i++) {
        for(int j = 0; j < nuevaC; j++) {
            if(i < _filas && j < _columnas) {
                nuevoGrid[i][j] = _grid[i][j];
            } else {
                nuevoGrid[i][j] = T(0);
            }
        }
    }
    
    for(int i = 0; i < _filas; i++) {
        delete[] _grid[i];
    }
    delete[] _grid;
    
    _grid = nuevoGrid;
    _filas = nuevaF;
    _columnas = nuevaC;
}

#endif 