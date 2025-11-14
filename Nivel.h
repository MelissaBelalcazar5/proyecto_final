//
// Created by Melissa Belalcazar on 12/11/25.
//

#ifndef NIVEL_H
#define NIVEL_H

#include <string>
#include "Jugador.h"
#include "Enemigo.h"
using namespace std;

class Nivel {
private:
    string nombre;          // Nombre del nivel
    string descripcion;     // Texto narrativo del lugar
    Enemigo* enemigo;       // Enemigo presente en este nivel

public:
    Nivel(string n, string d, Enemigo* e);

    void mostrarIntroduccion();              // Muestra el texto de bienvenida al nivel
    void iniciarCombate(Jugador& jugador);   // Controla el combate entre jugador y enemigo
};

#endif
