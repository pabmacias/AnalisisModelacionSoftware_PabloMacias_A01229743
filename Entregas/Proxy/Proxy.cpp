#include<iostream>

using namespace std;

class ArrayNatPerfect;

class Proxy
{
    ArrayNatPerfect& arr;
    int idx;
public:
    Proxy(ArrayNatPerfect& arr, int idx) : arr(arr), idx(idx){}
    Proxy& operator = (int value);
    friend ostream& operator<<(ostream&, Proxy&&);
};

class ArrayNatPerfect
{
private:
    int * arr;
    int size;

public:
    friend class Proxy;
    ArrayNatPerfect(int size) : size(size)
    {
        arr = new int[size+1]; //EL MAS 1 ES PARA REDIRIGIR ERRORES
    }
    Proxy operator[](int index)
    {
        if(index < 0)
        {
            cout << "Error: No hay índices negativos" << endl;
            return Proxy(*this, size);
        }

        if(index >= size)
        {
            cout << "Error: No hay índices mayores a " << index-1 << endl;
            return Proxy(*this, size);
        }

        return Proxy(*this, index);
    }
    friend ostream& operator<<(ostream& os, Proxy&& p);
};

Proxy& Proxy::operator = (int value)
{
  int tempArray[value] = {0};
  int temp=0;
  int j=0;

  for (int i=1; i<value; i++)
  {
    if (value%i == 0)
    {
      tempArray[j]=i;
      j++;
    }
  }

  for (int i=0; i<j; i++)
  {
    temp += tempArray[i];
  }

  if(temp == value) //natural perfecto
  {
      arr.arr[idx] = value;
  }
  else
  {
      cout << "Eror: No es natural perfecto" << endl;
  }

  return *this;
}

ostream& operator<<(ostream& os, Proxy&& p)
{
    os << p.arr.arr[p.idx];
    return os;
}

int main()
{
    ArrayNatPerfect a(5);
    a[0]=6;
    a[1]=5;
    a[5]= 2;
    a[-1] = 6;
    cout << a[0]<<endl;
}
