#ifndef POCIONDMG_H
#define POCIONDMG_H

#include <memory>
#include <string>

#include "Personaje.h"
#include "Objetos.h"

class PocionDmg : public Objetos
{
private:
    int cantidad;
    std::string nombre = "Bomba"; 

public:
    PocionDmg(int cant) : cantidad(cant)
    {
    }
    std::string getNombre() const override { return nombre;}
    void usarObjeto(Personajes *objetivo) override
    {
        objetivo->calcularDmgPuro(cantidad);
    }
    std::string getEfectoPocion() const override
    {
    return "(- " + std::to_string(cantidad) + " puntos de vida al enemigo)";
    }
};
#endif