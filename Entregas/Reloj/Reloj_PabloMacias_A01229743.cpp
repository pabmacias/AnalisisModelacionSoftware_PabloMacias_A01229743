#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <ctime>

class Reloj
{
	private:
		time_t hora = time(0);

	public:
		Reloj();
		time_t getHora();

};

Reloj::Reloj()
{
	hora = 0;
}

time_t Reloj::getHora()
{
	return time(&hora);
}

int main()
{
	Reloj *r1 = new Reloj();

	std::cout << r1->getHora();
	
	int a;
	std::cin >> a;
}