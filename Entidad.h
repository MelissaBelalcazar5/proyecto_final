//
// Created by Melissa Belalcazar on 9/11/25.
//
#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <string>

class Entidad {
protected:
    std::string nombre;
    int vida;

public:
    Entidad(const std::string& n, int v) : nombre(n), vida(v) {}

    virtual ~Entidad() = default;

    std::string getNombre() const { return nombre; }
    int getVida() const { return vida; }

    virtual void recibirDanio(int puntos) {
        vida -= puntos;
        if (vida < 0) vida = 0;
    }

    bool estaViva() const { return vida > 0; }
};

#endif

