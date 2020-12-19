/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Relacion.cpp
 * Author: Onasis Reyes
 * 
 * Created on 18 de diciembre de 2020, 01:28 PM
 */

#include "Relacion.h"

Relacion::Relacion() {
}

Relacion::Relacion(const Relacion& orig) {
}

Relacion::~Relacion() {
}

string Relacion::toStringTupla() {
     string info_relacion = "Nombre: " + nombre + "-Encabezados";
    for (int i = 0; i < lista_encabezados.size(); i++) {
        info_relacion = info_relacion + lista_encabezados.at(i) + ", ";
    }
    info_relacion = " - ";
    for (int i = 0; i < lista_objetos.size(); i++) {
        info_relacion = info_relacion + (((Tupla*) lista_objetos.at(i))->tuplaToString());
    }//fin for
    return info_relacion;
}//fin método

string Relacion::toString() {
    string info_relacion = "Nombre: " + nombre + "- Encabezados: ";
    for (int i = 0; i < lista_encabezados.size(); i++) {
        info_relacion = info_relacion + lista_encabezados.at(i) + ", ";
    }
    return info_relacion + "\n";
}
