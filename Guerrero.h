#ifndef GUERRERO_H
#define GUERRERO_H

#include "Jugador.h"   // ← antes era Personaje.h

class Guerrero : public Jugador {
private:
    int armadura;
public:
    Guerrero(std::string nombre, int vida, int ataque, int defensa, int velocidad, int armadura);
    void mostrarEstado() const override;          // añade const y override
    int calcularDmg(Personajes *objetivo) override;   // solo devuelve daño
    int recibirDmg(int dmg);
};

#endif