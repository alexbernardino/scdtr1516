#ifndef SOLID_H
#define SOLID_H
#include <iostream> //need std::cout

class Solid {
private:        //no one should change this
  static int obj_count;  //Initialization must be done outside class declaration
protected: 	//must be used by subclasses
  float _d; 	
public:
  Solid( float d )  : _d {d}  {
      std::cout << "creating solid\n";
      ++obj_count;   //must use in all contructor overloads
  }
  virtual ~Solid()  {
     std::cout << "destroying solid\n";
     --obj_count;
  }
  static int TotalItems()  {
      return obj_count; 
  }
  virtual float CalcMass() const = 0;
  virtual void Print(ostream &) = 0;
  friend ostream& operator<< (ostream&, Solid &);
};
ostream& operator<< (ostream& os, Solid &s)
{
  s.Print(os);
  return os;
}
int Solid::obj_count = 0;  //Initialization of static member variable
#endif // SOLID_H
