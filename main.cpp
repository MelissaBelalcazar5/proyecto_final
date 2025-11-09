//
// Created by Melissa Belalcazar on 9/11/25.
//
#include <iostream>
#include "Entidad.h"
#include "Jugador.h"
using namespace std;

int main() {
    cout << "🌟 BIENVENIDO A: RESCATE EN LA TORRE DE CRISTAL 🌟" << endl;
    cout << "-----------------------------------------------" << endl;

    Jugador arion("Arion", 100);

    cout << "\n👤 Jugador creado: " << arion.getNombre() << endl;
    cout << "❤️ Vida inicial: " << arion.getVida() << endl;

    arion.mover("Bosque Encantado");

    cout << "\n⚔️ Arion practica su espada contra un muñeco de entrenamiento..." << endl;

    // Enemigo temporal para probar
    class EnemigoPrueba : public Entidad {
    public:
        EnemigoPrueba(string n, int v) : Entidad(n, v) {}
        void atacar(Entidad* objetivo) override {
            cout << nombre << " intenta atacar, pero es solo un muñeco 😅" << endl;
        }
    };

    EnemigoPrueba dummy("Muñeco de madera", 40);
    arion.atacar(&dummy);

    cout << "\n✅ Prueba finalizada. El sistema de jugador y ataque funciona correctamente." << endl;

    return 0;
}
