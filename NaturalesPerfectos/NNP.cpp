#include<iostream>
using namespace std;

class NNP
{
public:
	int* ArregloNNP;

	NNP(int n)
	{
		ArregloNNP = new int[n];

		calcNNP(ArregloNNP, n);
	}

	int calcNNP(int ArregloNNP[], int n)
	{

	}
};

NNP& operator +(NNP &other)
{
	return 1;
}

int main()
{
	int n = 5;
	NNP a(n);

	a.ArregloNNP[0] = 6;

}