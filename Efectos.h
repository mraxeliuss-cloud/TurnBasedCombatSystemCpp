#ifndef EFECTOS_H
#define EFECTOS_H

#include "Personaje.h"

class Efectos
{

private:
    int duracion ;

public:
    Efectos(int duracion) : duracion (duracion){};
    virtual void aplicar(Personajes *objetivo) = 0;
    bool haTerminado() const { return duracion == 0; }
    int reducirDuracion() { return --duracion; }
    virtual std::unique_ptr<Efectos> clone() const = 0;//Hace falta para poder usar efectos en las habilidades
    virtual ~Efectos() = default;
};

#endif