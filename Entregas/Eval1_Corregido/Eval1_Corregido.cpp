#include<iostream>
#include<string>

class Videojuego
{
private:
  int niveles;
  int precio;
  std::string nombre;
  int numSerie;
  Videojuego * next = nullptr;

public:
  Videojuego() {};
  virtual void concepcion() = 0;
  virtual void diseno() = 0;
  virtual void planificacion() = 0;
  virtual void produccion() = 0;
  virtual void pruebas() = 0;
  virtual Videojuego* clonar() = 0;

  void setNext(Videojuego * _next)
  {
    next = _next;
  }

  Videojuego * getNext()
  {
    return next;
  }

  void setNumSerie(int _numSerie)
  {
    numSerie = _numSerie;
  }

  int getNumSerie()
  {
    return numSerie;
  }

  void setPrecio(int _precio)
  {
    precio = _precio;
  }

  int getPrecio()
  {
    return precio;
  }

  void setNombre(std::string _nombre)
  {
    nombre = _nombre;
  }

  std::string getNombre()
  {
    return nombre;
  }

  template<class SubClase>
  static Videojuego* factoryMethod()
  {
    SubClase s;
    Videojuego* v = s.clonar();
    v->concepcion();
    v->diseno();
    v->planificacion();
    v->produccion();
    v->pruebas();
    return v;
  }
};

template <class SubClase>
class ClonVideojuego : public Videojuego
{
public:
    virtual Videojuego* clonar()
    {
         return new SubClase(dynamic_cast<SubClase&>(*this));
    }
};

class Estrategia : public ClonVideojuego<Estrategia>
{
private:
  std::string dificultad;
public:
  void concepcion() { std::cout<<"Concepcion del juego"<<std::endl; }
  void diseno() { std::cout<<"Disenando el juego"<<std::endl; }
  void planificacion() { std::cout<<"Planificacion del juego"<<std::endl; }
  void produccion() { std::cout<<"Produciendo el juego"<<std::endl; }
  void pruebas() { std::cout<<"Realizando pruebas"<<std::endl; }
};

class Aventura : public ClonVideojuego<Aventura>
{
private:
  std::string personaje;
public:
  void concepcion() { std::cout<<"Concepcion del juego"<<std::endl; }
  void diseno() { std::cout<<"Disenando el juego"<<std::endl; }
  void planificacion() { std::cout<<"Planificacion del juego"<<std::endl; }
  void produccion() { std::cout<<"Produciendo el juego"<<std::endl; }
  void pruebas() { std::cout<<"Realizando pruebas"<<std::endl; }
};

class Aprendizaje : public ClonVideojuego<Aprendizaje>
{
private:
  std::string materia;
public:
  void concepcion() { std::cout<<"Concepcion del juego"<<std::endl; }
  void diseno() { std::cout<<"Disenando el juego"<<std::endl; }
  void planificacion() { std::cout<<"Planificacion del juego"<<std::endl; }
  void produccion() { std::cout<<"Produciendo el juego"<<std::endl; }
  void pruebas() { std::cout<<"Realizando pruebas"<<std::endl; }
};

class Almacen
{
protected:
  Videojuego * head = nullptr;
  int length = 0;
  //int i = 0;
public:
	//Almacen() { instance = this; head = nullptr; length = 0;}
  //static Almacen* instance;

  Almacen() {}
  Almacen (Videojuego * new_node) { head = new_node; length++; }

  int getLength() { return length; }
  //void setLength(int _length) { length = _length; std::cout<<length<<std::endl; }

  /*static Almacen* getInstance()
  {
      if(instance != 0)
      {
          return instance;
      }
      else
      {
          Almacen();
          return instance;
      }
  }*/

  void push(Videojuego * new_node)
  {
    if (head == nullptr)
    {
      //std::cout<<"mal"<<std::endl;
        head = new_node;
    }
    else
    {
        new_node->setNext(head);
        head = new_node;
    }

    length++;
  }

  void eliminar(int num)
  {
    Videojuego * item = head;

    while (true)
    {
      if (item->getNext()->getNumSerie() == num)
      {
        Videojuego * temp = item->getNext();
        item->setNext(temp->getNext());
        temp->setNext(nullptr);
        length--;
        return;
      }

      if (item->getNext() != nullptr)
        item = item->getNext();
      else
        break;
    }

    std::cout<<std::endl<<"No se encontro el videojuego con numero de serie: "<<num<<std::endl<<std::endl;

  }

  void buscar(int num)
  {
    Videojuego * item = head;
    std::cout<<std::endl;

    while (true)
    {
      if (item->getNumSerie() == num)
      {
        std::cout<<item->getNombre()<<" ("<<item->getNumSerie()<<")"<<std::endl<<std::endl;
        return;
      }

      if (item->getNext() != nullptr)
        item = item->getNext();
      else
        break;
    }

    std::cout<<"No se encontro el videojuego con numero de serie: "<<num<<std::endl<<std::endl;
  }

