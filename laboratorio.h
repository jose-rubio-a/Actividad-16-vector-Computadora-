#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "computadora.h"
#include <vector>

class Laboratorio{
    private:
    vector<Computadora> computadoras;
    
    public:
    Laboratorio();

    void agregarFinal(const Computadora &c);
    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();
    void eliminar(size_t p);
    void ordenar();
    Computadora* buscar(const Computadora &c);

    void insertar(const Computadora &c, size_t p);
    size_t size();
    void inicializar(const Computadora &c, size_t n);

    friend Laboratorio& operator << (Laboratorio &l, Computadora &c){
        l.agregarFinal(c);

        return l;
    }
};

#endif