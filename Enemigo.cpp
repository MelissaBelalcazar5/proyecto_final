//
// Created by Melissa Belalcazar on 11/11/25.
//

#include "Enemigo.h"
#include "Enemigo.h"

void Enemigo::atacar(Entidad* objetivo) {
    cout << "💢 " << nombre << " (" << tipo << ") ataca a "
         << objetivo->getNombre() << " causando " << danioBase << " puntos de daño." << endl;

    objetivo->recibirDanio(danioBase);
}
