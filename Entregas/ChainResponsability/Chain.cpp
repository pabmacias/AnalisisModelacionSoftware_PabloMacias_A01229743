#include <iostream>
#include <string>
#include <sstream>

class Server
{
private:
  Server* next = nullptr;

public:
  Server() { next = 0; }
  void setNext(Server* new_Server) { next = new_Server; }

  void addServer(Server* new_Server)
  {
    if (next != nullptr)
      next->addServer(new_Server);
    else
      setNext(new_Server);
  }

  virtual void handle(std::string ip)
  {
    if (next != nullptr)
      next->handle(ip);
    else
      std::cout<<"No se encontro"<<std::endl;
  }
};

class Server1 : public Server
{
private:
  std::string ips[2] = {"192.168.1.1", "192.168.1.2"};

public:
  void handle(std::string ip)
  {
    bool found = false;
    for (int i=0; i<2; i++)
    {
      if (ips[i] == ip)
        found = true;
    }

    if (found == true)
      std::cout<<"Encontrado en el servidor 1"<<std::endl;
    else
      Server::handle(ip);
  }
};

class Server2 : public Server
{
private:
  std::string ips[2] = {"192.168.2.1", "192.168.2.2"};

public:
  void handle(std::string ip)
  {
    bool found = false;
    for (int i=0; i<2; i++)
    {
      if (ips[i] == ip)
        found = true;
    }

    if (found == true)
      std::cout<<"Encontrado en el servidor 2"<<std::endl;
    else
      Server::handle(ip);
  }
};

class Server3 : public Server
{
private:
  std::string ips[2] = {"192.168.3.1", "192.168.3.2"};

public:
  void handle(std::string ip)
  {
    bool found = false;
    for (int i=0; i<2; i++)
    {
      if (ips[i] == ip)
        found = true;
    }

    if (found == true)
      std::cout<<"Encontrado en el servidor 3"<<std::endl;
    else
      Server::handle(ip);
  }
};

class Server4 : public Server
{
private:
  std::string ips[2] = {"192.168.4.1", "192.168.4.2"};

public:
  void handle(std::string ip)
  {
    bool found = false;
    for (int i=0; i<2; i++)
    {
      if (ips[i] == ip)
        found = true;
    }

    if (found == true)
      std::cout<<"Encontrado en el servidor 4"<<std::endl;
    else
      Server::handle(ip);
  }
};

class Server5 : public Server
{
private:
  std::string ips[2] = {"192.168.5.1", "192.168.5.2"};

public:
  void handle(std::string ip)
  {
    bool found = false;
    for (int i=0; i<2; i++)
    {
      if (ips[i] == ip)
        found = true;
    }

    if (found == true)
      std::cout<<"Encontrado en el servidor 5"<<std::endl;
    else
      Server::handle(ip);
  }
};

int main()
{
  Server s;

  Server1 s1;
  Server2 s2;
  Server3 s3;
  Server4 s4;
  Server5 s5;

  s.addServer(&s1);
  s.addServer(&s2);
  s.addServer(&s3);
  s.addServer(&s4);
  s.addServer(&s5);

  for (int i=1; i<3; i++)
  {
    for (int j=1; j<7; j++)
    {
      std::stringstream sstm;
      sstm <<"192.168."<<j<<"."<<i;
      std::string ip = sstm.str();
      std::cout<<"IP: "<<ip<<std::endl;
      s1.handle(ip);
    }
  }
}
