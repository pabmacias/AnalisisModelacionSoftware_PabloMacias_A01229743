#include <iostream>

class Personaje
{
public:
    virtual void correr() = 0;
    virtual void displayInstance() = 0;
    virtual Personaje* clonar() = 0;

		template<class SubClase>
    static Personaje* factoryMethod()
    {
        Personaje* p = Personaje::getInstance<SubClase>();
				SubClase t;
				p = t.clonar();
        p->displayInstance();
        return p;
    }

    template<class SubClase>
    static Personaje* getInstance()
    {
        if(SubClase::instance != 0)
        {
            return SubClase::instance;
        }
        else
        {
            SubClase();
            return SubClase::instance;
        }
    }
};

template <class SubClase>
class ClonPersonaje : public Personaje
{
public:
    virtual Personaje* clonar()
    {
         return new SubClase(dynamic_cast<SubClase&>(*this));
    }
};

class Principe : public ClonPersonaje<Principe>
{
public:
    void seleccionarArma();
    void atacar();
    void correr()
    {
        std::cout << "El principe corre rápido" << std::endl;
    }

    void displayInstance()
    {
      std::cout<<instance<<std::endl;
    }

    Principe() {instance = this;}
    static Principe* instance;
};

Principe* Principe::instance = 0;

class Princesa : public ClonPersonaje<Princesa>
{
public:
    void gritar();
    void correr()
    {
        std::cout << "La princesa corre medio lento" << std::endl;
    }

    void displayInstance()
    {
      std::cout<<instance<<std::endl;
    }

    Princesa() {instance = this;}
    static Princesa* instance;
};

Princesa* Princesa::instance = 0;

class Villano : public ClonPersonaje<Villano>
{
public:
    void atacar();
    void atraparPricnesa();
    void correr()
    {
        std::cout << "El villano no necesita correr" << std::endl;
    }

    void displayInstance()
    {
      std::cout<<instance<<std::endl;
    }

    Villano() {instance = this;}
    static Villano* instance;
};

Villano* Villano::instance = 0;

class VillanoVolador : public ClonPersonaje<VillanoVolador>
{
public:
    void correr()
    {
        std::cout << "También puede volar" << std::endl;
    }

    void displayInstance()
    {
      std::cout<<instance<<std::endl;
    }

    VillanoVolador() {instance = this;}
    static VillanoVolador* instance;
};

VillanoVolador* VillanoVolador::instance = 0;

int main()
{
		Personaje* pe = Personaje::factoryMethod<Villano>();
    Personaje* pe2 = Personaje::factoryMethod<Villano>();
		Personaje* pr = Personaje::factoryMethod<Princesa>();
    Personaje* prin = Personaje::factoryMethod<Principe>();
    Personaje* pv = Personaje::factoryMethod<VillanoVolador>();

    pe->correr();
    pe2->correr();
		pr->correr();
    prin->correr();
    pv->correr();

    return 0;
}
