//
// Created by Melissa Belalcazar on 11/11/25.
//

#include "Enemigo.h"
#include "Jugador.h"
#include <iostream>
using namespace std;

void Enemigo::atacar(Jugador& jugador) {
    cout << "💢 " << tipo << " " << nombre
         << " ataca causando " << dano << " puntos de daño." << endl;

    jugador.recibirDanio(dano);
}

