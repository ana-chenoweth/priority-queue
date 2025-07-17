#include <iostream>
#include "ColaMedieval.hpp"

//**********************************************
ColaMedieval::ColaMedieval() : tam(0), tamNoble(0), tamPlebeyo(0), fondo(nullptr), fondoNoble(nullptr)
{
}
//**********************************************

ColaMedieval::~ColaMedieval()
{
    Vaciar();
}
//***********************************************
ColaMedieval::ColaMedieval(const ColaMedieval &c) : tam(0), tamNoble(0), tamPlebeyo(0), fondo(nullptr), fondoNoble(nullptr)
{
    *this = c;
}
//*********************************************

ColaMedieval& ColaMedieval::operator=(const ColaMedieval& c) {
    if (this == &c) return *this;
    Vaciar();
    Individuo* actual = c.fondo->siguiente;
    while (actual != fondo) {
        Agregar(actual->nombre, actual->claseSocial);
        actual = actual->siguiente;
    }
    return *this;
}
