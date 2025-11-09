//
// Created by Melissa Belalcazar on 9/11/25.
//

#include "Jugador.h"
#include "Jugador.h"
#include <iostream>
using namespace std;

void Jugador::mover(string nuevaUbicacion) {
    ubicacion = nuevaUbicacion;
    cout << nombre << " se mueve hacia " << nuevaUbicacion << "." << endl;
}

void Jugador::agregarObjeto(Objeto* obj) {
    inventario.push_back(obj);
    cout << nombre << " ha obtenido un nuevo objeto." << endl;
}

void Jugador::usarObjeto(int indice) {
    if (indice >= 0 && indice < inventario.size()) {
        cout << nombre << " usa un objeto del inventario." << endl;
        inventario.erase(inventario.begin() + indice);
    } else {
        cout << "Índice inválido." << endl;
    }
}

void Jugador::mostrarInventario() {
    if (inventario.empty()) {
        cout << "El inventario está vacío." << endl;
    } else {
        cout << "Inventario de " << nombre << ":" << endl;
        for (int i = 0; i < inventario.size(); i++) {
            cout << i << ". Objeto disponible." << endl;
        }
    }
}

void Jugador::atacar(Entidad* objetivo) {
    int danio = 15;
    cout << nombre << " ataca a " << objetivo->getNombre() << " causando " << danio << " puntos de daño." << endl;
    objetivo->recibirDanio(danio);
}
