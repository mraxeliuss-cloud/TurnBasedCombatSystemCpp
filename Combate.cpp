#include <iostream>
#include <memory>
#include <vector>
#include <random>

#include "Combate.h"
#include "Personaje.h"
#include "Jugador.h"
#include "PocionCuracion.h"
#include "PocionBuffDmg.h"
#include "PocionDmg.h"

using namespace std;

Combate::Combate(std::unique_ptr<Jugador> j, std::vector<std::unique_ptr<Personajes>> e) : jugador(std::move(j)), Enemigos(move(e))
{
}
void Combate::Iniciar()
{
    int contadorTurnos = 0;
    while (jugador->estaVivo() && !Enemigos.empty())
    {

        if (jugador->getVelocidad() >= Enemigos[0]->getVelocidad())
        {
            turnoJugador();
            if (!Enemigos.empty())
            {
                turnoEnemigo();
            }
            else
            {
                break;
            }
        }
        else
        {
            turnoEnemigo();
            if (jugador->estaVivo())
            {
                turnoJugador();
            }
            else
            {
                break;
            }
        }
        contadorTurnos++;
        if (contadorTurnos == 3)
        {
            // Esto se queda en turnos
            jugador->mostrarEstado();
            // Mirar para que sea cada 3 asesinatos, no turnos
            unique_ptr<PocionCuracion> pocion = make_unique<PocionCuracion>(20);
            jugador->agregarObjeto(move(pocion));
            contadorTurnos = 0;
        }
    }
}
void Combate::turnoJugador()
{
    if (Enemigos.empty())
        return;

    jugador->aplicarEfectos();
    int accion = eligeAccionJugador();
    if (accion == 1)
    {
        int HabilidadAUsar = usarAtaqueJugador();
        const auto &habilidades = jugador->getHabilidades();
        if (HabilidadAUsar >= 0 && HabilidadAUsar < habilidades.size())
        {
            auto &enemigo = Enemigos[0];
            int dmg = habilidades[HabilidadAUsar].ejecutarAtaque(jugador.get(), enemigo.get());
            cout << jugador->getNombre() << " usa " << habilidades[HabilidadAUsar].getNombre()
                 << " causando " << dmg << " puntos de daño" << endl;
            // Ya se aplicó el daño dentro e nejecutar
            // Mostrar vida restante
            cout << "Te quedan " << jugador->getVida() << " puntos de vida" << endl;
            if (!enemigo->estaVivo())
            {
                cout << "Has derrotado a este enemigo, quedan " << Enemigos.size() - 1 << " enemigos, suerte" << endl;
                Enemigos.erase(Enemigos.begin());
            }
            else
            {
                cout << "Al enemigo le quedan " << enemigo->getVida() << " puntos de vida" << endl;
            }
        }
        else
        {
            cout << "Habilidad inválida. Pierdes el turno." << endl;
        }
    }
    else if (accion == 2)
    {

        // Hecha la versión del inventario, solo 3 items, dudo que meta más
        // El siguiente proyecto será más ambicioso
        // Hay que ver como hacer para no perder el turno si el inventario está vacío, pero ahora no se me ocurre.
        // Creo que no lo voy a hacer, si sabes que no tienes nada en el inventario, te jodes
        if (jugador->getInventario() > 0)
        {
            jugador->mostrarInventario();
            int seleccionInventario = 0;
            cout << "Que quieres emplear" << endl;
            do
            {
                cin >> seleccionInventario;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            } while (seleccionInventario == 0);
            //Falta implementar esta parte de usar el inventario, en plan, lo muestra y tal, pero no hace na
            //Igual con un for que recorra el inventario y comparaciones RAW
            switch (seleccionInventario)
            {
            case 1:
                
                break;
            
            default:
                break;
            }
        }
        else
        {
            cout << "El inventario esta vacío " << endl;
        }
    }
}

void Combate::turnoEnemigo()
{
    if (Enemigos.empty())
        return;
    // Pasamos el primer enemigo del array por referencia
    auto &enemigo = Enemigos[0];
    enemigo->aplicarEfectos();
    int dmg = enemigo->calcularDmg(jugador.get());
    cout << enemigo->getNombre() << " te ataca causando " << dmg << " puntos de daño.\n";
    jugador->recibirDmg(dmg);
    cout << "Te quedan " << jugador->getVida() << " puntos de vida" << endl;
    cout << "Al enemigo le quedan " << enemigo->getVida() << " puntos de vida" << endl;
}

int Combate::eligeAccionJugador()
{

    int elegido;
    cout << "Elige que vas a hacer este turno: " << endl;
    cout << "1. Atacar " << endl;
    // Esta opción de momento solo te va a curar, luego dará acceso al inventario entero
    cout << "2. Inventario" << endl;
    do
    {
        cin >> elegido;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (elegido < 1 || elegido > 2);
    return elegido;
}
int Combate::usarAtaqueJugador()
{

    int elegido;
    cout << "Que habilidad quieres usar: " << endl;
    for (int i = 0; i <= 3; i++)
    {
        cout << i + 1 << ". " << jugador->getNombreHabilidad(i) << endl;
    }
    do
    {
        cin >> elegido;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (elegido < 1 || elegido > 4);
    return elegido;
}
