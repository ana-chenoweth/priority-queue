#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include "priority-queue/ColaMedieval.hpp"

using namespace std;

void pausee() {
    std::cout << "Presiona Enter para continuar...";
    std::cin.get();
}

int main() {
    srand(time(NULL));
    const int intervaloAtencionTotal   = 120;
    const int tiempoEspera = 5;
    const int prob = 80;
    int  clase = rand() % 2;
    ColaMedieval colaEspera;
    ColaMedieval colaAtendidos;

    string claseSocialCiudadano = "";
    string actualCiudadano = "";
    int CiudadanoTiempo = 1;
    int tiempo = 1, minutos = 0;
    bool ocupado = false;

    cout << "**********************************************************\n"
         << "               REY                                        \n"
         << "                                                          \n"
         << "Tiempo del rey del dia de hoy: " << intervaloAtencionTotal << " minutos.\n\n"
         << "Tiempo de espera del dia de hoy: " << tiempoEspera << " minutos.\n\n"
         << "**********************************************************" << endl;
    pausee();

    return 0;
}
