#include<iostream>
#include<string>

class Videojuego
{
protected:
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

  void setNext(Videojuego* next_node)
  {
  	this->next = next_node;
  }

  Videojuego * getNext()
  {
    std::cout<<this<<std::endl;

  	return this->next;
  }

  int getNumSerie()
  {
    return this->numSerie;
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

/*class Inventario
{
public:
  Inventario() { instance = this; }
  static Inventario* instance;

  static Inventario* getInstance()
  {
      if(instance != 0)
      {
          return instance;
      }
      else
      {
          Inventario();
          return instance;
      }
  }

  void crear()
  {

  }
};

Inventario* Inventario::instance = 0;*/

class Almacen
{
protected:
  Videojuego * head = nullptr;
  int length = 0;
  int i = 0;
public:
	Almacen() { instance = this; head = nullptr; }
  static Almacen* instance;

	//Almacen(int size) { length = size; head = nullptr; }

  int getLength() { return this->length; }

  static Almacen* getInstance()
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
  }

  void creaInventario(int size)
  {
    Almacen* al = Almacen::getInstance();
    al->length = size;
    //Inventario* inv = Inventario::getInstance();
    //inv->crear(size);
  }

  void agregar(Videojuego * item)
  {
    item->setNext(nullptr);

    if (this->head == nullptr)
  	{
  		this->head = item;
  	}

    else
  	{
  		Videojuego * listItem = this->head;

      std::cout<<listItem->getNext()<<std::endl;

  		while (listItem->getNext() != nullptr)
  		{
  			listItem = listItem->getNext();
  		}

  		listItem->setNext(item);
  	}

    /*Videojuego* v;
    if (tipo == 1)
      v = Videojuego::factoryMethod<Estrategia>();
    else if (tipo == 2)
      v = Videojuego::factoryMethod<Aventura>();
    else if (tipo == 3)
      v = Videojuego::factoryMethod<Aprendizaje>();

    inv[i] = v;
    i++;*/
  }

  /*void eliminar(Videojuego item)
  {
    Videojuego * list_item = this->head;
  	int index = 0;

  	if (list_item == nullptr)
  		return;

  	while (list_item->getNumSerie() != item.getNumSerie())
  	{
  		list_item = list_item->getNext();
  		index++;
  	}
  	if (index < getLength())
  		removeItemAt(index);
  }

  Videojuego * removeItemAt(int position)
  {
  	int index = 1;
  	Videojuego * previous = this->head;
  	Videojuego * item;

  	if (position > this->length || position < 0)
  	{
  		return nullptr;
  	}

  	if (position == 0)
  	{
  		item = previous;
  		this->head = item->getNext();
  	}
  	else
  	{
  		item = previous->getNext();
  		while (index < position)
  		{
  			previous = item;
  			item = item->getNext();
  			index++;
  		}
  		previous->setNext(item->getNext());
  	}
  	item->setNext(nullptr);

  	return item;
  }*/

  void reHacer();
  void ordenar();
  void buscar(int n);
  void numero();
  void imprimir();
};

Almacen* Almacen::instance = 0;

int main()
{
  Almacen * a;
  Videojuego * item = nullptr;
  Videojuego * v;

  while (true)
  {
    std::cout<<"c: Crear inventario"<<std::endl;
    std::cout<<"a: Agregar videojuego"<<std::endl;
    std::cout<<"Elige la opcion que deseas: ";
    char op;
    std::cin>>op;

    switch(op)
    {
      case 'c':
        int size;
        std::cout<<"Escribe el tamano del inventario: ";
        std::cin>>size;
        a->creaInventario(size);
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
            a->agregar(v);
            break;
          case 'v':
            v = Videojuego::factoryMethod<Aventura>();
            a->agregar(v);
            break;
          case 'p':
            v = Videojuego::factoryMethod<Aprendizaje>();
            a->agregar(v);
            break;
          default:
            std::cout<<"Tipo invalido"<<std::endl;
        }
         break;
      default :
        std::cout<<"Opcion invalida"<<std::endl;
    }
  }
}
