#ifndef POCIONCURACION_H
#define POCIONCURACION_H

#include <memory>
#include <string>

#include "Personaje.h"
#include "Objetos.h"

class PocionCuracion : public Objetos
{
private:

    int cantidad;
    std::string nombre = "Pocion de Curacion";

public:
    PocionCuracion( int cant) : cantidad(cant)
    {
    }
    std::string getNombre() const override { return nombre; }
    std::string getEfectoPocion() const override {return "(+ " + to_string(cantidad) + " puntos de vida )";}
    void usarObjeto(Personajes *objetivo) override
    {
        objetivo->recibirCura(cantidad);
    }
};
#endif