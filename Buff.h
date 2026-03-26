#ifndef BUFF_H
#define BUFF_H

#include "Efectos.h"
#include "Personaje.h"

class Buff : public Efectos
{

private:
    int duracion = 4;
    int aumento = 6;

public:
    //Miraré también de crear uno que aumente la precisión o algo
    Buff(int duracion, int aumento) : Efectos(duracion), aumento(aumento){}
    void aplicar(Personajes *objetivo) override
    {
        objetivo->setDmg(aumento);
    }
        std::unique_ptr<Efectos> clone() const override {
        return std::make_unique<Buff>(duracion, aumento);
    }
    int getDuracion(){ return duracion;}
};

#endif