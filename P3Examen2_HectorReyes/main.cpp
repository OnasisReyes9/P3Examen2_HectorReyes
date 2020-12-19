/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Onasis Reyes
 *
 * Created on 18 de diciembre de 2020, 01:18 PM
 */

#include <cstdlib>

#include "Relacion.h"

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

using std::string;
using namespace std;

//void crear_relaciones(vector <Relacion*>);
void crear_relaciones(vector <Relacion*>&);

void listar_relaciones();

void escribir_relaciones(vector<Relacion*>);
void escribir_relacion(Relacion* relacion);

void insertar_tupla(vector<Relacion*>&);

void agregar_tupla(string, Tupla*);

/*
 * 
 */
int main(int argc, char** argv) {
    int opcion = 0;
    bool continuar = true;
    vector <Relacion*> lista_relaciones;
    while (continuar) {
        cout << "---Menu---\n"
                "0. Salir\n"
                "1. Crear Relacion\n"
                "2. Ver Relaciones\n"
                "3. Insertar Tupla\n"
                "-> Escoja su opcion: ";
        cin >> opcion;
        cout << "\n";
        switch (opcion) {
            case 1:
            {
                crear_relaciones(lista_relaciones);
                break;
            }
            case 2:
            {
                listar_relaciones();
                break;
            }
            case 3:
            {
                insertar_tupla(lista_relaciones);
                break;
            }
            case 0:
            {
                continuar = false;
                cout << "Fin de la ejecución.";
                break;
            }
            default:
            {
                cout << "Opcion inexistente.";
            }
        }
        cout << "\n";
    }//fin while
    return 0;
}//fin main

void crear_relaciones(vector <Relacion*>& lista_relaciones) {
    //creo las relaciones
    string nombre_relacion = "";
    cout << "Ingrese el nombre de la relacion: ";
    cin >> nombre_relacion;
    int opcion_encabezado = 1;
    string encabezado = "";
    vector <string> lista_encabezados;
    //agrego los encabezados
    do {
        cout << "Ingrese encabezado: ";
        cin >> encabezado;
        cout << "------"
                "\n0.Salir: "
                "\n1. Agregar otro encabezado: "
                "\n-> Seleccione: ";
        cin >> opcion_encabezado;
        while (opcion_encabezado < 0 || opcion_encabezado > 1) {
            cout << "\nPorfavor seleccione una opcion valida.";
            cout << "------"
                    "\n0. Salir: "
                    "\n1. Agregar otro encabezado: "
                    "\n-> Seleccione: ";
            cin >> opcion_encabezado;
        }//fin while
        lista_encabezados.push_back(encabezado);
        cout << "\n";
    } while (opcion_encabezado == 1);

    Relacion* relacion = new Relacion(lista_encabezados, nombre_relacion);
    lista_relaciones.push_back(relacion);

    escribir_relacion(relacion);
    escribir_relaciones(lista_relaciones);
}//fin método

void escribir_relacion(Relacion* relacion) {
    ofstream save_file;
    string direccion = relacion->getNombre() + ".txt";
    save_file.open(direccion, ofstream::out | ofstream::app);
    if (save_file.is_open()) {
        save_file << relacion->toStringTupla();
    }//fin if
    save_file.close();
}//fin método

void escribir_relaciones(vector<Relacion*> lista_relaciones) {
    //escribe el archivo
    ofstream save_file;
    save_file.open("lista_relaciones.txt", ofstream::out | ofstream::app);
    if (save_file.is_open()) {
        for (int i = 0; i < lista_relaciones.size(); i++) {
            save_file << ((Relacion*) lista_relaciones.at(i))->toString();
        }//fin for
    }//fin if
    save_file.close();
}//fin método

void insertar_tupla(vector<Relacion*>& lista_relaciones) {
    listar_relaciones();
    vector <string> lista_atributos;
    int opcion_tupla = 1;
    int index = 0;
    string atributo_tupla = "";
    cout << "Ingrese la posicion de la relacion: ";
    cin >> index;
    int id = 0;
    do {
        id = (1000) + rand() % ((9999 + 1) - (1000));
        cout << "Ingrese atributo: ";
        cin>>atributo_tupla;
        cout << "------"
                "\n0.Salir: "
                "\n1. Agregar otro atributo: "
                "\n-> Seleccione: ";
        cin >> opcion_tupla;
        while (opcion_tupla < 0 || opcion_tupla > 1) {
            cout << "\nPorfavor seleccione una opcion valida.";
            cout << "------"
                    "\n0. Salir: "
                    "\n1. Agregar otro atributo: "
                    "\n-> Seleccione: ";
            cin >> opcion_tupla;
        }//fin while
        lista_atributos.push_back(atributo_tupla);
        cout << endl;
    } while (opcion_tupla == 1);
    Tupla* tupla = new Tupla(id, lista_atributos);
    string nombre_archivo = ((Relacion*)lista_relaciones.at(index))->getNombre() + ".txt";
    //agregar_tupla(nombre_archivo, Tupla);
}//fin metodo

void agregar_tupla(string nombre_archivo, Tupla* tupla) {
    string new_info = "";
    ifstream leer(nombre_archivo);
    if (leer) {
        ofstream escribir;
        escribir.open(nombre_archivo, ofstream::out | ofstream::app);
        escribir << new_info + tupla->tuplaToString();
        escribir.close();
    } else {
        ofstream escritura(nombre_archivo);
        escritura << new_info;
        escritura.close();
    }//fin else
}//fin metodo

void listar_relaciones() {
    vector <string> listar_relaciones;
    ifstream leer;
    leer.open("lista_relaciones.txt");
    if (leer.is_open()) {
        while (!leer.eof()) {
            string newRow;
            //cout << newRow << endl;
            getline(leer, newRow);
            listar_relaciones.push_back(newRow);
        }//fin while
        leer.close();
    }//fin if
    for (int i = 0; i < listar_relaciones.size(); i++) {
        cout << i + ". " + listar_relaciones.at(i);
        cout << endl;
    }//fin for
    cout << "Que relacion desea visualizar: ";
}//fin método*/

