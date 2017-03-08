#include<iostream>
#include<string>

class Observer;

class Subject
{
protected:
  Observer listObservers = new Observer[100];
  int i;
public:
  Subject()
  {
    i = 0;
  }

  void registerObserver(Observer _observer)
  {
    listObservers[i] = _observer;
    i++;
  }
};

class Nieto : public Subject
{
public:
  Nieto() { i=0; }

  void notify(std::string news)
  {
    int i=0;

    while (listObservers[i] != nullptr)
    {
      listObservers[i].update(news);
    }
  }
};

class Trump : public Subject
{
public:
  Trump() { i=0; }

  void notify(std::string news)
  {
    int i=0;

    while (listObservers[i] != nullptr)
    {
      listObservers[i].update(news);
    }
  }
};

class Observer
{
protected:
  Subject subject;
  Reforma reforma(subject.nieto, subject.trump);
  Televisa televisa(subject.nieto, subject.trump);
  NBC nbc(subject.nieto, subject.trump);

public:
  /*void update(std::string news)
  {
    reforma.update(news);
    televisa.update(news);
    nbc.update(news);
  }*/
  virtual void update() = 0;
};

class Reforma : public Observer
{
protected:

public:
  Reforma(Nieto _nieto, Trump _trump)
  {
    this.subject.nieto = _nieto;
    this.subject.trump = _trump;
    this.subject.registerObserver(this);
  }

  void update(std::string news)
  {
    std::cout<<"Reforma reporta que "<<news<<std::endl;
  }
};

class Televisa : public Observer
{
protected:

public:
  Televisa(Nieto _nieto, Trump _trump)
  {
    this.subject.nieto = _nieto;
    this.subject.trump = _trump;
    this.subject.registerObserver(this);
  }

  void update(std::string news)
  {
    std::cout<<"Televisa reporta que "<<news<<std::endl;
  }
};

class NBC : public Observer
{
protected:

public:
  NBC(Nieto _nieto, Trump _trump)
  {
    this.subject.nieto = _nieto;
    this.subject.trump = _trump;
    this.subject.registerObserver(this);
  }

  void update(std::string news)
  {
    std::cout<<"NBC reporta que "<<news<<std::endl;
  }
};

int main()
{

}