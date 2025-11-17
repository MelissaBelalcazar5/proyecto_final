//
// Created by Melissa Belalcazar on 9/11/25.
//

#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <vector>
#include "Entidad.h"
#include "Objeto.h"

class Jugador : public Entidad {
private:
    std::vector<Objeto*> inventario;
    std::string ubicacion = "inicio";
    bool defendiendo = false;
    int vidaMaxima = 100;

    int danioBase = 15;
    int danioExtra = 0;
    bool amuletoActivo = false;
    bool esquivarProximo = false;

public:
    Jugador(std::string n, int v = 100) : Entidad(n, v), vidaMaxima(v) {}

    //Movimiento y combate
    void mover(const std::string& dir);
    void defender();
    void atacar(Entidad* objetivo);

    //Vida
    void recibirDanio(int puntos);
    void curar(int puntos);

    //Inventario
    void agregarObjeto(Objeto* obj);
    void mostrarInventario() const;
    void usarObjeto(int idx);

    //Efectos de objetos
    void incrementarDanio(int cantidad);
    void activarAmuleto();
    void activarEsquiva();

    int getDanioTotal() const { return danioBase + danioExtra; }
    std::string getUbicacion() const { return ubicacion; }
};

#endif

