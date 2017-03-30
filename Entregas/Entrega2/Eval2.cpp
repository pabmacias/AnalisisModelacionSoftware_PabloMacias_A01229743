#include <iostream>

class Visitor;

class Printer
{
protected:
  std::string type;

public:
  static int countPrinters;
  std::string getType() { return type; }
  virtual void accept(Visitor*) = 0;
};
int Printer::countPrinters = 0;

class Documents
{
protected:
  std::string type;

public:
  static int countDocs;
  std::string getType() { return type; }
  virtual void accept(Visitor*) = 0;
  void printOn(Printer*);
};
int Documents::countDocs = 0;

class Laser : public Printer
{
public:
  Laser() { type = "Laser"; }
  void accept(Visitor*);
};

class Inyection : public Printer
{
public:
  Inyection() { type = "Inyection"; }
  void accept(Visitor*);
};

class PDF : public Printer
{
public:
  PDF() { type = "PDF"; }
  void accept(Visitor*);
};

class Postscript : public Printer
{
public:
  Postscript() { type = "Postscript"; }
  void accept(Visitor*);
};

class Portable : public Printer
{
public:
  Portable() { type = "Portable"; }
  void accept(Visitor*);
};

class SimpleText : public Documents
{
public:
  SimpleText() { type = "Simple Text"; }
  void accept(Visitor*);
};

class FormatedText : public Documents
{
public:
  FormatedText() { type = "Formated Text"; }
  void accept(Visitor*);
};

class Images : public Documents
{
public:
  Images() { type = "Image"; }
  void accept(Visitor*);
};

class Cards : public Documents
{
public:
  Cards() { type = "Cards"; }
  void accept(Visitor*);
};

class Visitor
{
public:
  virtual void visit(Printer*) = 0;
  virtual void visit(Documents*) = 0;
};

class PresentVisitor : public Visitor
{
    PresentVisitor()
    {
        instance = this;
    }
    static PresentVisitor* instance;
public:
    static PresentVisitor* getInstance()
    {
        if(instance == 0)
        {
            return new PresentVisitor;
        }
        else
            return instance;
    }

    void visit(Printer* p)
    {
      std::cout<<p->getType();
    }
    void visit(Documents* d)
    {
      std::cout<<d->getType();
    }
};
PresentVisitor* PresentVisitor::instance = 0;

class CountVisitor : public Visitor
{
public:
  void visit(Printer* p)
  {
    std::cout<<Printer::countPrinters;
  }
  void visit(Documents* d)
  {
    std::cout<<Documents::countDocs;
  }
};

class AddVisitor : public Visitor
{
public:
    void visit(Printer*)
    {
        Printer::countPrinters++;
    }
    void visit(Documents*)
    {
        Documents::countDocs++;
    }
};

void Laser::accept(Visitor* v)
{
  v->visit(this);
}

void Inyection::accept(Visitor* v)
{
  v->visit(this);
}

void PDF::accept(Visitor* v)
{
  v->visit(this);
}

void Postscript::accept(Visitor* v)
{
  v->visit(this);
}

void SimpleText::accept(Visitor* v)
{
  v->visit(this);
}

void FormatedText::accept(Visitor* v)
{
  v->visit(this);
}

void Images::accept(Visitor* v)
{
  v->visit(this);
}

void Cards::accept(Visitor* v)
{
  v->visit(this);
}

void Portable::accept(Visitor* v)
{
  v->visit(this);
}

void Documents::printOn(Printer* p)
{
  std::cout<<type<<" on "<<p->getType()<<std::endl;
}

void printAllDocuments(Documents** d, int countDocs, Printer** p, int countPrinters)
{
  for(int i=0; i<countDocs; i++)
  {
    for(int j=0; j<countPrinters; j++)
    {
      d[i]->printOn(p[j]);
    }
  }
}

int main()
{
  AddVisitor a;
  CountVisitor c;
  PresentVisitor* pv = PresentVisitor::getInstance();

  Printer* p[] ={new Laser, new Inyection, new PDF, new Postscript, new Portable};

  for(int j = 0; j < 5; j++)
  {
    p[j]->accept(&a);
  }


  Documents* d[] ={new SimpleText, new FormatedText, new Images, new Cards};

  for (int j = 0; j < 4; j++)
  {
    d[j]->accept(&a);
  }

  printAllDocuments(d, d[0]->countDocs, p, p[0]->countPrinters);
}
