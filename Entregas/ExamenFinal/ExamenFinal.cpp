#include <iostream>
#include <string>

class Collisioner;

class Spacecraft
{
protected:
  std::string type;

public:
  static int countSpacecrafts;
  std::string getType() { return type; }
  virtual void accept(Collisioner*) = 0;

  template<class T>
  void spacecraftCollides(T*);

  virtual void operacion1() = 0;
  //virtual void operacion2() = 0;

  template<class T>
  static Spacecraft* factoryMethod()
  {
    T* t = T::getInstance();
    t->operacion1();
    return t;
  }
};
int Spacecraft::countSpacecrafts = 0;

class Asteroid
{
protected:
  std::string type;

public:
  static int countAsteroids;
  std::string getType() { return type; }
  virtual void accept(Collisioner*) = 0;

  template<class T>
  void asteroidCollides(T*);

  virtual void operacion1() = 0;
  //virtual void operacion2() = 0;

  template<class T>
  static Asteroid* factoryMethod()
  {
    T* t = T::getInstance();
    t->operacion1();
    return t;
  }
};
int Asteroid::countAsteroids = 0;

class Planet
{
protected:
  std::string type;

public:
  static int countPlanets;
  std::string getType() { return type; }
  virtual void accept(Collisioner*) = 0;

  template<class T>
  void planetCollides(T*);

  virtual void operacion1() = 0;
  //virtual void operacion2() = 0;

  template<class T>
  static Planet* factoryMethod()
  {
    T* t = T::getInstance();
    t->operacion1();
    return t;
  }
};
int Planet::countPlanets = 0;

class PlanetExplorationShip : public Spacecraft
{
public:
  PlanetExplorationShip() { type = "Planet Exploration Ship"; instance = this; }
  static PlanetExplorationShip* instance;

  static PlanetExplorationShip* getInstance()
  {
      if(instance == 0)
      {
          return new PlanetExplorationShip;
      }
      else
          return instance;
  }

  void accept(Collisioner*);

  void operacion1()
  {
    std::cout<<"Se creo una Planet Exploration Ship"<<std::endl;
  }
};
PlanetExplorationShip* PlanetExplorationShip::instance = 0;

class ColonizationShip : public Spacecraft
{
public:
  ColonizationShip() { type = "Colonization Ship"; instance = this; }
  static ColonizationShip* instance;

  static ColonizationShip* getInstance()
  {
      if(instance == 0)
      {
          return new ColonizationShip;
      }
      else
          return instance;
  }

  void accept(Collisioner*);

  void operacion1()
  {
    std::cout<<"Se creo una Colonization Ship"<<std::endl;
  }
};
ColonizationShip* ColonizationShip::instance = 0;

class PlanetObservationShip : public Spacecraft
{
public:
  PlanetObservationShip() { type = "Planet Observation Ship"; instance = this; }
  static PlanetObservationShip* instance;

  static PlanetObservationShip* getInstance()
  {
      if(instance == 0)
      {
          return new PlanetObservationShip;
      }
      else
          return instance;
  }

  void accept(Collisioner*);

  void operacion1()
  {
    std::cout<<"Se creo una Planet Observation Ship"<<std::endl;
  }
};
PlanetObservationShip* PlanetObservationShip::instance = 0;

class Stony : public Asteroid
{
public:
  Stony() { type = "Stony Asteroid"; instance = this; }
  static Stony* instance;

  static Stony* getInstance()
  {
      if(instance == 0)
      {
          return new Stony;
      }
      else
          return instance;
  }

  void accept(Collisioner*);

  void operacion1()
  {
    std::cout<<"Se creo un Stony Asteroid"<<std::endl;
  }
};
Stony* Stony::instance = 0;

class Iron : public Asteroid
{
public:
  Iron() { type = "Iron Asteroid"; instance = this; }
  static Iron* instance;

  static Iron* getInstance()
  {
      if(instance == 0)
      {
          return new Iron;
      }
      else
          return instance;
  }

  void accept(Collisioner*);

  void operacion1()
  {
    std::cout<<"Se creo un Iron Asteroid"<<std::endl;
  }
};
Iron* Iron::instance = 0;

class Dessert : public Planet
{
public:
  Dessert() { type = "Dessert Planet"; instance = this; }
  static Dessert* instance;

  static Dessert* getInstance()
  {
      if(instance == 0)
      {
          return new Dessert;
      }
      else
          return instance;
  }

  void accept(Collisioner*);

  void operacion1()
  {
    std::cout<<"Se creo un Dessert Planet"<<std::endl;
  }
};
Dessert* Dessert::instance = 0;

class Earth : public Planet
{
public:
  Earth() { type = "Earth Planet"; instance = this; }
  static Earth* instance;

  static Earth* getInstance()
  {
      if(instance == 0)
      {
          return new Earth;
      }
      else
          return instance;
  }

  void accept(Collisioner*);

  void operacion1()
  {
    std::cout<<"Se creo un Earth Planet"<<std::endl;
  }
};
Earth* Earth::instance = 0;

class Collisioner
{
public:
  virtual void collide(Spacecraft*) = 0;
  virtual void collide(Asteroid*) = 0;
  virtual void collide(Planet*) = 0;
};

