#ifndef FUEGO_H
#define FUEGO_H

#include "Efectos.h"
#include "Personaje.h"

class Fuego : public Efectos
{

private:
    int duracion = 3;
    int dañoPorTurno = 8;

public:
    // Quiero ver si hay un método más elegante que solo crear un método de daño puro
    Fuego(int duracion, int dañoPorTurno) : Efectos(duracion), dañoPorTurno(dañoPorTurno){}
    void aplicar(Personajes *objetivo) override
    {
        objetivo->calcularDmgPuro(dañoPorTurno);
    }
    std::unique_ptr<Efectos> clone() const override
    {
        return std::make_unique<Fuego>(duracion, dañoPorTurno);
    }
    int getDuracion(){ return duracion;}
};

#endif