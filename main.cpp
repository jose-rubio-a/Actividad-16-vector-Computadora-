#include <iostream>
#include "laboratorio.h"
using namespace std;

int main() {
    Laboratorio lb;
    string op;
    while (true)
    {
        cout << "1) Agregar Personaje" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Respaldar" << endl;
        cout << "4) Recuperar" << endl;
        cout << "5) Insertar" << endl;
        cout << "6) Inicializar" << endl;
        cout << "7) Eliminar" << endl;
        cout << "8) Ordenar" << endl;
        cout << "9) Buscar" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: ";
        getline(cin, op);
        if (op == "1"){
            Computadora c;
            cin >> c;
            lb.agregarFinal(c);
        }
        else if (op == "2"){
            lb.mostrar();
        }
        else if (op == "3"){
            lb.respaldar();
        }
        else if (op == "4"){
            lb.recuperar();
        }
        else if (op == "5"){
            Computadora c;
            cin >> c;
            size_t p;
            cout << "Posicion: ";
            cin >> p;
            cin.ignore();
            if(p >= lb.size()){
                cout << "Posicion no valida" << endl;
            }
            else {
                lb.insertar(c,p);
            }
        }
        else if (op == "6"){
            Computadora c;
            cin >> c;
            size_t n;
            cout << "n: ";
            cin >> n;
            cin.ignore();
            lb.inicializar(c, n);
        }
        else if (op == "7"){
            size_t p;
            cout << "Posicion: ";
            cin >> p;
            cin.ignore();
            if(p >= lb.size()){
                cout << "Posicion no valida" << endl;
            }
            else {
                lb.eliminar(p);
            }
        }
        else if (op == "8"){
            lb.ordenar();
        }
        else if (op == "9"){
            Computadora c;
            cin >> c;
            Computadora *ptr = lb.buscar(c);
            if(ptr == nullptr){
                cout << "No encontrado" << endl;
            }
            else{
                cout << *ptr << endl;
            }
        }
        else if (op == "0"){
            break;
        }
        else{
            cout << "Opcion no valida" << endl;
        }
    }
    
    return 0;
}