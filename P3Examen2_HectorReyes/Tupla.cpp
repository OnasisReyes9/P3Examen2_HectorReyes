/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tupla.cpp
 * Author: Onasis Reyes
 * 
 * Created on 18 de diciembre de 2020, 01:30 PM
 */

#include "Tupla.h"

Tupla::Tupla() {
}

Tupla::Tupla(const Tupla& orig) {
}

Tupla::~Tupla() {
}

string Tupla::tuplaToString() {
    string info_tupla = ID + "-Atributos: - ";
    for (int i = 0; i < lista_atributos.size(); i++) {
        info_tupla = info_tupla + lista_atributos.at(i) + ", ";
    }
    return info_tupla + "\n";
}//fin método

