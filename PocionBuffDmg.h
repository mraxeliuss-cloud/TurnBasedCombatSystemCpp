#ifndef POCIONBUFFDMG_H
#define POCIONBUFFDMG_H

#include <memory>
#include <string>

#include "Buff.h"
#include "Personaje.h"
#include "Objetos.h"

class PocionBuffDmg : public Objetos
{
private:
    int cantidad = 6;
    int duracion = 2;
    std::string nombre = "Poción de Ataque";

public:
    PocionBuffDmg(int duracion, int cant) : duracion(duracion), cantidad(cant)
    {
    }
    std::string getNombre() const override
    {
        return nombre;
    }
    void usarObjeto(Personajes *objetivo) override
    {
        auto efecto = std::make_unique<Buff>(duracion, cantidad);
        objetivo->agregaEfecto(std::move(efecto));
    }
    std::string getEfectoPocion() const override { 
    return "(+ " + std::to_string(cantidad) + " puntos de daño durante " + std::to_string(duracion) + " turnos)"; }
};
#endif