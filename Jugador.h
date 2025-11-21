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
    int vidaMaxima = 110;
    int nivel = 1;
    int experiencia = 0;
    int experienciaMax = 50;
    int danioBase = 20;
    int danioExtra = 0;
    bool amuletoActivo = false;
    bool esquivarProximo = false;
    bool armaduraActiva = false;
    double reduccionArmadura = 0.0;

public:
    Jugador(std::string n, int v = 100) : Entidad(n, v), vidaMaxima(v) {}

    void ganarExperiencia(int cantidad);
    void subirNivel();
    int getNivel() const { return nivel; }
    int getExperiencia() const { return experiencia; }

    void mover(const std::string& dir);
    void defender();
    void atacar(Entidad* objetivo);

    void recibirDanio(int puntos);
    void curar(int puntos);

    void setDanioTotal(int total) {
        danioExtra = total - danioBase;
        if (danioExtra < 0) danioExtra = 0;
    }

    void agregarObjeto(Objeto* obj);
    void mostrarInventario() const;
    void usarObjeto(int idx);

    void incrementarDanio(int cantidad);
    void activarAmuleto();
    void activarEsquiva();
    void activarArmadura();

    int getDanioTotal() const { return danioBase + danioExtra; }

    std::string getUbicacion() const { return ubicacion; }

    const std::vector<Objeto*>& getInventario() const { return inventario; }

    bool tieneAmuleto() const { return amuletoActivo; }
    bool tieneArmadura() const { return armaduraActiva; }

    void limpiarInventario() {
        for (Objeto* o : inventario) delete o;
        inventario.clear();
    }

    void setDanioBase(int extra) { danioExtra = extra; }
};

#endif

