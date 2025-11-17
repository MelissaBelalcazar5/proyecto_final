//
// Created by Melissa Belalcazar on 17/11/25.
//

#ifndef OBJETO_H
#define OBJETO_H

#include <string>

class Jugador;

class Objeto {
protected:
    std::string nombre;
    std::string descripcion;
    std::string tipo;

public:
    Objeto(const std::string& n, const std::string& d, const std::string& t)
        : nombre(n), descripcion(d), tipo(t) {}

    virtual ~Objeto() {}

    std::string getNombre() const { return nombre; }
    std::string getDescripcion() const { return descripcion; }
    std::string getTipo() const { return tipo; }

    virtual void usar(Jugador& j) = 0;
};

#endif




