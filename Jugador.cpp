//
// Created by Melissa Belalcazar on 9/11/25.
//

#include "Jugador.h"
#include <iostream>
using namespace std;

void Jugador::mover(const string& dir) {
    ubicacion = dir;
    cout << nombre << " se mueve hacia " << dir << "." << endl;
}

void Jugador::defender() {
    defendiendo = true;
    cout << "🛡️ " << nombre << " se prepara para defenderse." << endl;
}

void Jugador::atacar(Entidad* objetivo) {
    int danio = getDanioTotal();

    cout << "⚔️ " << nombre << " ataca a " << objetivo->getNombre()
         << " causando " << danio << " puntos de daño." << endl;

    objetivo->recibirDanio(danio);
}

void Jugador::recibirDanio(int puntos) {
    if (esquivarProximo) {
        cout << "✨ " << nombre << " esquiva el ataque gracias al Cristal del Tiempo." << endl;
        esquivarProximo = false;
        return;
    }

    if (amuletoActivo) {
        puntos = (int)(puntos * 0.8);
        cout << "🔮 El Amuleto reduce el daño a " << puntos << "." << endl;
    }

    if (armaduraActiva) {
        puntos = (int)(puntos * (1.0 - reduccionArmadura));
        cout << "🛡️ La armadura reduce el daño a " << puntos << "." << endl;
    }

    if (defendiendo) {
        puntos /= 2;
        cout << "🛡️ Defensa activa: daño reducido a " << puntos << "." << endl;
        defendiendo = false;
    }

    vida -= puntos;
    if (vida < 0) vida = 0;

    cout << nombre << " recibe " << puntos << " de daño. Vida actual: "
         << vida << endl;
}

void Jugador::curar(int puntos) {
    vida += puntos;
    if (vida > vidaMaxima) vida = vidaMaxima;

    cout << "💖 " << nombre << " se cura " << puntos << " puntos. Vida actual: "
         << vida << "/" << vidaMaxima << endl;
}

void Jugador::agregarObjeto(Objeto* obj) {
    inventario.push_back(obj);
    cout << "🎁 Obtuviste: " << obj->getNombre() << endl;
}

void Jugador::mostrarInventario() const {
    if (inventario.empty()) {
        cout << "👜 Tu inventario está vacío." << endl;
        return;
    }

    cout << "👜 Inventario:" << endl;
    for (size_t i = 0; i < inventario.size(); i++) {
        cout << i << ". " << inventario[i]->getNombre()
             << " (" << inventario[i]->getTipo() << ")" << endl;
    }
}

void Jugador::usarObjeto(int idx) {
    if (inventario.empty()) {
        cout << "❌ No tienes objetos para usar." << endl;
        return;
    }

    if (idx < 0 || idx >= (int)inventario.size()) {
        cout << "❌ Índice inválido." << endl;
        return;
    }

    Objeto* obj = inventario[idx];
    obj->usar(*this);

    delete obj;
    inventario.erase(inventario.begin() + idx);
}

void Jugador::incrementarDanio(int cantidad) {
    danioExtra += cantidad;
    cout << "⚔️ Tu ataque aumenta permanentemente +" << cantidad
         << " (Total: " << getDanioTotal() << ")." << endl;
}

void Jugador::activarAmuleto() {
    amuletoActivo = true;
    cout << "🔮 El Amuleto de Luz está activo (20% menos daño recibido)." << endl;
}

void Jugador::activarArmadura() {
    armaduraActiva = true;
    reduccionArmadura = 0.30;
    cout << "🛡️✨ Has obtenido la Armadura Sagrada. Reducirás 30% del daño recibido." << endl;
}

void Jugador::activarEsquiva() {
    esquivarProximo = true;
    cout << "✨ El Cristal del Tiempo te permitirá esquivar el próximo ataque." << endl;
}
void Jugador::ganarExperiencia(int cantidad) {
    experiencia += cantidad;
    cout << "⭐ Ganas " << cantidad << " puntos de experiencia. (Total: " << experiencia << ")\n";

    if (experiencia >= nivel * 50) {
        subirNivel();
    }
}

void Jugador::subirNivel() {
    nivel++;
    experiencia = 0;

    vidaMaxima += 20;
    vida = vidaMaxima;
    danioBase += 5;

    cout << "💖 Vida máxima aumentada a " << vidaMaxima << endl;
    cout << "⚔️ Daño base aumentado a " << danioBase << endl;
    cout << "✨ ¡Te sientes más fuerte y poderoso!\n\n";
}






