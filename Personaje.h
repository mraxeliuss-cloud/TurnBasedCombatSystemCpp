#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <memory>
#include <string>
#include <vector>
#include <algorithm>

#include "Habilidades.h"
#include "Efectos.h"

class Personajes
{
private:
    std::string nombre;
    int vida;
    int ataqueBase;
    int defensa;
    int velocidad;
    bool envenenado = false;
    bool ardiendo = false;
    std::vector<Habilidad> skillSet; // ahora Habilidad es un tipo completo
    std::vector<unique_ptr<Efectos>> estados;

public:
    Personajes(std::string s, int v, int a, int d, int vel);
    // gestión de cosas
    virtual void agregaHabilidad(Habilidad h) { skillSet.push_back(std::move(h)); }
    virtual void agregaEfecto(std::unique_ptr<Efectos> e) { estados.push_back(move(e)); }
    virtual int recibirDmg(int dmg);
    virtual int calcularDmgPuro(int dmg);
    virtual void aplicarEfectos()
    {
        for (auto &e : estados)
        {
            e->aplicar(this);
            e->reducirDuracion();
        }
        estados.erase(std::remove_if(estados.begin(), estados.end(),
                                     [](const auto &e)
                                     { return e->haTerminado(); }),
                      estados.end());
    }
    bool estaVivo() const;
    // pal combate
    virtual int calcularDmg(Personajes *objetivo) = 0;
    virtual int recibirCura(int cant)
    {
        vida += cant;
        return vida;
    }
    virtual void mostrarEstado() const = 0;
    // getters
    virtual int getVida() const;
    virtual int getDaño() const;
    virtual int getVelocidad() const;
    virtual bool getVeneno() const;
    virtual bool getFuego() const;
    virtual std::string getNombre() const;
    virtual std::string getNombreHabilidad(int i) const;
    virtual int setDmg(int i) { return ataqueBase = ataqueBase + i; }
    const std::vector<Habilidad> &getHabilidades() const { return skillSet; }
    // funcionalidad
    virtual ~Personajes() = default;
};
#endif