#ifndef OBJETOS_H
#define OBJETOS_H

#include <memory>
#include <string>
class Personajes;

class Objetos
{
    private: 


public:
    virtual ~Objetos() = default;
    virtual std::string getNombre() const = 0;
    virtual std::string getEfectoPocion() const = 0;
    virtual void usarObjeto(Personajes *objetivo) = 0;
};

#endif