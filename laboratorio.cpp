#include "laboratorio.h"
#include <fstream>
#include <algorithm>

Laboratorio::Laboratorio(){}

void Laboratorio::agregarFinal(const Computadora &c){
    computadoras.push_back(c);
}

void Laboratorio::mostrar(){
    cout << left;
    cout << setw(16) << "Nombre Equipo";
    cout << setw(20) << "Sistema Operativo";
    cout << setw(6) << "RAM";
    cout << setw(16) << "Microprocesador";
    cout << endl;
        for(size_t i = 0; i < computadoras.size(); i++){
        Computadora &c = computadoras[i]; 
        cout << c;
        //cout << "Nombre de Equipo: " << c.getNombreEquipo() << endl;
        //cout << "Sistema Operativo: " << c.getSistemaOperativo() << endl;
        //cout << "Tamano Ram: " << c.getTamanoRam() << endl;
        //cout << "Procesador: " << c.getProcesador() << endl;
        //cout << endl;
    }
}
void Laboratorio::respaldar_tabla(){
        int i;
        ofstream archivo("computadoras_tabla.txt");
        if(archivo.is_open()){
            archivo << left;
            archivo << setw(16) << "Nombre Equipo";
            archivo << setw(20) << "Sistema Operativo";
            archivo << setw(6) << "RAM";
            archivo << setw(16) << "Microprocesador";
            archivo << endl;
            for(size_t i = 0; i < computadoras.size(); i++){
                Computadora &c = computadoras[i]; 
                archivo << c;
            }
        }
        archivo.close();
    }

void Laboratorio::respaldar(){
        ofstream archivo("computadoras.txt");
        if(archivo.is_open()){
            for(size_t i = 0; i < computadoras.size(); i++){
                Computadora &c = computadoras[i]; 
                archivo << c.getNombreEquipo() << endl;
                archivo << c.getSistemaOperativo() << endl;
                archivo << c.getTamanoRam() << endl;
                archivo << c.getProcesador() << endl;
            }
        }
        archivo.close();
    }

void Laboratorio::recuperar(){
    ifstream archivo("computadoras.txt");
    if(archivo.is_open()){
        string temp;
        int ram;
        Computadora c;
        while (true){
            getline(archivo,temp);
            if (archivo.eof()){
                break;
            }
            c.setNombreEquipo(temp);
            getline(archivo,temp);
            c.setSistemaOperativo(temp);
            getline(archivo,temp);
            ram = stoi(temp);
            c.setTamanoRam(ram);
            getline(archivo,temp);
            c.setProcesador(temp);

            agregarFinal(c);
        }
    }
    archivo.close();
}

void Laboratorio::insertar(const Computadora &c, size_t p){
    computadoras.insert(computadoras.begin()+p, c);
}

size_t Laboratorio::size(){
    return computadoras.size();
}
void Laboratorio::inicializar(const Computadora &c, size_t n){
    computadoras = vector<Computadora>(n,c);
}
void Laboratorio::eliminar(size_t p){
    computadoras.erase(computadoras.begin()+p);
}
void Laboratorio::ordenar(){
    sort(computadoras.begin(), computadoras.end());
}

Computadora* Laboratorio::buscar(const Computadora &c){
    // vector<Computadora>::iterator
    auto it = find(computadoras.begin(), computadoras.end(), c);
    if(it == computadoras.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}