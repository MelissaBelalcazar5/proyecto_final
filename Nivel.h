//
// Created by Melissa Belalcazar on 12/11/25.
//
#ifndef NIVEL_H
#define NIVEL_H

#include <string>
#include "Enemigo.h"
#include "Objeto.h"


class Jugador;

class Nivel {
private:
    std::string nombre;
    std::string descripcion;
    Enemigo* enemigo;
    Objeto* objetoDelNivel;

public:
    Nivel(std::string n, std::string d, Enemigo* e, Objeto* recompensa);
    void mostrarIntroduccion();
void iniciarCombate(Jugador& jugador);
};

#endif


