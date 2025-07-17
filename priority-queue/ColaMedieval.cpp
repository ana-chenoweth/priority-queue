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
//*********************************************************************************************************
void ColaMedieval::Agregar(std::string nombre, std::string claseSocial) {
    Individuo* nuevo = new Individuo(nombre, claseSocial, nullptr);
    if (EstaVacia()) {
        fondo = nuevo;
        fondo->siguiente = fondo;
        if (claseSocial == "Noble") {
            fondoNoble = fondo;
            tamNoble++;
        } else {
            tamPlebeyo++;
        }
    } else {
        if (claseSocial == "Noble") {
            if (fondoNoble == nullptr) {
                nuevo->siguiente = fondo->siguiente;
                fondo->siguiente = nuevo;
                fondoNoble = nuevo;
            } else {
                nuevo->siguiente = fondoNoble->siguiente;
                fondoNoble->siguiente = nuevo;
                fondoNoble = nuevo;
            }
            tamNoble++;
        } else {
            nuevo->siguiente = fondo->siguiente;
            fondo->siguiente = nuevo;
            fondo = nuevo;
            tamPlebeyo++;
        }
    }
    tam++;
}