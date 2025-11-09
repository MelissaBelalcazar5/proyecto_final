//
// Created by Melissa Belalcazar on 9/11/25.
//

#ifndef PROYECTO_FINAL_ENTIDAD_H
#define PROYECTO_FINAL_ENTIDAD_H


#pragma once
#include <iostream>
#include <string>
using namespace std;

class Entidad {
protected:
    string nombre;
    int vida;

public:
    Entidad(string n, int v) : nombre(n), vida(v) {}

    string getNombre() { return nombre; }
    int getVida() { return vida; }

    bool estaViva() {
        return vida > 0;
    }

    void recibirDanio(int puntos) {
        vida -= puntos;
        if (vida < 0) vida = 0;
        cout << nombre << " recibió " << puntos << " puntos de daño. Vida restante: " << vida << endl;
    }

    virtual void atacar(Entidad* objetivo) = 0;
};
#endif //PROYECTO_FINAL_ENTIDAD_H