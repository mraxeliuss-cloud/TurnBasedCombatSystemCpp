#ifndef ROGUE_H
#define ROGUE_H

#include "Jugador.h"

class Rogue : public Jugador{
    private:
    bool primerGolpe;

    public:
    
    Rogue(std::string nombre, int vida, int ataque, int defensa, int velocidad);
    void mostrarEstado() const;
    int calcularDmg(Personajes *objetivo);
    int recibirDmg(int dmg);
    void prepararCombate() override;
};
#endif