/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tupla.h
 * Author: Onasis Reyes
 *
 * Created on 18 de diciembre de 2020, 01:30 PM
 */

#ifndef TUPLA_H
#define TUPLA_H

#include <string>
using std::string;

#include <vector>
using std::vector;

class Tupla {
public:
    Tupla();
    Tupla(const Tupla& orig);
    virtual ~Tupla();

    string tuplaToString();


    Tupla(int ID, vector<string> lista_atributos) :
    ID(ID), lista_atributos(lista_atributos) {
    }

    int getID() const {
        return ID;
    }

    void setID(int ID) {
        this->ID = ID;
    }

    vector<string> getLista_atributos() const {
        return lista_atributos;
    }

    void setLista_atributos(vector<string> lista_atributos) {
        this->lista_atributos = lista_atributos;
    }
    
private:
    int ID;
    vector <string> lista_atributos;
};

#endif /* TUPLA_H */