  /*void ordenar()
  {
    int n = length;
    bool swapped = false;

    Videojuego * item = head;

    do
    {
      swapped = false;
      item = head;
      for (int i=1; i<n; i++)
      {
        std::cout<<item->getPrecio()<<" > "<<item->getNext()->getPrecio()<<std::endl;
        if (item->getPrecio() > item->getNext()->getPrecio())
        {
          swap(item, item->getNext());
          swapped = true;
        }
        if (item->getNext() != nullptr)
          item = item->getNext();
        else
          break;
      }
    } while (swapped == true);
  }

  void swap(Videojuego * a, Videojuego * b)
  {
    Videojuego * item = head;
    Videojuego * ba = nullptr;
    Videojuego * bb = nullptr;
    bool fa = false;
    bool fb = false;

    while (fa == false || fb == false)
    {
      if (item->getNext()->getNumSerie() == a->getNumSerie())
      {
        ba = item;
        fa = true;
      }
      if (item->getNext()->getNumSerie() == b->getNumSerie())
      {
        bb = item;
        fb = true;
      }

      if (item->getNext() != nullptr)
        item = item->getNext();
      else
        break;
    }

    std::cout<<"swap"<<std::endl;

    Videojuego * temp = b;
    ba->setNext(b);
    b->setNext(a->getNext());
    bb->setNext(a);
    a->setNext(temp->getNext());
  } */

  void imprimir()
  {
    Videojuego * item = head;
    std::cout<<std::endl;
    for (int i=0; i<length; i++)
    {
      std::cout<<item->getNombre()<<" ("<<item->getPrecio()<<")"<<std::endl;

      if (item->getNext() != nullptr)
        item = item->getNext();
      else
        break;
    }
    std::cout<<std::endl;
  }
};

//Almacen* Almacen::instance = 0;

int main()
{
  Almacen a;
  int num = 0;
  int serie = 0;

  //Almacen* a = Almacen::getInstance();
  //a->setLength(10);
  Videojuego * v = nullptr;

  while (true)
  {
    //std::cout<<"c: Crear inventario"<<std::endl;
    std::cout<<"a: Agregar videojuego"<<std::endl;
    std::cout<<"e: Eliminar videojuego"<<std::endl;
    std::cout<<"b: Buscar videojuego"<<std::endl;
    //std::cout<<"o: Ordenar por precio"<<std::endl;
    std::cout<<"i: Imprimir inventario"<<std::endl;
    std::cout<<"t: Total de videojuegos en el inventario"<<std::endl;
    std::cout<<"Elige la opcion que deseas: ";
    char op;
    std::cin>>op;

    switch(op)
    {
      /*case 'c':
        int size;
        std::cout<<"Escribe el tamano del inventario: ";
        std::cin>>size;
        break;*/
      /*case 'o':
        a.ordenar();
        a.imprimir();
        break;*/
      case 't':
        std::cout<<std::endl<<"En total se cuentan con "<<a.getLength()<<" videojuegos"<<std::endl<<std::endl;
        break;
      case 'e':
        std::cout<<"Escribe el numero de serie del videojuego que quieres eliminar: ";
        std::cin>>serie;
        a.eliminar(serie);
        break;
      case 'b':
        std::cout<<"Escribe el numero de serie del videojuego que quieres buscar: ";
        std::cin>>serie;
        a.buscar(serie);
        break;
      case 'a':
        std::cout<<"e: Estrategia"<<std::endl;
        std::cout<<"v: Aventura"<<std::endl;
        std::cout<<"p: Aprendizaje"<<std::endl;
        std::cout<<"Elige el tipo de videojuego:";
        char tipo;
        std::cin>>tipo;

        switch(tipo)
        {
          case 'e':
            v = Videojuego::factoryMethod<Estrategia>();
            v->setNombre("Estrategia");
            v->setNumSerie(num);
            v->setPrecio(10);
            num++;
            //std::cout<<v->getNombre()<<std::endl;
            a.push(v);
            break;
          case 'v':
            v = Videojuego::factoryMethod<Aventura>();
            v->setNombre("Aventura");
            v->setNumSerie(num);
            v->setPrecio(30);
            num++;
            //std::cout<<v->getNombre()<<std::endl;
            a.push(v);
            break;
          case 'p':
            v = Videojuego::factoryMethod<Aprendizaje>();
            v->setNombre("Aprendizaje");
            v->setNumSerie(num);
            v->setPrecio(20);
            num++;
            a.push(v);
            break;
          default:
            std::cout<<"Tipo invalido"<<std::endl;
        }
         break;
      case 'i':
        a.imprimir();
        break;
      default :
        std::cout<<"Opcion invalida"<<std::endl;
        break;
    }
  }
}
