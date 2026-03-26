#ifndef VENENO_H
#define VENENO_H

#include "Efectos.h"
#include "Personaje.h"

class Veneno : public Efectos
{

private:
    int duracion;
    int dañoPorTurno = 6;

public:
    Veneno(int duracion, int dañoPorTurno) : Efectos(duracion), dañoPorTurno(dañoPorTurno){}
    // Tengo que ver como hacer para que el daño no se vea reducido por la armadura
    // Igual creo un método en personaje que simplemente baje la vida en bruto, sin defensas
    void aplicar(Personajes *objetivo) override
    {
        objetivo->calcularDmgPuro(dañoPorTurno);
    }

    std::unique_ptr<Efectos> clone() const override {
        return std::make_unique<Veneno>(duracion, dañoPorTurno);
    }

};

#endif