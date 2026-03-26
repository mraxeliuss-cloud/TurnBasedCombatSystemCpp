#ifndef ARQUERO_H
#define ARQUERO_H

#include "Jugador.h"
#include <random>

class Arquero : public Jugador
{
private:
    // La precisión del arquero
    double precision;
    // Genera la aleatoriedad, gestionada desde la librería random
    static std::mt19937 generador;

public:
    Arquero(std::string nombre, int vida, int ataque, int defensa, int velocidad, double precision);
    int calcularDmg(Personajes *objetivo);
    void mostrarEstado() const override;
};

#endif