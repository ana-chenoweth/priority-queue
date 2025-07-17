#ifndef ColaMedievalMEDIEVAL_HPP_INCLUDED
#define ColaMedievalMEDIEVAL_HPP_INCLUDED

    class ColaVacia : public std::exception{
    public:
        virtual const char * what() const throw();
     };
class ColaMedieval
{
public:
    ColaMedieval();
    ~ColaMedieval();
    ColaMedieval(const ColaMedieval &c);
    ColaMedieval &operator=(const ColaMedieval &c);
    void Agregar(std::string nombre, std::string claseSocial);
    void Eliminar();
    bool EstaVacia() const;

private:
    int tam;
    int tamNoble;
    int tamPlebeyo;
    struct Individuo
    {
        std::string nombre;
        std::string claseSocial;
        Individuo *siguiente;

        Individuo(std::string nom, std::string cs, Individuo *sig) : nombre(nom), claseSocial(cs), siguiente(sig) {}
    };

    Individuo *fondo;
    Individuo *fondoNoble;
};

#endif // ColaMedievalMEDIEVAL_HPP_INCLUDED
