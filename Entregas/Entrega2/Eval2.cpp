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
  Laser() { type = "Laser"; instance = this; }
  static Laser* instance;
  void accept(Visitor*);

  static Laser* getInstance()
  {
      if(instance == 0)
      {
          return new Laser;
      }
      else
          return instance;
  }
};
Laser* Laser::instance = 0;

class Inyection : public Printer
{
public:
  Inyection() { type = "Inyection"; instance = this; }
  static Inyection* instance;
  void accept(Visitor*);

  static Inyection* getInstance()
  {
      if(instance == 0)
      {
          return new Inyection;
      }
      else
          return instance;
  }
};
Inyection* Inyection::instance = 0;

class PDF : public Printer
{
public:
  PDF() { type = "PDF"; instance = this; }
  static PDF* instance;
  void accept(Visitor*);

  static PDF* getInstance()
  {
      if(instance == 0)
      {
          return new PDF;
      }
      else
          return instance;
  }
};
PDF* PDF::instance = 0;

class Postscript : public Printer
{
public:
  Postscript() { type = "Postscript"; instance = this; }
  static Postscript* instance;
  void accept(Visitor*);

  static Postscript* getInstance()
  {
      if(instance == 0)
      {
          return new Postscript;
      }
      else
          return instance;
  }
};
Postscript* Postscript::instance = 0;

class Portable : public Printer
{
public:
  Portable() { type = "Portable"; instance = this; }
  static Portable* instance;
  void accept(Visitor*);

  static Portable* getInstance()
  {
      if(instance == 0)
      {
          return new Portable;
      }
      else
          return instance;
  }
};
Portable* Portable::instance = 0;

class SimpleText : public Documents
{
public:
  SimpleText() { type = "Simple Text"; instance = this; }
  static SimpleText* instance;
  void accept(Visitor*);

  static SimpleText* getInstance()
  {
      if(instance == 0)
      {
          return new SimpleText;
      }
      else
          return instance;
  }
};
SimpleText* SimpleText::instance = 0;

class FormatedText : public Documents
{
public:
  FormatedText() { type = "Formated Text"; instance = this; }
  static FormatedText* instance;
  void accept(Visitor*);

  static FormatedText* getInstance()
  {
      if(instance == 0)
      {
          return new FormatedText;
      }
      else
          return instance;
  }
};
FormatedText* FormatedText::instance = 0;

class Images : public Documents
{
public:
  Images() { type = "Image"; instance = this; }
  static Images* instance;
  void accept(Visitor*);

  static Images* getInstance()
  {
      if(instance == 0)
      {
          return new Images;
      }
      else
          return instance;
  }
};
Images* Images::instance = 0;

class Cards : public Documents
{
public:
  Cards() { type = "Cards"; instance = this; }
  static Cards* instance;
  void accept(Visitor*);

  static Cards* getInstance()
  {
      if(instance == 0)
      {
          return new Cards;
      }
      else
          return instance;
  }
};
Cards* Cards::instance = 0;

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
