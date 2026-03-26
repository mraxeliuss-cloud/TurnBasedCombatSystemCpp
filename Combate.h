#ifndef COMBATE_H
#define COMBATE_H

#include <vector>
#include <memory>
#include "Personaje.h"
#include "Jugador.h"

class Combate
{
private:
    std::unique_ptr<Jugador> jugador;
    std::vector<std::unique_ptr<Personajes>> Enemigos;
    int enemigoActual = 0;

    void turnoJugador();
    void turnoEnemigo();
    int eligeAccionJugador();
    int usarAtaqueJugador();

public:
    Combate(std::unique_ptr<Jugador> j, std::vector<std::unique_ptr<Personajes>> e);
    void Iniciar();
};

#endif