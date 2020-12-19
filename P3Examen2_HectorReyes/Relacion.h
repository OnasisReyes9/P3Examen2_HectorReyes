/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Relacion.h
 * Author: Onasis Reyes
 *
 * Created on 18 de diciembre de 2020, 01:28 PM
 */

#ifndef RELACION_H
#define RELACION_H

#include <string>
using std::string;

#include "Tupla.h"

#include <vector>
using std::vector;

class Relacion {
public:
    Relacion();
    Relacion(const Relacion& orig);
    virtual ~Relacion();
    
    string toString();
    string toStringTupla();
    
    Relacion(vector<string> lista_encabezados, string nombre, vector<Tupla*> lista_objetos) :
    lista_encabezados(lista_encabezados), nombre(nombre), lista_objetos(lista_objetos) {
    }
    
    Relacion(vector<string> lista_encabezados, string nombre) :
    lista_encabezados(lista_encabezados), nombre(nombre) {
    }

    vector<string> getLista_encabezados() const {
        return lista_encabezados;
    }

    void setLista_encabezados(vector<string> lista_encabezados) {
        this->lista_encabezados = lista_encabezados;
    }

    vector<Tupla*> getLista_objetos() const {
        return lista_objetos;
    }

    void setLista_objetos(vector<Tupla*> lista_objetos) {
        this->lista_objetos = lista_objetos;
    }

    string getNombre() const {
        return nombre;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }
    
private:
    vector <string> lista_encabezados;
    string nombre;
    vector <Tupla*> lista_objetos;
};

#endif /* RELACION_H */

