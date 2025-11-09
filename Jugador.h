//
// Created by Melissa Belalcazar on 9/11/25.
//

#ifndef PROYECTO_FINAL_JUGADOR_H
#define PROYECTO_FINAL_JUGADOR_H


#pragma once
#include "Entidad.h"
#include <vector>
#include <string>
using namespace std;

class Objeto;

class Jugador : public Entidad {
private:
    vector<Objeto*> inventario;
    string ubicacion;

public:
    Jugador(string n, int v) : Entidad(n, v) {}

    void mover(string nuevaUbicacion);
    void agregarObjeto(Objeto* obj);
    void usarObjeto(int indice);
    void mostrarInventario();
    void atacar(Entidad* objetivo) override;
};
#endif //PROYECTO_FINAL_JUGADOR_H