class PresentCollisioner : public Collisioner
{
private:
  PresentCollisioner()
  {
    instance = this;
  }
  static PresentCollisioner* instance;
public:
  static PresentCollisioner* getInstance()
  {
    if(instance == 0)
    {
      return new PresentCollisioner;
    }
    else
      return instance;
  }

  void collide(Spacecraft* s)
  {
    std::cout<<s->getType();
  }
  void collide(Asteroid* a)
  {
    std::cout<<a->getType();
  }
  void collide(Planet* p)
  {
    std::cout<<p->getType();
  }
};
PresentCollisioner* PresentCollisioner::instance = 0;

class CountCollisioner : public Collisioner
{
public:
  void collide(Spacecraft* s)
  {
    std::cout<<Spacecraft::countSpacecrafts;
  }
  void collide(Asteroid* a)
  {
    std::cout<<Asteroid::countAsteroids;
  }
  void collide(Planet* p)
  {
    std::cout<<Planet::countPlanets;
  }
};

class AddCollisioner : public Collisioner
{
public:
    void collide(Spacecraft*)
    {
        Spacecraft::countSpacecrafts++;
    }
    void collide(Asteroid*)
    {
        Asteroid::countAsteroids++;
    }
    void collide(Planet*)
    {
        Planet::countPlanets++;
    }
};

void PlanetExplorationShip::accept(Collisioner* c)
{
  c->collide(this);
}

void ColonizationShip::accept(Collisioner* c)
{
  c->collide(this);
}

void PlanetObservationShip::accept(Collisioner* c)
{
  c->collide(this);
}

void Stony::accept(Collisioner* c)
{
  c->collide(this);
}

void Iron::accept(Collisioner* c)
{
  c->collide(this);
}

void Dessert::accept(Collisioner* c)
{
  c->collide(this);
}

void Earth::accept(Collisioner* c)
{
  c->collide(this);
}

template<class T>
void Asteroid::asteroidCollides(T* t)
{
  std::cout<<type<<" crashes "<<t->getType()<<std::endl;
}

template<class T>
void collideAsteroids(Asteroid** a, int countAsteroids, T** t, int countT)
{
  for(int i=0; i<countAsteroids; i++)
  {
    for(int j=0; j<countT; j++)
    {
      if (a[i]->getType() != t[j]->getType())
        a[i]->asteroidCollides(t[j]);
    }
  }
}

template<class T>
void Spacecraft::spacecraftCollides(T* t)
{
  std::cout<<type<<" crashes "<<t->getType()<<std::endl;
}

template<class T>
void collideSpacecrafts(Spacecraft** s, int countSpacecrafts, T** t, int countT)
{
  for(int i=0; i<countSpacecrafts; i++)
  {
    for(int j=0; j<countT; j++)
    {
      if (s[i]->getType() != t[j]->getType())
        s[i]->spacecraftCollides(t[j]);
    }
  }
}

template<class T>
void Planet::planetCollides(T* t)
{
  std::cout<<type<<" crashes "<<t->getType()<<std::endl;
}

template<class T>
void collidePlanets(Planet** p, int countPlanets, T** t, int countT)
{
  for(int i=0; i<countPlanets; i++)
  {
    for(int j=0; j<countT; j++)
    {
      if (p[i]->getType() != t[j]->getType())
        p[i]->planetCollides(t[j]);
    }
  }
}

int main()
{
  AddCollisioner a;
  CountCollisioner c;
  PresentCollisioner* pc = PresentCollisioner::getInstance();

  Asteroid* as[] ={Asteroid::factoryMethod<Stony>(),Asteroid::factoryMethod<Iron>()};

  for(int j = 0; j < 2; j++)
  {
    as[j]->accept(&a);
  }

  Spacecraft* s[] ={Spacecraft::factoryMethod<PlanetExplorationShip>(),Spacecraft::factoryMethod<ColonizationShip>(),Spacecraft::factoryMethod<PlanetObservationShip>()};

  for(int j = 0; j < 3; j++)
  {
    s[j]->accept(&a);
  }

  Planet* p[] ={Planet::factoryMethod<Dessert>(),Planet::factoryMethod<Earth>()};

  for(int j = 0; j < 2; j++)
  {
    p[j]->accept(&a);
  }

  std::cout<<std::endl;

  collideAsteroids(as, as[0]->countAsteroids, as, as[0]->countAsteroids);
  collideAsteroids(as, as[0]->countAsteroids, s, s[0]->countSpacecrafts);
  collideAsteroids(as, as[0]->countAsteroids, p, p[0]->countPlanets);
  std::cout<<std::endl;

  collideSpacecrafts(s, s[0]->countSpacecrafts, as, as[0]->countAsteroids);
  collideSpacecrafts(s, s[0]->countSpacecrafts, s, s[0]->countSpacecrafts);
  collideSpacecrafts(s, s[0]->countSpacecrafts, p, p[0]->countPlanets);
  std::cout<<std::endl;

  collidePlanets(p, p[0]->countPlanets, as, as[0]->countAsteroids);
  collidePlanets(p, p[0]->countPlanets, s, s[0]->countSpacecrafts);
  collidePlanets(p, p[0]->countPlanets, p, p[0]->countPlanets);
  std::cout<<std::endl;

}
