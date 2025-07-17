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

string nombreAleatorio() {
    string nombres[] = {"Maria", "Jose", "Carmen", "Juan", "Ana", "Antonio", "Laura", "Francisco", "Isabel", "David", "Rosa", "Miguel", "Elena", "Manuel", "Patricia", "Luis", "Carolina", "Javier", "Marta", "Pedro", "Natalia", "Diego", "Cristina", "Carlos", "Lucia", "Alejandro", "Paula", "Angela", "Sergio", "Nuria", "Pablo", "Raquel", "Daniel", "Sara", "Fernando", "Beatriz", "Ricardo", "Claudia", "Ruben", "Andrea", "Adrian", "Elena", "Jesus", "Marta", "Alberto", "Lorena", "Jorge", "Georgina", "Denisse", "Omar", "Ivan", "Silvia"};
    string apellidos[] = {"Garcia", "Rodriguez", "Martinez", "Lopez", "Gonzalez", "Sanchez", "Perez", "Gomez", "Fernandez", "Ruiz", "Diaz", "Moreno", "Alvarez", "Romero", "Navarro", "Torres", "Dominguez", "Vazquez", "Ramos", "Jimenez", "Martinez", "Gutierrez", "Herrero", "Rojas", "Morales", "Ortega", "Delgado", "Castro", "Castillo", "Carrasco", "Cordero", "Cabello", "Reyes", "Medina", "Aguilar", "Bravo", "Molina", "Leon", "Marin", "Blanco", "Gallego", "Ramirez", "Suarez", "Ortega", "Nunez", "Salazar", "Iglesias", "Mendez", "Moya", "Estevez", "Salcido", "Valenzuela", "Galaz", "Chenoweth", "Antunez"};

    string nombreCompleto = nombres[rand() % sizeof(nombres) / sizeof(string)] + " " + apellidos[rand() % sizeof(apellidos) / sizeof(string)];
    return nombreCompleto;
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

    for(int i = 0; i < intervaloAtencionTotal; ++i){
        system("clear");
        cout << "Reloj: " << minutos << "\n\n";
        if(!(colaEspera.ObtenerTam()==0) && ocupado == false){
            actualCiudadano = colaEspera.ObtenerFrente();
            claseSocialCiudadano = colaEspera.ObtenerClaseSocialFrente();
            colaEspera.Eliminar();
            CiudadanoTiempo = rand()%tiempoEspera + 1;
            ocupado = true;
        }
        if(ocupado){
            cout << "Subdito con el rey: " << actualCiudadano << "\t\t";
            cout << "Tiempo de atencion: " << tiempo;
        }
        else cout << "El rey esta desocupado." << endl;

        if(ocupado) tiempo++;
        if(tiempo > tiempoEspera){
            if(claseSocialCiudadano == "Plebeyo") colaAtendidos.Agregar(actualCiudadano, "Plebeyo");
            else colaAtendidos.Agregar(actualCiudadano, "Noble");
            actualCiudadano = "";
            claseSocialCiudadano = "";
            ocupado = false;
            tiempo = 1;
        }
        if(rand()%100 <= prob){
            if(rand()%100 >= 70){
                colaEspera.Agregar(nombreAleatorio(), "Noble");
            }
            else{
                colaEspera.Agregar(nombreAleatorio(), "Plebeyo");
            }
        }
        cout << "\n\n\n\n> En espera: " << endl;
        colaEspera.Imprimir();

        sleep(1);
        minutos++;
    }

    return 0;
}
